#pragma once

#include "RCcodeBaseVisitor.h"
#include "rc_exception.h"
#include "rc_helper.h"
#include "rc_innerdata.h"
#include "rc_logger.h"
#include "RCRuntimeModel.h"

#include <stack>


class RCcodeGenerator : public RCcodeBaseVisitor {
public:
    CodeModel &cm;

    RC_SymbolTable &symbolTable;

	RCAddressSpace &addrspace;     // addrspace[0] is the returned value of all the library function  in global
	
	StringPoolSpace &stringpool;
	APDataSpace &apaddr;
	CPDataSpace &cpaddr;
	ToolDataSpace &tooladdr;
	CoorDataSpace &cooraddr;

	std::unordered_map<std::string, int> &dataIndexMap;		// parser xml file and generator dataMap
	std::unordered_map<std::string, int> &constIndexMap;	// the index of all the constants in addr space 

    std::stack<std::vector<RCBaseStatement*>*> compileStack;

public:
	RCcodeGenerator(CodeModel &c, RC_SymbolTable &sym) :
                    cm(c),
                    symbolTable(sym),
					addrspace(sym.addrspace),
					stringpool(sym.stringpool),
					apaddr(sym.apaddr),
					cpaddr(sym.cpaddr),
					tooladdr(sym.tooladdr),
					cooraddr(sym.cooraddr),
					dataIndexMap(sym.dataIndexMap),
					constIndexMap(sym.constIndexMap)
	{}

public:
    virtual antlrcpp::Any visitProgram(RCcodeParser::ProgramContext *ctx) override {
    	LOGGER_INF("Program");
        compileStack.push(&cm);
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitStatBlock(RCcodeParser::StatBlockContext *ctx) override {
        LOGGER_INF("StatBlock");
        antlrcpp::Any result = defaultResult();
        size_t n = ctx->children.size();
        for (size_t i = 0; i < n; i++) {
            if (!shouldVisitNextChild(ctx, result)) {
                break;
            }
            antlrcpp::Any childResult = ctx->children[i]->accept(this);
            result = aggregateResult(result, childResult);
            std::vector<RCBaseStatement*>* cur = compileStack.top();
            RCBaseStatement* tmp = result;
            cur->push_back(tmp);
        }

        return result;
    }

    virtual antlrcpp::Any visitStat(RCcodeParser::StatContext *ctx) override {
        LOGGER_INF("Stat");
        return visitChildren(ctx);
    }

  

    virtual antlrcpp::Any visitMovjExpr(RCcodeParser::MovjExprContext *ctx) override {
    	LOGGER_INF("MovjExpr");
        int line = ctx->MOVJ()->getSymbol()->getLine();
        RCRobotStatement *tempStat = new RCRobotStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCRobotStatement::MOVJ;        // setting the type of robot inst

        int paramSize = ctx->ID().size();
        if(paramSize != 3) {
            throw rc_lackparam_exception(line, 0, "MOVJ");
        }

        std::string strPoint = ctx->ID(0)->getText();
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->endpointIndex = dataIndexMap[strPoint];
            } else {
                int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        std::string strSpeed = ctx->ID(1)->getText();
        int speed = Utility::parseSpeed(strSpeed);
        if(speed != -1) {
            tempStat->speed = speed;
        } else {
            int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
            throw rc_wrongparam_exception(line, col, strSpeed);
        }

        std::string strZX = ctx->ID(2)->getText();
        if(strZX != "Z0" && strZX != "Z1" && strZX != "Z2" && strZX != "Z3" && strZX != "Z4"
             && strZX != "Z5" && strZX != "Z6" && strZX != "Z7" && strZX != "Z8") 
        {
            int col = ctx->ID(2)->getSymbol()->getCharPositionInLine();
            throw rc_wrongparam_exception(line, col, strZX);
        } else {
            if(strZX == "Z0") tempStat->Z = RCRobotStatement::Z0;
            if(strZX == "Z1") tempStat->Z = RCRobotStatement::Z1;
            if(strZX == "Z2") tempStat->Z = RCRobotStatement::Z2;
            if(strZX == "Z3") tempStat->Z = RCRobotStatement::Z3;
            if(strZX == "Z4") tempStat->Z = RCRobotStatement::Z4;
            if(strZX == "Z5") tempStat->Z = RCRobotStatement::Z5;
            if(strZX == "Z6") tempStat->Z = RCRobotStatement::Z6;
            if(strZX == "Z7") tempStat->Z = RCRobotStatement::Z7;
            if(strZX == "Z8") tempStat->Z = RCRobotStatement::Z8;
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitMovlExpr(RCcodeParser::MovlExprContext *ctx) override {
    	LOGGER_INF("MovlExpr");
        int line = ctx->MOVL()->getSymbol()->getLine();
        RCRobotStatement *tempStat = new RCRobotStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCRobotStatement::MOVL;        // setting the type of robot inst

        int paramSize = ctx->ID().size();
        if(paramSize != 3) {
            throw rc_lackparam_exception(line, 0, "MOVL");
        }

        std::string strPoint = ctx->ID(0)->getText();
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->endpointIndex = dataIndexMap[strPoint];
            } else {
                int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        std::string strSpeed = ctx->ID(1)->getText();
        int speed = Utility::parseSpeed(strSpeed);
        if(speed != -1) {
            tempStat->speed = speed;
        } else {
            int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
            throw rc_wrongparam_exception(line, col, strSpeed);
        }

        std::string strZX = ctx->ID(2)->getText();
        if(strZX != "Z0" && strZX != "Z1" && strZX != "Z2" && strZX != "Z3" && strZX != "Z4"
             && strZX != "Z5" && strZX != "Z6" && strZX != "Z7" && strZX != "Z8") 
        {
            int col = ctx->ID(2)->getSymbol()->getCharPositionInLine();
            throw rc_wrongparam_exception(line, col, strZX);
        } else {
            if(strZX == "Z0") tempStat->Z = RCRobotStatement::Z0;
            if(strZX == "Z1") tempStat->Z = RCRobotStatement::Z1;
            if(strZX == "Z2") tempStat->Z = RCRobotStatement::Z2;
            if(strZX == "Z3") tempStat->Z = RCRobotStatement::Z3;
            if(strZX == "Z4") tempStat->Z = RCRobotStatement::Z4;
            if(strZX == "Z5") tempStat->Z = RCRobotStatement::Z5;
            if(strZX == "Z6") tempStat->Z = RCRobotStatement::Z6;
            if(strZX == "Z7") tempStat->Z = RCRobotStatement::Z7;
            if(strZX == "Z8") tempStat->Z = RCRobotStatement::Z8;
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitMovcExpr(RCcodeParser::MovcExprContext *ctx) override {
    	LOGGER_INF("MovcExpr");
        int line = ctx->MOVC()->getSymbol()->getLine();
        RCRobotStatement *tempStat = new RCRobotStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCRobotStatement::MOVC;        // setting the type of robot inst

        int paramSize = ctx->ID().size();
        if(paramSize != 4) {
            throw rc_lackparam_exception(line, 0, "MOVC");
        }

        std::string strPoint = ctx->ID(0)->getText();
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->endpointIndex = dataIndexMap[strPoint];
            } else {
                int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        strPoint = ctx->ID(1)->getText();
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->midpointIndex = dataIndexMap[strPoint];
            } else {
                int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        std::string strSpeed = ctx->ID(2)->getText();
        int speed = Utility::parseSpeed(strSpeed);
        if(speed != -1) {
            tempStat->speed = speed;
        } else {
            int col = ctx->ID(2)->getSymbol()->getCharPositionInLine();
            throw rc_wrongparam_exception(line, col, strSpeed);
        }

        std::string strZX = ctx->ID(3)->getText();
        if(strZX != "Z0" && strZX != "Z1" && strZX != "Z2" && strZX != "Z3" && strZX != "Z4"
             && strZX != "Z5" && strZX != "Z6" && strZX != "Z7" && strZX != "Z8") 
        {
            int col = ctx->ID(3)->getSymbol()->getCharPositionInLine();
            throw rc_wrongparam_exception(line, col, strZX);
        } else {
            if(strZX == "Z0") tempStat->Z = RCRobotStatement::Z0;
            if(strZX == "Z1") tempStat->Z = RCRobotStatement::Z1;
            if(strZX == "Z2") tempStat->Z = RCRobotStatement::Z2;
            if(strZX == "Z3") tempStat->Z = RCRobotStatement::Z3;
            if(strZX == "Z4") tempStat->Z = RCRobotStatement::Z4;
            if(strZX == "Z5") tempStat->Z = RCRobotStatement::Z5;
            if(strZX == "Z6") tempStat->Z = RCRobotStatement::Z6;
            if(strZX == "Z7") tempStat->Z = RCRobotStatement::Z7;
            if(strZX == "Z8") tempStat->Z = RCRobotStatement::Z8;
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitMovsExpr(RCcodeParser::MovsExprContext *ctx) override {
    	LOGGER_INF("MovsExpr");
        int line = ctx->MOVS()->getSymbol()->getLine();
        RCRobotStatement *tempStat = new RCRobotStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCRobotStatement::MOVS;        // setting the type of robot inst

        int paramSize = ctx->ID().size();
        if(paramSize != 4) {
            throw rc_lackparam_exception(line, 0, "MOVS");
        }

        std::string strPoint = ctx->ID(0)->getText();
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->endpointIndex = dataIndexMap[strPoint];
            } else {
                int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        strPoint = ctx->ID(1)->getText();
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->midpointIndex = dataIndexMap[strPoint];
            } else {
                int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        std::string strSpeed = ctx->ID(2)->getText();
        int speed = Utility::parseSpeed(strSpeed);
        if(speed != -1) {
            tempStat->speed = speed;
        } else {
            int col = ctx->ID(2)->getSymbol()->getCharPositionInLine();
            throw rc_wrongparam_exception(line, col, strSpeed);
        }

        std::string strZX = ctx->ID(3)->getText();
        if(strZX != "Z0" && strZX != "Z1" && strZX != "Z2" && strZX != "Z3" && strZX != "Z4"
             && strZX != "Z5" && strZX != "Z6" && strZX != "Z7" && strZX != "Z8") 
        {
            int col = ctx->ID(3)->getSymbol()->getCharPositionInLine();
            throw rc_wrongparam_exception(line, col, strZX);
        } else {
            if(strZX == "Z0") tempStat->Z = RCRobotStatement::Z0;
            if(strZX == "Z1") tempStat->Z = RCRobotStatement::Z1;
            if(strZX == "Z2") tempStat->Z = RCRobotStatement::Z2;
            if(strZX == "Z3") tempStat->Z = RCRobotStatement::Z3;
            if(strZX == "Z4") tempStat->Z = RCRobotStatement::Z4;
            if(strZX == "Z5") tempStat->Z = RCRobotStatement::Z5;
            if(strZX == "Z6") tempStat->Z = RCRobotStatement::Z6;
            if(strZX == "Z7") tempStat->Z = RCRobotStatement::Z7;
            if(strZX == "Z8") tempStat->Z = RCRobotStatement::Z8;
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitShiftonExpr(RCcodeParser::ShiftonExprContext *ctx) override {
    	LOGGER_INF("ShiftonExpr");
        int line = ctx->SHIFTON()->getSymbol()->getLine();
        RCRobotStatement *tempStat = new RCRobotStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCRobotStatement::SHIFTON;        // setting the type of robot inst

        int paramSize = ctx->ID().size();
        if(paramSize != 2) {
            throw rc_lackparam_exception(line, 0, "SHIFTON");
        }

        std::string strPoint = ctx->ID(0)->getText();
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->endpointIndex = dataIndexMap[strPoint];
            } else {
                int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        tempStat->frame = ctx->ID(1)->getText();
        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitShiftoffExpr(RCcodeParser::ShiftoffExprContext *ctx) override {
    	LOGGER_INF("ShiftoffExpr");
        int line = ctx->SHIFTOFF()->getSymbol()->getLine();
        RCRobotStatement *tempStat = new RCRobotStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCRobotStatement::SHIFTOFF;        // setting the type of robot inst

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitSetExpr(RCcodeParser::SetExprContext *ctx) override {
    	LOGGER_INF("SetExpr");
        int line = ctx->SET()->getSymbol()->getLine();
        RCDataStatement *tempStat = new RCDataStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCDataStatement::SET;

        int paramSize = ctx->ID().size();
        if(paramSize != 2) {
            throw rc_lackparam_exception(line, 0, "SET");
        }

        std::string strIndex1 = ctx->ID(0)->getText();
        uint8_t index1Type;
        if(dataIndexMap.find(strIndex1) != dataIndexMap.end()) {
            index1Type = addrspace[dataIndexMap[strIndex1]].type;
            tempStat->index1 = dataIndexMap[strIndex1];
        } else {
            int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strIndex1);
        }

        std::string strIndex2 = ctx->ID(1)->getText();
        uint8_t index2Type;
        if(dataIndexMap.find(strIndex2) != dataIndexMap.end()) {
            index2Type = addrspace[dataIndexMap[strIndex2]].type;
            tempStat->index2 = dataIndexMap[strIndex2];
        } else {
            int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strIndex2);
        }

        if(Utility::checkTypeMatch(index1Type, index2Type) == false) {
            int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
            throw rc_wrongvartype_exception(line, col, strIndex1);
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

  virtual antlrcpp::Any visitSeteExpr(RCcodeParser::SeteExprContext *ctx) override {
  	LOGGER_INF("SeteExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGeteExpr(RCcodeParser::GeteExprContext *ctx) override {
  	LOGGER_INF("GeteExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWaitExpr(RCcodeParser::WaitExprContext *ctx) override {
  	LOGGER_INF("WaitExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDelayExpr(RCcodeParser::DelayExprContext *ctx) override {
  	LOGGER_INF("DelayExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetoutExpr(RCcodeParser::SetoutExprContext *ctx) override {
  	LOGGER_INF("SetoutExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDinExpr(RCcodeParser::DinExprContext *ctx) override {
  	LOGGER_INF("DinExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIncExpr(RCcodeParser::IncExprContext *ctx) override {
  	LOGGER_INF("IncExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecExpr(RCcodeParser::DecExprContext *ctx) override {
  	LOGGER_INF("DecExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncExpr(RCcodeParser::FuncExprContext *ctx) override {
  	LOGGER_INF("FuncExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallExpr(RCcodeParser::CallExprContext *ctx) override {
  	LOGGER_INF("CallExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignExpr1(RCcodeParser::AssignExpr1Context *ctx) override {
  	LOGGER_INF("AssignExpr1");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignExpr2(RCcodeParser::AssignExpr2Context *ctx) override {
  	LOGGER_INF("AssignExpr2");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignExpr3(RCcodeParser::AssignExpr3Context *ctx) override {
  	LOGGER_INF("AssignExpr3");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignExpr4(RCcodeParser::AssignExpr4Context *ctx) override {
  	LOGGER_INF("AssignExpr4");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignExpr5(RCcodeParser::AssignExpr5Context *ctx) override {
  	LOGGER_INF("AssignExpr5");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGotoExpr(RCcodeParser::GotoExprContext *ctx) override {
  	LOGGER_INF("GotoExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpr1(RCcodeParser::IfExpr1Context *ctx) override {
  	LOGGER_INF("IfExpr1");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpr2(RCcodeParser::IfExpr2Context *ctx) override {
  	LOGGER_INF("IfExpr2");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfExpr3(RCcodeParser::IfExpr3Context *ctx) override {
  	LOGGER_INF("IfExpr3");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElseifExpr1(RCcodeParser::ElseifExpr1Context *ctx) override {
  	LOGGER_INF("ElseifExpr1");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElseifExpr2(RCcodeParser::ElseifExpr2Context *ctx) override {
  	LOGGER_INF("ElseifExpr2");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElseifExpr3(RCcodeParser::ElseifExpr3Context *ctx) override {
  	LOGGER_INF("ElseifExpr3");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElseExpr(RCcodeParser::ElseExprContext *ctx) override {
  	LOGGER_INF("ElseExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForExpr(RCcodeParser::ForExprContext *ctx) override {
  	LOGGER_INF("ForExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileExpr1(RCcodeParser::WhileExpr1Context *ctx) override {
  	LOGGER_INF("WhileExpr1");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileExpr2(RCcodeParser::WhileExpr2Context *ctx) override {
  	LOGGER_INF("WhileExpr2");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileExpr3(RCcodeParser::WhileExpr3Context *ctx) override {
  	LOGGER_INF("WhileExpr3");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrueExpr(RCcodeParser::TrueExprContext *ctx) override {
  	LOGGER_INF("TrueExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFalseExpr(RCcodeParser::FalseExprContext *ctx) override {
  	LOGGER_INF("FalseExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibcallExpr(RCcodeParser::LibcallExprContext *ctx) override {
  	LOGGER_INF("LibcallExpr");
    return visitChildren(ctx);
  }

   virtual antlrcpp::Any visitFuncallExpr(RCcodeParser::FuncallExprContext *ctx) override {
   	LOGGER_INF("FuncallExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParamlist(RCcodeParser::ParamlistContext *ctx) override {
  	LOGGER_INF("Paramlist");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumExpr(RCcodeParser::NumExprContext *ctx) override {
  	LOGGER_INF("NumExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExpr(RCcodeParser::IdExprContext *ctx) override {
  	LOGGER_INF("IdExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOneinstExpr(RCcodeParser::OneinstExprContext *ctx) override {
  	LOGGER_INF("OneinstExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLabelExpr(RCcodeParser::LabelExprContext *ctx) override {
  	LOGGER_INF("LabelExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRetExpr(RCcodeParser::RetExprContext *ctx) override {
  	LOGGER_INF("RetExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNopExpr(RCcodeParser::NopExprContext *ctx) override {
  	LOGGER_INF("NopExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPauseExpr(RCcodeParser::PauseExprContext *ctx) override {
  	LOGGER_INF("PauseExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHaltExpr(RCcodeParser::HaltExprContext *ctx) override {
  	LOGGER_INF("HaltExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreakExpr(RCcodeParser::BreakExprContext *ctx) override {
  	LOGGER_INF("BreakExpr");
    return visitChildren(ctx);
  }
};