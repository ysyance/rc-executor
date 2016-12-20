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
        int line = ctx->SETE()->getSymbol()->getLine();
        RCDataStatement *tempStat = new RCDataStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCDataStatement::SETE;

        std::string strElem = ctx->ELEM()->getText();
        std::pair<std::string, std::string> pairElem;
        Utility::parseElem(strElem, pairElem);

        std::string strPoint = pairElem.first;
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->elem.first = dataIndexMap[strPoint];
            } else {
                int col = ctx->ELEM()->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ELEM()->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        try{
            tempStat->elem.second = std::stoi(pairElem.second);
        } catch(std::exception &e) {
            int col = ctx->ELEM()->getSymbol()->getCharPositionInLine();
            throw rc_numformat_exception(line, col+4, strPoint + "(" + pairElem.second + ")");
        }

        std::string strIndex2 = ctx->ID()->getText();
        uint8_t index2Type;
        if(dataIndexMap.find(strIndex2) != dataIndexMap.end()) {
            index2Type = addrspace[dataIndexMap[strIndex2]].type;
            tempStat->index2 = dataIndexMap[strIndex2];
        } else {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strIndex2);
        }

        if(index2Type != TINT && index2Type != TDOUBLE) {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_wrongvartype_exception(line, col, strIndex2);
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitGeteExpr(RCcodeParser::GeteExprContext *ctx) override {
    	LOGGER_INF("GeteExpr");
        int line = ctx->GETE()->getSymbol()->getLine();
        RCDataStatement *tempStat = new RCDataStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCDataStatement::GETE;

        std::string strIndex1 = ctx->ID()->getText();
        uint8_t index1Type;
        if(dataIndexMap.find(strIndex1) != dataIndexMap.end()) {
            index1Type = addrspace[dataIndexMap[strIndex1]].type;
            tempStat->index1 = dataIndexMap[strIndex1];
        } else {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strIndex1);
        }

        if(index1Type != TINT && index1Type != TDOUBLE) {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_wrongvartype_exception(line, col, strIndex1);
        }

        std::string strElem = ctx->ELEM()->getText();
        std::pair<std::string, std::string> pairElem;
        Utility::parseElem(strElem, pairElem);

        std::string strPoint = pairElem.first;
        if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strPoint]].type;
            if(t == TJTPOSE || t == TTRPOSE) {
                tempStat->elem.first = dataIndexMap[strPoint];
            } else {
                int col = ctx->ELEM()->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strPoint);
            }
        } else {
            int col = ctx->ELEM()->getSymbol()->getCharPositionInLine();
            throw rc_pointnotdefined_exception(line, col, strPoint);
        }

        try{
            tempStat->elem.second = std::stoi(pairElem.second);
        } catch(std::exception &e) {
            int col = ctx->ELEM()->getSymbol()->getCharPositionInLine();
            throw rc_numformat_exception(line, col+4, strPoint + "(" + pairElem.second + ")");
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitWaitExpr(RCcodeParser::WaitExprContext *ctx) override {
    	LOGGER_INF("WaitExpr");
        // WAIT ID op=(EQ|GE|LE|LT|GT|NE) numorid (',' TIME)? ';'
        int line = ctx->WAIT()->getSymbol()->getLine();
        RCSignalStatement *tempStat = new RCSignalStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSignalStatement::WAIT;

        std::string strVar = ctx->ID()->getText();
        if(dataIndexMap.find(strVar) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strVar]].type;
            if(Utility::checkNum(t)) {
                tempStat->index1 = dataIndexMap[strVar];
            } else {
                int col = ctx->ID()->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strVar);
            }
        } else {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strVar);
        }

        if(ctx->op->getType() == RCcodeParser::EQ) tempStat->op = RCSignalStatement::EQ;
        if(ctx->op->getType() == RCcodeParser::GE) tempStat->op = RCSignalStatement::GE;
        if(ctx->op->getType() == RCcodeParser::GT) tempStat->op = RCSignalStatement::GT;
        if(ctx->op->getType() == RCcodeParser::LE) tempStat->op = RCSignalStatement::LE;
        if(ctx->op->getType() == RCcodeParser::LT) tempStat->op = RCSignalStatement::LT;
        if(ctx->op->getType() == RCcodeParser::NE) tempStat->op = RCSignalStatement::NE;

        int index2 = visit(ctx->numorid()) ;
        if(Utility::checkNum(addrspace[index2].type)) {
            tempStat->index2 = index2;
        } else {
            throw rc_wrongvartype_exception(line, 0, "second argument");
        }

        if(ctx->TIME() != NULL) {
            std::string strTime = ctx->TIME()->getText();
            try{
                tempStat->time = std::stod(strTime.substr(1));
            }catch(std::exception &e) {
                int col = ctx->TIME()->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strTime);
            }
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitDelayExpr(RCcodeParser::DelayExprContext *ctx) override {
    	LOGGER_INF("DelayExpr");
        // DELAY TIME ';'                         
        int line = ctx->DELAY()->getSymbol()->getLine();
        RCSignalStatement *tempStat = new RCSignalStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSignalStatement::DELAY;

        if(ctx->TIME() != NULL) {
            std::string strTime = ctx->TIME()->getText();
            try{
                tempStat->time = std::stod(strTime.substr(1));
            }catch(std::exception &e) {
                int col = ctx->TIME()->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strTime);
            }
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitSetoutExpr(RCcodeParser::SetoutExprContext *ctx) override {
    	LOGGER_INF("SetoutExpr");
        // SETOUT ID ',' numorid ';'
        int line = ctx->SETOUT()->getSymbol()->getLine();
        RCSignalStatement *tempStat = new RCSignalStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSignalStatement::SETOUT;       

        std::string strVar = ctx->ID()->getText();
        if(dataIndexMap.find(strVar) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strVar]].type;
            if(Utility::checkNum(t)) {
                tempStat->index1 = dataIndexMap[strVar];
            } else {
                int col = ctx->ID()->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strVar);
            }
        } else {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strVar);
        }

        int index2 = visit(ctx->numorid()) ;
        if(Utility::checkNum(addrspace[index2].type)) {
            tempStat->index2 = index2;
        } else {
            throw rc_wrongvartype_exception(line, 0, "second argument");
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitDinExpr(RCcodeParser::DinExprContext *ctx) override {
    	LOGGER_INF("DinExpr");
        // DIN ID ',' ID ';'
        int line = ctx->DIN()->getSymbol()->getLine();
        RCSignalStatement *tempStat = new RCSignalStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSignalStatement::DIN;    

        std::string strIndex1 = ctx->ID(0)->getText();
        if(dataIndexMap.find(strIndex1) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strIndex1]].type;
            if(Utility::checkNum(t)) {
                tempStat->index1 = dataIndexMap[strIndex1];
            } else {
                int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strIndex1);
            }
        } else {
            int col = ctx->ID(0)->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strIndex1);
        }

        std::string strIndex2 = ctx->ID(1)->getText();
        if(dataIndexMap.find(strIndex2) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strIndex2]].type;
            if(Utility::checkNum(t)) {
                tempStat->index2 = dataIndexMap[strIndex2];
            } else {
                int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strIndex2);
            }
        } else {
            int col = ctx->ID(1)->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strIndex2);
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitIncExpr(RCcodeParser::IncExprContext *ctx) override {
    	LOGGER_INF("IncExpr");
        // INCR ID ';'
        int line = ctx->INCR()->getSymbol()->getLine();
        RCMathStatement *tempStat = new RCMathStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCMathStatement::INCR;   

        std::string strVar = ctx->ID()->getText();
        if(dataIndexMap.find(strVar) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strVar]].type;
            if(Utility::checkNum(t)) {
                tempStat->index1 = dataIndexMap[strVar];
            } else {
                int col = ctx->ID()->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strVar);
            }
        } else {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strVar);
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitDecExpr(RCcodeParser::DecExprContext *ctx) override {
    	LOGGER_INF("DecExpr");
        // DECR ID ';'
        int line = ctx->DECR()->getSymbol()->getLine();
        RCMathStatement *tempStat = new RCMathStatement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCMathStatement::DECR;   

        std::string strVar = ctx->ID()->getText();
        if(dataIndexMap.find(strVar) != dataIndexMap.end()) {
            uint8_t t = addrspace[dataIndexMap[strVar]].type;
            if(Utility::checkNum(t)) {
                tempStat->index1 = dataIndexMap[strVar];
            } else {
                int col = ctx->ID()->getSymbol()->getCharPositionInLine();
                throw rc_wrongvartype_exception(line, col, strVar);
            }
        } else {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strVar);
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitFuncExpr(RCcodeParser::FuncExprContext *ctx) override {
    	LOGGER_INF("FuncExpr");
        // FUNC op1=(ELEM | ID) ',' op2=(ELEM | ID | NUM)';'
        int line = ctx->FUNC()->getSymbol()->getLine();
        RCMathStatement *tempStat = new RCMathStatement(symbolTable);

        tempStat->lineno = line;

        std::string funcName = ctx->FUNC()->getText();
        if(funcName == "ADD") tempStat->type = RCMathStatement::ADD;
        else if(funcName == "SUB") tempStat->type = RCMathStatement::SUB;
        else if(funcName == "MUL") tempStat->type = RCMathStatement::MUL;
        else if(funcName == "DIV") tempStat->type = RCMathStatement::DIV;
        else if(funcName == "SIN") tempStat->type = RCMathStatement::SIN;
        else if(funcName == "COS") tempStat->type = RCMathStatement::COS;
        else if(funcName == "ATAN") tempStat->type = RCMathStatement::ATAN;
        else if(funcName == "SQRT") tempStat->type = RCMathStatement::SQRT;
        else if(funcName == "OR") tempStat->type = RCMathStatement::OR;
        else if(funcName == "AND") tempStat->type = RCMathStatement::AND;
        else if(funcName == "NOT") tempStat->type = RCMathStatement::NOT;
        else if(funcName == "XOR") tempStat->type = RCMathStatement::XOR;
        else {
            throw rc_nullinstruction_exception(line, 0, funcName);
        } 

        int elemIndex = 0;
        int idIndex = 0;
        if(ctx->op1->getType() == RCcodeParser::ELEM) {
            
            std::string strElem = ctx->ELEM(elemIndex)->getText();
            std::pair<std::string, std::string> pairElem;
            Utility::parseElem(strElem, pairElem);

            std::string strPoint = pairElem.first;
            if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
                uint8_t t = addrspace[dataIndexMap[strPoint]].type;
                if(t == TJTPOSE || t == TTRPOSE) {
                    tempStat->elem1.first = dataIndexMap[strPoint];
                } else {
                    int col = ctx->ELEM(elemIndex)->getSymbol()->getCharPositionInLine();
                    throw rc_wrongvartype_exception(line, col, strPoint);
                }
            } else {
                int col = ctx->ELEM(elemIndex)->getSymbol()->getCharPositionInLine();
                throw rc_pointnotdefined_exception(line, col, strPoint);
            }

            try{
                tempStat->elem1.second = std::stoi(pairElem.second);
            } catch(std::exception &e) {
                int col = ctx->ELEM(elemIndex)->getSymbol()->getCharPositionInLine();
                throw rc_numformat_exception(line, col+4, strPoint + "(" + pairElem.second + ")");
            }
            elemIndex ++;
        } else {
            std::string strVar = ctx->ID(idIndex)->getText();
            if(dataIndexMap.find(strVar) != dataIndexMap.end()) {
                uint8_t t = addrspace[dataIndexMap[strVar]].type;
                if(Utility::checkNum(t)) {
                    tempStat->index1 = dataIndexMap[strVar];
                } else {
                    int col = ctx->ID(idIndex)->getSymbol()->getCharPositionInLine();
                    throw rc_wrongvartype_exception(line, col, strVar);
                }
            } else {
                int col = ctx->ID(idIndex)->getSymbol()->getCharPositionInLine();
                throw rc_varnotdefined_exception(line, col, strVar);
            }
            idIndex ++;
        }

        if(ctx->op2->getType() == RCcodeParser::ELEM) {
            std::string strElem = ctx->ELEM(elemIndex)->getText();
            std::pair<std::string, std::string> pairElem;
            Utility::parseElem(strElem, pairElem);

            std::string strPoint = pairElem.first;
            if(dataIndexMap.find(strPoint) != dataIndexMap.end()) {
                uint8_t t = addrspace[dataIndexMap[strPoint]].type;
                if(t == TJTPOSE || t == TTRPOSE) {
                    tempStat->elem2.first = dataIndexMap[strPoint];
                } else {
                    int col = ctx->ELEM(elemIndex)->getSymbol()->getCharPositionInLine();
                    throw rc_wrongvartype_exception(line, col, strPoint);
                }
            } else {
                int col = ctx->ELEM(elemIndex)->getSymbol()->getCharPositionInLine();
                throw rc_pointnotdefined_exception(line, col, strPoint);
            }

            try{
                tempStat->elem2.second = std::stoi(pairElem.second);
            } catch(std::exception &e) {
                int col = ctx->ELEM(elemIndex)->getSymbol()->getCharPositionInLine();
                throw rc_numformat_exception(line, col+4, strPoint + "(" + pairElem.second + ")");
            }
        } else if(ctx->op2->getType() == RCcodeParser::ID) {
            std::string strVar = ctx->ID(idIndex)->getText();
            if(dataIndexMap.find(strVar) != dataIndexMap.end()) {
                uint8_t t = addrspace[dataIndexMap[strVar]].type;
                if(Utility::checkNum(t)) {
                    tempStat->index2 = dataIndexMap[strVar];
                } else {
                    int col = ctx->ID(idIndex)->getSymbol()->getCharPositionInLine();
                    throw rc_wrongvartype_exception(line, col, strVar);
                }
            } else {
                int col = ctx->ID(idIndex)->getSymbol()->getCharPositionInLine();
                throw rc_varnotdefined_exception(line, col, strVar);
            }
        } else {
            std::string strNum = ctx->NUM()->getText();
            if(constIndexMap.find(strNum) == constIndexMap.end()) {
                int index = addrspace.size();
                try{
                    if(Utility::checkInt(strNum)) {
                        int constVal = Utility::parseInt(strNum);
                        constIndexMap.insert({strNum, index});
                        addrspace.push_back(RC_IValue(TINT, constVal));
                    } else {
                        double constVal = Utility::parseDouble(strNum);
                        constIndexMap.insert({strNum, index});
                        addrspace.push_back(RC_IValue(TDOUBLE, constVal));
                    }
                    tempStat->index2 = index;
                } catch(std::exception &e) {
                    int col = ctx->NUM()->getSymbol()->getCharPositionInLine();
                    throw rc_numformat_exception(line, col, strNum);
                }
            } else {
                tempStat->index2 = constIndexMap[strNum];
            }
        }

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitCallExpr(RCcodeParser::CallExprContext *ctx) override {
    	LOGGER_INF("CallExpr");
        // CALL ID ';'
        int line = ctx->CALL()->getSymbol()->getLine();
        RCCallStatement *tempStat = new RCCallStatement(symbolTable);
        tempStat->lineno = line;
        tempStat->programName = ctx->ID()->getText();
        return dynamic_cast<RCBaseStatement*>(tempStat);
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
        int line = ctx->NUM()->getSymbol()->getLine();

        std::string strNum = ctx->NUM()->getText();
        if(constIndexMap.find(strNum) == constIndexMap.end()) {
            int index = addrspace.size();
            try{
                if(Utility::checkInt(strNum)) {
                    int constVal = Utility::parseInt(strNum);
                    constIndexMap.insert({strNum, index});
                    addrspace.push_back(RC_IValue(TINT, constVal));
                    return index;
                } else {
                    double constVal = Utility::parseDouble(strNum);
                    constIndexMap.insert({strNum, index});
                    addrspace.push_back(RC_IValue(TDOUBLE, constVal));
                    return index;
                }
            } catch(std::exception &e) {
                int col = ctx->NUM()->getSymbol()->getCharPositionInLine();
                throw rc_numformat_exception(line, col, strNum);
            }
        } else {
            return constIndexMap[strNum];
        }
    }

    virtual antlrcpp::Any visitIdExpr(RCcodeParser::IdExprContext *ctx) override {
    	LOGGER_INF("IdExpr");
        int line = ctx->ID()->getSymbol()->getLine();

        std::string strVar = ctx->ID()->getText();
        if(dataIndexMap.find(strVar) != dataIndexMap.end()) {
            return dataIndexMap[strVar];
        } else {
            int col = ctx->ID()->getSymbol()->getCharPositionInLine();
            throw rc_varnotdefined_exception(line, col, strVar);
        }
    }


    virtual antlrcpp::Any visitLabelExpr(RCcodeParser::LabelExprContext *ctx) override {
    	LOGGER_INF("LabelExpr");
        int line = ctx->LABEL()->getSymbol()->getLine();
        RCSingleInstStatemement *tempStat = new RCSingleInstStatemement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSingleInstStatemement::LABEL;   

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitRetExpr(RCcodeParser::RetExprContext *ctx) override {
    	LOGGER_INF("RetExpr");
        int line = ctx->RET()->getSymbol()->getLine();
        RCSingleInstStatemement *tempStat = new RCSingleInstStatemement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSingleInstStatemement::RET;   

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitNopExpr(RCcodeParser::NopExprContext *ctx) override {
    	LOGGER_INF("NopExpr");
        int line = ctx->NOP()->getSymbol()->getLine();
        RCSingleInstStatemement *tempStat = new RCSingleInstStatemement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSingleInstStatemement::NOP;   

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitPauseExpr(RCcodeParser::PauseExprContext *ctx) override {
    	LOGGER_INF("PauseExpr");
        int line = ctx->PAUSE()->getSymbol()->getLine();
        RCSingleInstStatemement *tempStat = new RCSingleInstStatemement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSingleInstStatemement::PAUSE;   

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitHaltExpr(RCcodeParser::HaltExprContext *ctx) override {
    	LOGGER_INF("HaltExpr");
        int line = ctx->HALT()->getSymbol()->getLine();
        RCSingleInstStatemement *tempStat = new RCSingleInstStatemement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSingleInstStatemement::HALT;   

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }

    virtual antlrcpp::Any visitBreakExpr(RCcodeParser::BreakExprContext *ctx) override {
    	LOGGER_INF("BreakExpr");
        int line = ctx->BREAK()->getSymbol()->getLine();
        RCSingleInstStatemement *tempStat = new RCSingleInstStatemement(symbolTable);

        tempStat->lineno = line;
        tempStat->type = RCSingleInstStatemement::BREAK;   

        return dynamic_cast<RCBaseStatement*>(tempStat);
    }
};