#pragma once

#include "RCcodeBaseVisitor.h"


class RCcodeGenerator : public RCcodeBaseVisitor {
public:

  virtual antlrcpp::Any visitProgram(RCcodeParser::ProgramContext *ctx) override {
  	LOGGER_INF("Program");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatBlock(RCcodeParser::StatBlockContext *ctx) override {
  	LOGGER_INF("StatBlock");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRobotStat(RCcodeParser::RobotStatContext *ctx) override {
  	LOGGER_INF("RobotStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDataStat(RCcodeParser::DataStatContext *ctx) override {
  	LOGGER_INF("DataStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSignalStat(RCcodeParser::SignalStatContext *ctx) override {
  	LOGGER_INF("SignalStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMathStat(RCcodeParser::MathStatContext *ctx) override {
  	LOGGER_INF("MathStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOnewordStat(RCcodeParser::OnewordStatContext *ctx) override {
  	LOGGER_INF("OnewordStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignStat(RCcodeParser::AssignStatContext *ctx) override {
  	LOGGER_INF("AssignStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGotoStat(RCcodeParser::GotoStatContext *ctx) override {
  	LOGGER_INF("GotoStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStat(RCcodeParser::IfStatContext *ctx) override {
  	LOGGER_INF("IfStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStat(RCcodeParser::ForStatContext *ctx) override {
  	LOGGER_INF("ForStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStat(RCcodeParser::WhileStatContext *ctx) override {
  	LOGGER_INF("WhileStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLibcallStat(RCcodeParser::LibcallStatContext *ctx) override {
  	LOGGER_INF("LibcallStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallStat(RCcodeParser::CallStatContext *ctx) override {
  	LOGGER_INF("CallStat");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMovjExpr(RCcodeParser::MovjExprContext *ctx) override {
  	LOGGER_INF("MovjExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMovlExpr(RCcodeParser::MovlExprContext *ctx) override {
  	LOGGER_INF("MovlExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMovcExpr(RCcodeParser::MovcExprContext *ctx) override {
  	LOGGER_INF("MovcExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMovsExpr(RCcodeParser::MovsExprContext *ctx) override {
  	LOGGER_INF("MovsExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftonExpr(RCcodeParser::ShiftonExprContext *ctx) override {
  	LOGGER_INF("ShiftonExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShiftoffExpr(RCcodeParser::ShiftoffExprContext *ctx) override {
  	LOGGER_INF("ShiftoffExpr");
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetExpr(RCcodeParser::SetExprContext *ctx) override {
  	LOGGER_INF("SetExpr");
    return visitChildren(ctx);
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