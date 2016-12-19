
// Generated from RCcode.g by ANTLR 4.6


#include "RCcodeVisitor.h"

#include "RCcodeParser.h"


using namespace antlrcpp;
using namespace antlr4;

RCcodeParser::RCcodeParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

RCcodeParser::~RCcodeParser() {
  delete _interpreter;
}

std::string RCcodeParser::getGrammarFileName() const {
  return "RCcode.g";
}

const std::vector<std::string>& RCcodeParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& RCcodeParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

RCcodeParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::ProgContext::getRuleIndex() const {
  return RCcodeParser::RuleProg;
}

void RCcodeParser::ProgContext::copyFrom(ProgContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProgramContext ------------------------------------------------------------------

RCcodeParser::BlockContext* RCcodeParser::ProgramContext::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::ProgramContext::EOF() {
  return getToken(RCcodeParser::EOF, 0);
}

RCcodeParser::ProgramContext::ProgramContext(ProgContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::ProgContext* RCcodeParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, RCcodeParser::RuleProg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<ProgContext *>(_tracker.createInstance<RCcodeParser::ProgramContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(44);
    block();
    setState(45);
    match(RCcodeParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

RCcodeParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::BlockContext::getRuleIndex() const {
  return RCcodeParser::RuleBlock;
}

void RCcodeParser::BlockContext::copyFrom(BlockContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StatBlockContext ------------------------------------------------------------------

std::vector<RCcodeParser::StatContext *> RCcodeParser::StatBlockContext::stat() {
  return getRuleContexts<RCcodeParser::StatContext>();
}

RCcodeParser::StatContext* RCcodeParser::StatBlockContext::stat(size_t i) {
  return getRuleContext<RCcodeParser::StatContext>(i);
}

RCcodeParser::StatBlockContext::StatBlockContext(BlockContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::StatBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitStatBlock(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::BlockContext* RCcodeParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 2, RCcodeParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<BlockContext *>(_tracker.createInstance<RCcodeParser::StatBlockContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RCcodeParser::GOTO)
      | (1ULL << RCcodeParser::IF)
      | (1ULL << RCcodeParser::WHILE)
      | (1ULL << RCcodeParser::FOR)
      | (1ULL << RCcodeParser::MOVJ)
      | (1ULL << RCcodeParser::MOVL)
      | (1ULL << RCcodeParser::MOVC)
      | (1ULL << RCcodeParser::MOVS)
      | (1ULL << RCcodeParser::SHIFTON)
      | (1ULL << RCcodeParser::SHIFTOFF)
      | (1ULL << RCcodeParser::SET)
      | (1ULL << RCcodeParser::SETE)
      | (1ULL << RCcodeParser::GETE)
      | (1ULL << RCcodeParser::WAIT)
      | (1ULL << RCcodeParser::DELAY)
      | (1ULL << RCcodeParser::SETOUT)
      | (1ULL << RCcodeParser::DIN)
      | (1ULL << RCcodeParser::LABEL)
      | (1ULL << RCcodeParser::RET)
      | (1ULL << RCcodeParser::NOP)
      | (1ULL << RCcodeParser::PAUSE)
      | (1ULL << RCcodeParser::HALT)
      | (1ULL << RCcodeParser::BREAK)
      | (1ULL << RCcodeParser::INCR)
      | (1ULL << RCcodeParser::DECR)
      | (1ULL << RCcodeParser::CALL)
      | (1ULL << RCcodeParser::FUNC)
      | (1ULL << RCcodeParser::ID))) != 0)) {
      setState(47);
      stat();
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

RCcodeParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::StatContext::getRuleIndex() const {
  return RCcodeParser::RuleStat;
}

void RCcodeParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileStatContext ------------------------------------------------------------------

RCcodeParser::While_statContext* RCcodeParser::WhileStatContext::while_stat() {
  return getRuleContext<RCcodeParser::While_statContext>(0);
}

RCcodeParser::WhileStatContext::WhileStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::WhileStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitWhileStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForStatContext ------------------------------------------------------------------

RCcodeParser::For_statContext* RCcodeParser::ForStatContext::for_stat() {
  return getRuleContext<RCcodeParser::For_statContext>(0);
}

RCcodeParser::ForStatContext::ForStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ForStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitForStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStatContext ------------------------------------------------------------------

RCcodeParser::Assign_statContext* RCcodeParser::AssignStatContext::assign_stat() {
  return getRuleContext<RCcodeParser::Assign_statContext>(0);
}

RCcodeParser::AssignStatContext::AssignStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::AssignStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitAssignStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GotoStatContext ------------------------------------------------------------------

RCcodeParser::Goto_statContext* RCcodeParser::GotoStatContext::goto_stat() {
  return getRuleContext<RCcodeParser::Goto_statContext>(0);
}

RCcodeParser::GotoStatContext::GotoStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::GotoStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitGotoStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MathStatContext ------------------------------------------------------------------

RCcodeParser::Math_statContext* RCcodeParser::MathStatContext::math_stat() {
  return getRuleContext<RCcodeParser::Math_statContext>(0);
}

RCcodeParser::MathStatContext::MathStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::MathStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitMathStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RobotStatContext ------------------------------------------------------------------

RCcodeParser::Robot_statContext* RCcodeParser::RobotStatContext::robot_stat() {
  return getRuleContext<RCcodeParser::Robot_statContext>(0);
}

RCcodeParser::RobotStatContext::RobotStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::RobotStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitRobotStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStatContext ------------------------------------------------------------------

RCcodeParser::If_statContext* RCcodeParser::IfStatContext::if_stat() {
  return getRuleContext<RCcodeParser::If_statContext>(0);
}

RCcodeParser::IfStatContext::IfStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::IfStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitIfStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DataStatContext ------------------------------------------------------------------

RCcodeParser::Data_statContext* RCcodeParser::DataStatContext::data_stat() {
  return getRuleContext<RCcodeParser::Data_statContext>(0);
}

RCcodeParser::DataStatContext::DataStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::DataStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitDataStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SignalStatContext ------------------------------------------------------------------

RCcodeParser::Signal_statContext* RCcodeParser::SignalStatContext::signal_stat() {
  return getRuleContext<RCcodeParser::Signal_statContext>(0);
}

RCcodeParser::SignalStatContext::SignalStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::SignalStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitSignalStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LibcallStatContext ------------------------------------------------------------------

RCcodeParser::Libcall_statContext* RCcodeParser::LibcallStatContext::libcall_stat() {
  return getRuleContext<RCcodeParser::Libcall_statContext>(0);
}

RCcodeParser::LibcallStatContext::LibcallStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::LibcallStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitLibcallStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallStatContext ------------------------------------------------------------------

RCcodeParser::Call_statContext* RCcodeParser::CallStatContext::call_stat() {
  return getRuleContext<RCcodeParser::Call_statContext>(0);
}

RCcodeParser::CallStatContext::CallStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::CallStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitCallStat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OnewordStatContext ------------------------------------------------------------------

RCcodeParser::Oneinst_statContext* RCcodeParser::OnewordStatContext::oneinst_stat() {
  return getRuleContext<RCcodeParser::Oneinst_statContext>(0);
}

RCcodeParser::OnewordStatContext::OnewordStatContext(StatContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::OnewordStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitOnewordStat(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::StatContext* RCcodeParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 4, RCcodeParser::RuleStat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(65);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::RobotStatContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(53);
      robot_stat();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::DataStatContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(54);
      data_stat();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::SignalStatContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(55);
      signal_stat();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::MathStatContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(56);
      math_stat();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::OnewordStatContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(57);
      oneinst_stat();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::AssignStatContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(58);
      assign_stat();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::GotoStatContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(59);
      goto_stat();
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::IfStatContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(60);
      if_stat();
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::ForStatContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(61);
      for_stat();
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::WhileStatContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(62);
      while_stat();
      break;
    }

    case 11: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::LibcallStatContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(63);
      libcall_stat();
      break;
    }

    case 12: {
      _localctx = dynamic_cast<StatContext *>(_tracker.createInstance<RCcodeParser::CallStatContext>(_localctx));
      enterOuterAlt(_localctx, 12);
      setState(64);
      call_stat();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Robot_statContext ------------------------------------------------------------------

RCcodeParser::Robot_statContext::Robot_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Robot_statContext::getRuleIndex() const {
  return RCcodeParser::RuleRobot_stat;
}

void RCcodeParser::Robot_statContext::copyFrom(Robot_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MovlExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::MovlExprContext::MOVL() {
  return getToken(RCcodeParser::MOVL, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::MovlExprContext::ID() {
  return getTokens(RCcodeParser::ID);
}

tree::TerminalNode* RCcodeParser::MovlExprContext::ID(size_t i) {
  return getToken(RCcodeParser::ID, i);
}

RCcodeParser::MovlExprContext::MovlExprContext(Robot_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::MovlExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitMovlExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MovcExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::MovcExprContext::MOVC() {
  return getToken(RCcodeParser::MOVC, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::MovcExprContext::ID() {
  return getTokens(RCcodeParser::ID);
}

tree::TerminalNode* RCcodeParser::MovcExprContext::ID(size_t i) {
  return getToken(RCcodeParser::ID, i);
}

RCcodeParser::MovcExprContext::MovcExprContext(Robot_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::MovcExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitMovcExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MovjExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::MovjExprContext::MOVJ() {
  return getToken(RCcodeParser::MOVJ, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::MovjExprContext::ID() {
  return getTokens(RCcodeParser::ID);
}

tree::TerminalNode* RCcodeParser::MovjExprContext::ID(size_t i) {
  return getToken(RCcodeParser::ID, i);
}

RCcodeParser::MovjExprContext::MovjExprContext(Robot_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::MovjExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitMovjExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShiftoffExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::ShiftoffExprContext::SHIFTOFF() {
  return getToken(RCcodeParser::SHIFTOFF, 0);
}

RCcodeParser::ShiftoffExprContext::ShiftoffExprContext(Robot_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ShiftoffExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitShiftoffExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MovsExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::MovsExprContext::MOVS() {
  return getToken(RCcodeParser::MOVS, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::MovsExprContext::ID() {
  return getTokens(RCcodeParser::ID);
}

tree::TerminalNode* RCcodeParser::MovsExprContext::ID(size_t i) {
  return getToken(RCcodeParser::ID, i);
}

RCcodeParser::MovsExprContext::MovsExprContext(Robot_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::MovsExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitMovsExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ShiftonExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::ShiftonExprContext::SHIFTON() {
  return getToken(RCcodeParser::SHIFTON, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::ShiftonExprContext::ID() {
  return getTokens(RCcodeParser::ID);
}

tree::TerminalNode* RCcodeParser::ShiftonExprContext::ID(size_t i) {
  return getToken(RCcodeParser::ID, i);
}

RCcodeParser::ShiftonExprContext::ShiftonExprContext(Robot_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ShiftonExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitShiftonExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Robot_statContext* RCcodeParser::robot_stat() {
  Robot_statContext *_localctx = _tracker.createInstance<Robot_statContext>(_ctx, getState());
  enterRule(_localctx, 6, RCcodeParser::RuleRobot_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RCcodeParser::MOVJ: {
        _localctx = dynamic_cast<Robot_statContext *>(_tracker.createInstance<RCcodeParser::MovjExprContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(67);
        match(RCcodeParser::MOVJ);
        setState(68);
        match(RCcodeParser::ID);
        setState(69);
        match(RCcodeParser::T__0);
        setState(70);
        match(RCcodeParser::ID);
        setState(71);
        match(RCcodeParser::T__0);
        setState(72);
        match(RCcodeParser::ID);
        setState(73);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::MOVL: {
        _localctx = dynamic_cast<Robot_statContext *>(_tracker.createInstance<RCcodeParser::MovlExprContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(74);
        match(RCcodeParser::MOVL);
        setState(75);
        match(RCcodeParser::ID);
        setState(76);
        match(RCcodeParser::T__0);
        setState(77);
        match(RCcodeParser::ID);
        setState(78);
        match(RCcodeParser::T__0);
        setState(79);
        match(RCcodeParser::ID);
        setState(80);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::MOVC: {
        _localctx = dynamic_cast<Robot_statContext *>(_tracker.createInstance<RCcodeParser::MovcExprContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(81);
        match(RCcodeParser::MOVC);
        setState(82);
        match(RCcodeParser::ID);
        setState(83);
        match(RCcodeParser::T__0);
        setState(84);
        match(RCcodeParser::ID);
        setState(85);
        match(RCcodeParser::T__0);
        setState(86);
        match(RCcodeParser::ID);
        setState(87);
        match(RCcodeParser::T__0);
        setState(88);
        match(RCcodeParser::ID);
        setState(89);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::MOVS: {
        _localctx = dynamic_cast<Robot_statContext *>(_tracker.createInstance<RCcodeParser::MovsExprContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(90);
        match(RCcodeParser::MOVS);
        setState(91);
        match(RCcodeParser::ID);
        setState(92);
        match(RCcodeParser::T__0);
        setState(93);
        match(RCcodeParser::ID);
        setState(94);
        match(RCcodeParser::T__0);
        setState(95);
        match(RCcodeParser::ID);
        setState(96);
        match(RCcodeParser::T__0);
        setState(97);
        match(RCcodeParser::ID);
        setState(98);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::SHIFTON: {
        _localctx = dynamic_cast<Robot_statContext *>(_tracker.createInstance<RCcodeParser::ShiftonExprContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(99);
        match(RCcodeParser::SHIFTON);
        setState(100);
        match(RCcodeParser::ID);
        setState(101);
        match(RCcodeParser::T__0);
        setState(102);
        match(RCcodeParser::ID);
        setState(103);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::SHIFTOFF: {
        _localctx = dynamic_cast<Robot_statContext *>(_tracker.createInstance<RCcodeParser::ShiftoffExprContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(104);
        match(RCcodeParser::SHIFTOFF);
        setState(105);
        match(RCcodeParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Data_statContext ------------------------------------------------------------------

RCcodeParser::Data_statContext::Data_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Data_statContext::getRuleIndex() const {
  return RCcodeParser::RuleData_stat;
}

void RCcodeParser::Data_statContext::copyFrom(Data_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SetExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::SetExprContext::SET() {
  return getToken(RCcodeParser::SET, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::SetExprContext::ID() {
  return getTokens(RCcodeParser::ID);
}

tree::TerminalNode* RCcodeParser::SetExprContext::ID(size_t i) {
  return getToken(RCcodeParser::ID, i);
}

RCcodeParser::SetExprContext::SetExprContext(Data_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::SetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitSetExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SeteExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::SeteExprContext::SETE() {
  return getToken(RCcodeParser::SETE, 0);
}

tree::TerminalNode* RCcodeParser::SeteExprContext::ELEM() {
  return getToken(RCcodeParser::ELEM, 0);
}

tree::TerminalNode* RCcodeParser::SeteExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

RCcodeParser::SeteExprContext::SeteExprContext(Data_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::SeteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitSeteExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GeteExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::GeteExprContext::GETE() {
  return getToken(RCcodeParser::GETE, 0);
}

tree::TerminalNode* RCcodeParser::GeteExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::GeteExprContext::ELEM() {
  return getToken(RCcodeParser::ELEM, 0);
}

RCcodeParser::GeteExprContext::GeteExprContext(Data_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::GeteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitGeteExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Data_statContext* RCcodeParser::data_stat() {
  Data_statContext *_localctx = _tracker.createInstance<Data_statContext>(_ctx, getState());
  enterRule(_localctx, 8, RCcodeParser::RuleData_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RCcodeParser::SET: {
        _localctx = dynamic_cast<Data_statContext *>(_tracker.createInstance<RCcodeParser::SetExprContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(108);
        match(RCcodeParser::SET);
        setState(109);
        match(RCcodeParser::ID);
        setState(110);
        match(RCcodeParser::T__0);
        setState(111);
        match(RCcodeParser::ID);
        setState(112);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::SETE: {
        _localctx = dynamic_cast<Data_statContext *>(_tracker.createInstance<RCcodeParser::SeteExprContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(113);
        match(RCcodeParser::SETE);
        setState(114);
        match(RCcodeParser::ELEM);
        setState(115);
        match(RCcodeParser::T__0);
        setState(116);
        match(RCcodeParser::ID);
        setState(117);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::GETE: {
        _localctx = dynamic_cast<Data_statContext *>(_tracker.createInstance<RCcodeParser::GeteExprContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(118);
        match(RCcodeParser::GETE);
        setState(119);
        match(RCcodeParser::ID);
        setState(120);
        match(RCcodeParser::T__0);
        setState(121);
        match(RCcodeParser::ELEM);
        setState(122);
        match(RCcodeParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signal_statContext ------------------------------------------------------------------

RCcodeParser::Signal_statContext::Signal_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Signal_statContext::getRuleIndex() const {
  return RCcodeParser::RuleSignal_stat;
}

void RCcodeParser::Signal_statContext::copyFrom(Signal_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WaitExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::WaitExprContext::WAIT() {
  return getToken(RCcodeParser::WAIT, 0);
}

tree::TerminalNode* RCcodeParser::WaitExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

RCcodeParser::NumoridContext* RCcodeParser::WaitExprContext::numorid() {
  return getRuleContext<RCcodeParser::NumoridContext>(0);
}

tree::TerminalNode* RCcodeParser::WaitExprContext::EQ() {
  return getToken(RCcodeParser::EQ, 0);
}

tree::TerminalNode* RCcodeParser::WaitExprContext::GE() {
  return getToken(RCcodeParser::GE, 0);
}

tree::TerminalNode* RCcodeParser::WaitExprContext::LE() {
  return getToken(RCcodeParser::LE, 0);
}

tree::TerminalNode* RCcodeParser::WaitExprContext::LT() {
  return getToken(RCcodeParser::LT, 0);
}

tree::TerminalNode* RCcodeParser::WaitExprContext::GT() {
  return getToken(RCcodeParser::GT, 0);
}

tree::TerminalNode* RCcodeParser::WaitExprContext::NE() {
  return getToken(RCcodeParser::NE, 0);
}

tree::TerminalNode* RCcodeParser::WaitExprContext::TIME() {
  return getToken(RCcodeParser::TIME, 0);
}

RCcodeParser::WaitExprContext::WaitExprContext(Signal_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::WaitExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitWaitExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DelayExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::DelayExprContext::DELAY() {
  return getToken(RCcodeParser::DELAY, 0);
}

tree::TerminalNode* RCcodeParser::DelayExprContext::TIME() {
  return getToken(RCcodeParser::TIME, 0);
}

RCcodeParser::DelayExprContext::DelayExprContext(Signal_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::DelayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitDelayExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SetoutExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::SetoutExprContext::SETOUT() {
  return getToken(RCcodeParser::SETOUT, 0);
}

tree::TerminalNode* RCcodeParser::SetoutExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

RCcodeParser::NumoridContext* RCcodeParser::SetoutExprContext::numorid() {
  return getRuleContext<RCcodeParser::NumoridContext>(0);
}

RCcodeParser::SetoutExprContext::SetoutExprContext(Signal_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::SetoutExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitSetoutExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DinExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::DinExprContext::DIN() {
  return getToken(RCcodeParser::DIN, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::DinExprContext::ID() {
  return getTokens(RCcodeParser::ID);
}

tree::TerminalNode* RCcodeParser::DinExprContext::ID(size_t i) {
  return getToken(RCcodeParser::ID, i);
}

RCcodeParser::DinExprContext::DinExprContext(Signal_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::DinExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitDinExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Signal_statContext* RCcodeParser::signal_stat() {
  Signal_statContext *_localctx = _tracker.createInstance<Signal_statContext>(_ctx, getState());
  enterRule(_localctx, 10, RCcodeParser::RuleSignal_stat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RCcodeParser::WAIT: {
        _localctx = dynamic_cast<Signal_statContext *>(_tracker.createInstance<RCcodeParser::WaitExprContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(125);
        match(RCcodeParser::WAIT);
        setState(126);
        match(RCcodeParser::ID);
        setState(127);
        dynamic_cast<WaitExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << RCcodeParser::EQ)
          | (1ULL << RCcodeParser::GT)
          | (1ULL << RCcodeParser::GE)
          | (1ULL << RCcodeParser::LT)
          | (1ULL << RCcodeParser::LE)
          | (1ULL << RCcodeParser::NE))) != 0))) {
          dynamic_cast<WaitExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(128);
        numorid();
        setState(131);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == RCcodeParser::T__0) {
          setState(129);
          match(RCcodeParser::T__0);
          setState(130);
          match(RCcodeParser::TIME);
        }
        setState(133);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::DELAY: {
        _localctx = dynamic_cast<Signal_statContext *>(_tracker.createInstance<RCcodeParser::DelayExprContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(135);
        match(RCcodeParser::DELAY);
        setState(136);
        match(RCcodeParser::TIME);
        setState(137);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::SETOUT: {
        _localctx = dynamic_cast<Signal_statContext *>(_tracker.createInstance<RCcodeParser::SetoutExprContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(138);
        match(RCcodeParser::SETOUT);
        setState(139);
        match(RCcodeParser::ID);
        setState(140);
        match(RCcodeParser::T__0);
        setState(141);
        numorid();
        setState(142);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::DIN: {
        _localctx = dynamic_cast<Signal_statContext *>(_tracker.createInstance<RCcodeParser::DinExprContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(144);
        match(RCcodeParser::DIN);
        setState(145);
        match(RCcodeParser::ID);
        setState(146);
        match(RCcodeParser::T__0);
        setState(147);
        match(RCcodeParser::ID);
        setState(148);
        match(RCcodeParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Math_statContext ------------------------------------------------------------------

RCcodeParser::Math_statContext::Math_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Math_statContext::getRuleIndex() const {
  return RCcodeParser::RuleMath_stat;
}

void RCcodeParser::Math_statContext::copyFrom(Math_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DecExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::DecExprContext::DECR() {
  return getToken(RCcodeParser::DECR, 0);
}

tree::TerminalNode* RCcodeParser::DecExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

RCcodeParser::DecExprContext::DecExprContext(Math_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::DecExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitDecExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::FuncExprContext::FUNC() {
  return getToken(RCcodeParser::FUNC, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::FuncExprContext::ELEM() {
  return getTokens(RCcodeParser::ELEM);
}

tree::TerminalNode* RCcodeParser::FuncExprContext::ELEM(size_t i) {
  return getToken(RCcodeParser::ELEM, i);
}

std::vector<tree::TerminalNode *> RCcodeParser::FuncExprContext::ID() {
  return getTokens(RCcodeParser::ID);
}

tree::TerminalNode* RCcodeParser::FuncExprContext::ID(size_t i) {
  return getToken(RCcodeParser::ID, i);
}

tree::TerminalNode* RCcodeParser::FuncExprContext::NUM() {
  return getToken(RCcodeParser::NUM, 0);
}

RCcodeParser::FuncExprContext::FuncExprContext(Math_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::FuncExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitFuncExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IncExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::IncExprContext::INCR() {
  return getToken(RCcodeParser::INCR, 0);
}

tree::TerminalNode* RCcodeParser::IncExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

RCcodeParser::IncExprContext::IncExprContext(Math_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::IncExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitIncExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Math_statContext* RCcodeParser::math_stat() {
  Math_statContext *_localctx = _tracker.createInstance<Math_statContext>(_ctx, getState());
  enterRule(_localctx, 12, RCcodeParser::RuleMath_stat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RCcodeParser::INCR: {
        _localctx = dynamic_cast<Math_statContext *>(_tracker.createInstance<RCcodeParser::IncExprContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(151);
        match(RCcodeParser::INCR);
        setState(152);
        match(RCcodeParser::ID);
        setState(153);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::DECR: {
        _localctx = dynamic_cast<Math_statContext *>(_tracker.createInstance<RCcodeParser::DecExprContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(154);
        match(RCcodeParser::DECR);
        setState(155);
        match(RCcodeParser::ID);
        setState(156);
        match(RCcodeParser::T__1);
        break;
      }

      case RCcodeParser::FUNC: {
        _localctx = dynamic_cast<Math_statContext *>(_tracker.createInstance<RCcodeParser::FuncExprContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(157);
        match(RCcodeParser::FUNC);
        setState(158);
        dynamic_cast<FuncExprContext *>(_localctx)->op1 = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == RCcodeParser::ELEM

        || _la == RCcodeParser::ID)) {
          dynamic_cast<FuncExprContext *>(_localctx)->op1 = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(159);
        match(RCcodeParser::T__0);
        setState(160);
        dynamic_cast<FuncExprContext *>(_localctx)->op2 = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << RCcodeParser::ELEM)
          | (1ULL << RCcodeParser::ID)
          | (1ULL << RCcodeParser::NUM))) != 0))) {
          dynamic_cast<FuncExprContext *>(_localctx)->op2 = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(161);
        match(RCcodeParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Call_statContext ------------------------------------------------------------------

RCcodeParser::Call_statContext::Call_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Call_statContext::getRuleIndex() const {
  return RCcodeParser::RuleCall_stat;
}

void RCcodeParser::Call_statContext::copyFrom(Call_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CallExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::CallExprContext::CALL() {
  return getToken(RCcodeParser::CALL, 0);
}

tree::TerminalNode* RCcodeParser::CallExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

RCcodeParser::CallExprContext::CallExprContext(Call_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::CallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitCallExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Call_statContext* RCcodeParser::call_stat() {
  Call_statContext *_localctx = _tracker.createInstance<Call_statContext>(_ctx, getState());
  enterRule(_localctx, 14, RCcodeParser::RuleCall_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<Call_statContext *>(_tracker.createInstance<RCcodeParser::CallExprContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(RCcodeParser::CALL);
    setState(165);
    match(RCcodeParser::ID);
    setState(166);
    match(RCcodeParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_statContext ------------------------------------------------------------------

RCcodeParser::Assign_statContext::Assign_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Assign_statContext::getRuleIndex() const {
  return RCcodeParser::RuleAssign_stat;
}

void RCcodeParser::Assign_statContext::copyFrom(Assign_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AssignExpr4Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::AssignExpr4Context::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr4Context::ASSIGN() {
  return getToken(RCcodeParser::ASSIGN, 0);
}

RCcodeParser::NumoridContext* RCcodeParser::AssignExpr4Context::numorid() {
  return getRuleContext<RCcodeParser::NumoridContext>(0);
}

RCcodeParser::AssignExpr4Context::AssignExpr4Context(Assign_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::AssignExpr4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitAssignExpr4(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExpr5Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::AssignExpr5Context::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr5Context::ASSIGN() {
  return getToken(RCcodeParser::ASSIGN, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr5Context::CSTRING() {
  return getToken(RCcodeParser::CSTRING, 0);
}

RCcodeParser::AssignExpr5Context::AssignExpr5Context(Assign_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::AssignExpr5Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitAssignExpr5(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExpr3Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::AssignExpr3Context::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr3Context::ASSIGN() {
  return getToken(RCcodeParser::ASSIGN, 0);
}

RCcodeParser::FuncallexprContext* RCcodeParser::AssignExpr3Context::funcallexpr() {
  return getRuleContext<RCcodeParser::FuncallexprContext>(0);
}

RCcodeParser::AssignExpr3Context::AssignExpr3Context(Assign_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::AssignExpr3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitAssignExpr3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExpr2Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::AssignExpr2Context::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::ASSIGN() {
  return getToken(RCcodeParser::ASSIGN, 0);
}

std::vector<RCcodeParser::NumoridContext *> RCcodeParser::AssignExpr2Context::numorid() {
  return getRuleContexts<RCcodeParser::NumoridContext>();
}

RCcodeParser::NumoridContext* RCcodeParser::AssignExpr2Context::numorid(size_t i) {
  return getRuleContext<RCcodeParser::NumoridContext>(i);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::ADD() {
  return getToken(RCcodeParser::ADD, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::SUB() {
  return getToken(RCcodeParser::SUB, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::MUL() {
  return getToken(RCcodeParser::MUL, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::DIV() {
  return getToken(RCcodeParser::DIV, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::EQ() {
  return getToken(RCcodeParser::EQ, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::GE() {
  return getToken(RCcodeParser::GE, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::LE() {
  return getToken(RCcodeParser::LE, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::GT() {
  return getToken(RCcodeParser::GT, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::LT() {
  return getToken(RCcodeParser::LT, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr2Context::NE() {
  return getToken(RCcodeParser::NE, 0);
}

RCcodeParser::AssignExpr2Context::AssignExpr2Context(Assign_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::AssignExpr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitAssignExpr2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExpr1Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::AssignExpr1Context::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::AssignExpr1Context::ASSIGN() {
  return getToken(RCcodeParser::ASSIGN, 0);
}

RCcodeParser::BoolvalContext* RCcodeParser::AssignExpr1Context::boolval() {
  return getRuleContext<RCcodeParser::BoolvalContext>(0);
}

RCcodeParser::AssignExpr1Context::AssignExpr1Context(Assign_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::AssignExpr1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitAssignExpr1(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Assign_statContext* RCcodeParser::assign_stat() {
  Assign_statContext *_localctx = _tracker.createInstance<Assign_statContext>(_ctx, getState());
  enterRule(_localctx, 16, RCcodeParser::RuleAssign_stat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(194);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Assign_statContext *>(_tracker.createInstance<RCcodeParser::AssignExpr1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(168);
      match(RCcodeParser::ID);
      setState(169);
      match(RCcodeParser::ASSIGN);
      setState(170);
      boolval();
      setState(171);
      match(RCcodeParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Assign_statContext *>(_tracker.createInstance<RCcodeParser::AssignExpr2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(173);
      match(RCcodeParser::ID);
      setState(174);
      match(RCcodeParser::ASSIGN);
      setState(175);
      numorid();
      setState(176);
      dynamic_cast<AssignExpr2Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << RCcodeParser::EQ)
        | (1ULL << RCcodeParser::GT)
        | (1ULL << RCcodeParser::GE)
        | (1ULL << RCcodeParser::LT)
        | (1ULL << RCcodeParser::LE)
        | (1ULL << RCcodeParser::NE)
        | (1ULL << RCcodeParser::ADD)
        | (1ULL << RCcodeParser::SUB)
        | (1ULL << RCcodeParser::MUL)
        | (1ULL << RCcodeParser::DIV))) != 0))) {
        dynamic_cast<AssignExpr2Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(177);
      numorid();
      setState(178);
      match(RCcodeParser::T__1);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Assign_statContext *>(_tracker.createInstance<RCcodeParser::AssignExpr3Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(180);
      match(RCcodeParser::ID);
      setState(181);
      match(RCcodeParser::ASSIGN);
      setState(182);
      funcallexpr();
      setState(183);
      match(RCcodeParser::T__1);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<Assign_statContext *>(_tracker.createInstance<RCcodeParser::AssignExpr4Context>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(185);
      match(RCcodeParser::ID);
      setState(186);
      match(RCcodeParser::ASSIGN);
      setState(187);
      numorid();
      setState(188);
      match(RCcodeParser::T__1);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<Assign_statContext *>(_tracker.createInstance<RCcodeParser::AssignExpr5Context>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(190);
      match(RCcodeParser::ID);
      setState(191);
      match(RCcodeParser::ASSIGN);
      setState(192);
      match(RCcodeParser::CSTRING);
      setState(193);
      match(RCcodeParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Goto_statContext ------------------------------------------------------------------

RCcodeParser::Goto_statContext::Goto_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Goto_statContext::getRuleIndex() const {
  return RCcodeParser::RuleGoto_stat;
}

void RCcodeParser::Goto_statContext::copyFrom(Goto_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- GotoExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::GotoExprContext::GOTO() {
  return getToken(RCcodeParser::GOTO, 0);
}

tree::TerminalNode* RCcodeParser::GotoExprContext::LABEL() {
  return getToken(RCcodeParser::LABEL, 0);
}

RCcodeParser::GotoExprContext::GotoExprContext(Goto_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::GotoExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitGotoExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Goto_statContext* RCcodeParser::goto_stat() {
  Goto_statContext *_localctx = _tracker.createInstance<Goto_statContext>(_ctx, getState());
  enterRule(_localctx, 18, RCcodeParser::RuleGoto_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<Goto_statContext *>(_tracker.createInstance<RCcodeParser::GotoExprContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(RCcodeParser::GOTO);
    setState(197);
    match(RCcodeParser::LABEL);
    setState(198);
    match(RCcodeParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statContext ------------------------------------------------------------------

RCcodeParser::If_statContext::If_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::If_statContext::getRuleIndex() const {
  return RCcodeParser::RuleIf_stat;
}

void RCcodeParser::If_statContext::copyFrom(If_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfExpr1Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::IfExpr1Context::IF() {
  return getToken(RCcodeParser::IF, 0);
}

std::vector<RCcodeParser::NumoridContext *> RCcodeParser::IfExpr1Context::numorid() {
  return getRuleContexts<RCcodeParser::NumoridContext>();
}

RCcodeParser::NumoridContext* RCcodeParser::IfExpr1Context::numorid(size_t i) {
  return getRuleContext<RCcodeParser::NumoridContext>(i);
}

tree::TerminalNode* RCcodeParser::IfExpr1Context::THEN() {
  return getToken(RCcodeParser::THEN, 0);
}

RCcodeParser::BlockContext* RCcodeParser::IfExpr1Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::IfExpr1Context::ENDIF() {
  return getToken(RCcodeParser::ENDIF, 0);
}

tree::TerminalNode* RCcodeParser::IfExpr1Context::EQ() {
  return getToken(RCcodeParser::EQ, 0);
}

tree::TerminalNode* RCcodeParser::IfExpr1Context::GE() {
  return getToken(RCcodeParser::GE, 0);
}

tree::TerminalNode* RCcodeParser::IfExpr1Context::LE() {
  return getToken(RCcodeParser::LE, 0);
}

tree::TerminalNode* RCcodeParser::IfExpr1Context::LT() {
  return getToken(RCcodeParser::LT, 0);
}

tree::TerminalNode* RCcodeParser::IfExpr1Context::GT() {
  return getToken(RCcodeParser::GT, 0);
}

tree::TerminalNode* RCcodeParser::IfExpr1Context::NE() {
  return getToken(RCcodeParser::NE, 0);
}

std::vector<RCcodeParser::Elseif_statContext *> RCcodeParser::IfExpr1Context::elseif_stat() {
  return getRuleContexts<RCcodeParser::Elseif_statContext>();
}

RCcodeParser::Elseif_statContext* RCcodeParser::IfExpr1Context::elseif_stat(size_t i) {
  return getRuleContext<RCcodeParser::Elseif_statContext>(i);
}

RCcodeParser::Else_statContext* RCcodeParser::IfExpr1Context::else_stat() {
  return getRuleContext<RCcodeParser::Else_statContext>(0);
}

RCcodeParser::IfExpr1Context::IfExpr1Context(If_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::IfExpr1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitIfExpr1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfExpr3Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::IfExpr3Context::IF() {
  return getToken(RCcodeParser::IF, 0);
}

tree::TerminalNode* RCcodeParser::IfExpr3Context::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::IfExpr3Context::THEN() {
  return getToken(RCcodeParser::THEN, 0);
}

RCcodeParser::BlockContext* RCcodeParser::IfExpr3Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::IfExpr3Context::ENDIF() {
  return getToken(RCcodeParser::ENDIF, 0);
}

std::vector<RCcodeParser::Elseif_statContext *> RCcodeParser::IfExpr3Context::elseif_stat() {
  return getRuleContexts<RCcodeParser::Elseif_statContext>();
}

RCcodeParser::Elseif_statContext* RCcodeParser::IfExpr3Context::elseif_stat(size_t i) {
  return getRuleContext<RCcodeParser::Elseif_statContext>(i);
}

RCcodeParser::Else_statContext* RCcodeParser::IfExpr3Context::else_stat() {
  return getRuleContext<RCcodeParser::Else_statContext>(0);
}

RCcodeParser::IfExpr3Context::IfExpr3Context(If_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::IfExpr3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitIfExpr3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfExpr2Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::IfExpr2Context::IF() {
  return getToken(RCcodeParser::IF, 0);
}

RCcodeParser::BoolvalContext* RCcodeParser::IfExpr2Context::boolval() {
  return getRuleContext<RCcodeParser::BoolvalContext>(0);
}

tree::TerminalNode* RCcodeParser::IfExpr2Context::THEN() {
  return getToken(RCcodeParser::THEN, 0);
}

RCcodeParser::BlockContext* RCcodeParser::IfExpr2Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::IfExpr2Context::ENDIF() {
  return getToken(RCcodeParser::ENDIF, 0);
}

std::vector<RCcodeParser::Elseif_statContext *> RCcodeParser::IfExpr2Context::elseif_stat() {
  return getRuleContexts<RCcodeParser::Elseif_statContext>();
}

RCcodeParser::Elseif_statContext* RCcodeParser::IfExpr2Context::elseif_stat(size_t i) {
  return getRuleContext<RCcodeParser::Elseif_statContext>(i);
}

RCcodeParser::Else_statContext* RCcodeParser::IfExpr2Context::else_stat() {
  return getRuleContext<RCcodeParser::Else_statContext>(0);
}

RCcodeParser::IfExpr2Context::IfExpr2Context(If_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::IfExpr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitIfExpr2(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::If_statContext* RCcodeParser::if_stat() {
  If_statContext *_localctx = _tracker.createInstance<If_statContext>(_ctx, getState());
  enterRule(_localctx, 20, RCcodeParser::RuleIf_stat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(250);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<If_statContext *>(_tracker.createInstance<RCcodeParser::IfExpr1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(200);
      match(RCcodeParser::IF);
      setState(201);
      numorid();
      setState(202);
      dynamic_cast<IfExpr1Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << RCcodeParser::EQ)
        | (1ULL << RCcodeParser::GT)
        | (1ULL << RCcodeParser::GE)
        | (1ULL << RCcodeParser::LT)
        | (1ULL << RCcodeParser::LE)
        | (1ULL << RCcodeParser::NE))) != 0))) {
        dynamic_cast<IfExpr1Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(203);
      numorid();
      setState(204);
      match(RCcodeParser::THEN);
      setState(205);
      block();
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == RCcodeParser::ELSEIF) {
        setState(206);
        elseif_stat();
        setState(211);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(213);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == RCcodeParser::ELSE) {
        setState(212);
        else_stat();
      }
      setState(215);
      match(RCcodeParser::ENDIF);
      setState(216);
      match(RCcodeParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<If_statContext *>(_tracker.createInstance<RCcodeParser::IfExpr2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(218);
      match(RCcodeParser::IF);
      setState(219);
      boolval();
      setState(220);
      match(RCcodeParser::THEN);
      setState(221);
      block();
      setState(225);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == RCcodeParser::ELSEIF) {
        setState(222);
        elseif_stat();
        setState(227);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(229);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == RCcodeParser::ELSE) {
        setState(228);
        else_stat();
      }
      setState(231);
      match(RCcodeParser::ENDIF);
      setState(232);
      match(RCcodeParser::T__1);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<If_statContext *>(_tracker.createInstance<RCcodeParser::IfExpr3Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(234);
      match(RCcodeParser::IF);
      setState(235);
      match(RCcodeParser::ID);
      setState(236);
      match(RCcodeParser::THEN);
      setState(237);
      block();
      setState(241);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == RCcodeParser::ELSEIF) {
        setState(238);
        elseif_stat();
        setState(243);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(245);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == RCcodeParser::ELSE) {
        setState(244);
        else_stat();
      }
      setState(247);
      match(RCcodeParser::ENDIF);
      setState(248);
      match(RCcodeParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Elseif_statContext ------------------------------------------------------------------

RCcodeParser::Elseif_statContext::Elseif_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Elseif_statContext::getRuleIndex() const {
  return RCcodeParser::RuleElseif_stat;
}

void RCcodeParser::Elseif_statContext::copyFrom(Elseif_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ElseifExpr1Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::ElseifExpr1Context::ELSEIF() {
  return getToken(RCcodeParser::ELSEIF, 0);
}

std::vector<RCcodeParser::NumoridContext *> RCcodeParser::ElseifExpr1Context::numorid() {
  return getRuleContexts<RCcodeParser::NumoridContext>();
}

RCcodeParser::NumoridContext* RCcodeParser::ElseifExpr1Context::numorid(size_t i) {
  return getRuleContext<RCcodeParser::NumoridContext>(i);
}

tree::TerminalNode* RCcodeParser::ElseifExpr1Context::THEN() {
  return getToken(RCcodeParser::THEN, 0);
}

RCcodeParser::BlockContext* RCcodeParser::ElseifExpr1Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr1Context::EQ() {
  return getToken(RCcodeParser::EQ, 0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr1Context::GE() {
  return getToken(RCcodeParser::GE, 0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr1Context::LE() {
  return getToken(RCcodeParser::LE, 0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr1Context::LT() {
  return getToken(RCcodeParser::LT, 0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr1Context::GT() {
  return getToken(RCcodeParser::GT, 0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr1Context::NE() {
  return getToken(RCcodeParser::NE, 0);
}

RCcodeParser::ElseifExpr1Context::ElseifExpr1Context(Elseif_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ElseifExpr1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitElseifExpr1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ElseifExpr2Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::ElseifExpr2Context::ELSEIF() {
  return getToken(RCcodeParser::ELSEIF, 0);
}

RCcodeParser::BoolvalContext* RCcodeParser::ElseifExpr2Context::boolval() {
  return getRuleContext<RCcodeParser::BoolvalContext>(0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr2Context::THEN() {
  return getToken(RCcodeParser::THEN, 0);
}

RCcodeParser::BlockContext* RCcodeParser::ElseifExpr2Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

RCcodeParser::ElseifExpr2Context::ElseifExpr2Context(Elseif_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ElseifExpr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitElseifExpr2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ElseifExpr3Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::ElseifExpr3Context::ELSEIF() {
  return getToken(RCcodeParser::ELSEIF, 0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr3Context::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::ElseifExpr3Context::THEN() {
  return getToken(RCcodeParser::THEN, 0);
}

RCcodeParser::BlockContext* RCcodeParser::ElseifExpr3Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

RCcodeParser::ElseifExpr3Context::ElseifExpr3Context(Elseif_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ElseifExpr3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitElseifExpr3(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Elseif_statContext* RCcodeParser::elseif_stat() {
  Elseif_statContext *_localctx = _tracker.createInstance<Elseif_statContext>(_ctx, getState());
  enterRule(_localctx, 22, RCcodeParser::RuleElseif_stat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(268);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Elseif_statContext *>(_tracker.createInstance<RCcodeParser::ElseifExpr1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(252);
      match(RCcodeParser::ELSEIF);
      setState(253);
      numorid();
      setState(254);
      dynamic_cast<ElseifExpr1Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << RCcodeParser::EQ)
        | (1ULL << RCcodeParser::GT)
        | (1ULL << RCcodeParser::GE)
        | (1ULL << RCcodeParser::LT)
        | (1ULL << RCcodeParser::LE)
        | (1ULL << RCcodeParser::NE))) != 0))) {
        dynamic_cast<ElseifExpr1Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(255);
      numorid();
      setState(256);
      match(RCcodeParser::THEN);
      setState(257);
      block();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Elseif_statContext *>(_tracker.createInstance<RCcodeParser::ElseifExpr2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(259);
      match(RCcodeParser::ELSEIF);
      setState(260);
      boolval();
      setState(261);
      match(RCcodeParser::THEN);
      setState(262);
      block();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Elseif_statContext *>(_tracker.createInstance<RCcodeParser::ElseifExpr3Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(264);
      match(RCcodeParser::ELSEIF);
      setState(265);
      match(RCcodeParser::ID);
      setState(266);
      match(RCcodeParser::THEN);
      setState(267);
      block();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Else_statContext ------------------------------------------------------------------

RCcodeParser::Else_statContext::Else_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Else_statContext::getRuleIndex() const {
  return RCcodeParser::RuleElse_stat;
}

void RCcodeParser::Else_statContext::copyFrom(Else_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ElseExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::ElseExprContext::ELSE() {
  return getToken(RCcodeParser::ELSE, 0);
}

RCcodeParser::BlockContext* RCcodeParser::ElseExprContext::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

RCcodeParser::ElseExprContext::ElseExprContext(Else_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ElseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitElseExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Else_statContext* RCcodeParser::else_stat() {
  Else_statContext *_localctx = _tracker.createInstance<Else_statContext>(_ctx, getState());
  enterRule(_localctx, 24, RCcodeParser::RuleElse_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<Else_statContext *>(_tracker.createInstance<RCcodeParser::ElseExprContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(270);
    match(RCcodeParser::ELSE);
    setState(271);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_statContext ------------------------------------------------------------------

RCcodeParser::For_statContext::For_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::For_statContext::getRuleIndex() const {
  return RCcodeParser::RuleFor_stat;
}

void RCcodeParser::For_statContext::copyFrom(For_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ForExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::ForExprContext::FOR() {
  return getToken(RCcodeParser::FOR, 0);
}

tree::TerminalNode* RCcodeParser::ForExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::ForExprContext::ASSIGN() {
  return getToken(RCcodeParser::ASSIGN, 0);
}

std::vector<tree::TerminalNode *> RCcodeParser::ForExprContext::NUM() {
  return getTokens(RCcodeParser::NUM);
}

tree::TerminalNode* RCcodeParser::ForExprContext::NUM(size_t i) {
  return getToken(RCcodeParser::NUM, i);
}

tree::TerminalNode* RCcodeParser::ForExprContext::TO() {
  return getToken(RCcodeParser::TO, 0);
}

tree::TerminalNode* RCcodeParser::ForExprContext::BY() {
  return getToken(RCcodeParser::BY, 0);
}

RCcodeParser::BlockContext* RCcodeParser::ForExprContext::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::ForExprContext::ENDFOR() {
  return getToken(RCcodeParser::ENDFOR, 0);
}

RCcodeParser::ForExprContext::ForExprContext(For_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ForExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitForExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::For_statContext* RCcodeParser::for_stat() {
  For_statContext *_localctx = _tracker.createInstance<For_statContext>(_ctx, getState());
  enterRule(_localctx, 26, RCcodeParser::RuleFor_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<For_statContext *>(_tracker.createInstance<RCcodeParser::ForExprContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(273);
    match(RCcodeParser::FOR);
    setState(274);
    match(RCcodeParser::ID);
    setState(275);
    match(RCcodeParser::ASSIGN);
    setState(276);
    match(RCcodeParser::NUM);
    setState(277);
    match(RCcodeParser::TO);
    setState(278);
    match(RCcodeParser::NUM);
    setState(279);
    match(RCcodeParser::BY);
    setState(280);
    match(RCcodeParser::NUM);
    setState(281);
    block();
    setState(282);
    match(RCcodeParser::ENDFOR);
    setState(283);
    match(RCcodeParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_statContext ------------------------------------------------------------------

RCcodeParser::While_statContext::While_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::While_statContext::getRuleIndex() const {
  return RCcodeParser::RuleWhile_stat;
}

void RCcodeParser::While_statContext::copyFrom(While_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WhileExpr2Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::WhileExpr2Context::WHILE() {
  return getToken(RCcodeParser::WHILE, 0);
}

RCcodeParser::BoolvalContext* RCcodeParser::WhileExpr2Context::boolval() {
  return getRuleContext<RCcodeParser::BoolvalContext>(0);
}

tree::TerminalNode* RCcodeParser::WhileExpr2Context::DO() {
  return getToken(RCcodeParser::DO, 0);
}

RCcodeParser::BlockContext* RCcodeParser::WhileExpr2Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::WhileExpr2Context::ENDWL() {
  return getToken(RCcodeParser::ENDWL, 0);
}

RCcodeParser::WhileExpr2Context::WhileExpr2Context(While_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::WhileExpr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitWhileExpr2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileExpr3Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::WhileExpr3Context::WHILE() {
  return getToken(RCcodeParser::WHILE, 0);
}

tree::TerminalNode* RCcodeParser::WhileExpr3Context::ID() {
  return getToken(RCcodeParser::ID, 0);
}

tree::TerminalNode* RCcodeParser::WhileExpr3Context::DO() {
  return getToken(RCcodeParser::DO, 0);
}

RCcodeParser::BlockContext* RCcodeParser::WhileExpr3Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::WhileExpr3Context::ENDWL() {
  return getToken(RCcodeParser::ENDWL, 0);
}

RCcodeParser::WhileExpr3Context::WhileExpr3Context(While_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::WhileExpr3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitWhileExpr3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileExpr1Context ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::WhileExpr1Context::WHILE() {
  return getToken(RCcodeParser::WHILE, 0);
}

std::vector<RCcodeParser::NumoridContext *> RCcodeParser::WhileExpr1Context::numorid() {
  return getRuleContexts<RCcodeParser::NumoridContext>();
}

RCcodeParser::NumoridContext* RCcodeParser::WhileExpr1Context::numorid(size_t i) {
  return getRuleContext<RCcodeParser::NumoridContext>(i);
}

tree::TerminalNode* RCcodeParser::WhileExpr1Context::DO() {
  return getToken(RCcodeParser::DO, 0);
}

RCcodeParser::BlockContext* RCcodeParser::WhileExpr1Context::block() {
  return getRuleContext<RCcodeParser::BlockContext>(0);
}

tree::TerminalNode* RCcodeParser::WhileExpr1Context::ENDWL() {
  return getToken(RCcodeParser::ENDWL, 0);
}

tree::TerminalNode* RCcodeParser::WhileExpr1Context::EQ() {
  return getToken(RCcodeParser::EQ, 0);
}

tree::TerminalNode* RCcodeParser::WhileExpr1Context::GE() {
  return getToken(RCcodeParser::GE, 0);
}

tree::TerminalNode* RCcodeParser::WhileExpr1Context::LE() {
  return getToken(RCcodeParser::LE, 0);
}

tree::TerminalNode* RCcodeParser::WhileExpr1Context::LT() {
  return getToken(RCcodeParser::LT, 0);
}

tree::TerminalNode* RCcodeParser::WhileExpr1Context::GT() {
  return getToken(RCcodeParser::GT, 0);
}

tree::TerminalNode* RCcodeParser::WhileExpr1Context::NE() {
  return getToken(RCcodeParser::NE, 0);
}

RCcodeParser::WhileExpr1Context::WhileExpr1Context(While_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::WhileExpr1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitWhileExpr1(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::While_statContext* RCcodeParser::while_stat() {
  While_statContext *_localctx = _tracker.createInstance<While_statContext>(_ctx, getState());
  enterRule(_localctx, 28, RCcodeParser::RuleWhile_stat);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(308);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<While_statContext *>(_tracker.createInstance<RCcodeParser::WhileExpr1Context>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(285);
      match(RCcodeParser::WHILE);
      setState(286);
      numorid();
      setState(287);
      dynamic_cast<WhileExpr1Context *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << RCcodeParser::EQ)
        | (1ULL << RCcodeParser::GT)
        | (1ULL << RCcodeParser::GE)
        | (1ULL << RCcodeParser::LT)
        | (1ULL << RCcodeParser::LE)
        | (1ULL << RCcodeParser::NE))) != 0))) {
        dynamic_cast<WhileExpr1Context *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(288);
      numorid();
      setState(289);
      match(RCcodeParser::DO);
      setState(290);
      block();
      setState(291);
      match(RCcodeParser::ENDWL);
      setState(292);
      match(RCcodeParser::T__1);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<While_statContext *>(_tracker.createInstance<RCcodeParser::WhileExpr2Context>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(294);
      match(RCcodeParser::WHILE);
      setState(295);
      boolval();
      setState(296);
      match(RCcodeParser::DO);
      setState(297);
      block();
      setState(298);
      match(RCcodeParser::ENDWL);
      setState(299);
      match(RCcodeParser::T__1);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<While_statContext *>(_tracker.createInstance<RCcodeParser::WhileExpr3Context>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(301);
      match(RCcodeParser::WHILE);
      setState(302);
      match(RCcodeParser::ID);
      setState(303);
      match(RCcodeParser::DO);
      setState(304);
      block();
      setState(305);
      match(RCcodeParser::ENDWL);
      setState(306);
      match(RCcodeParser::T__1);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BoolvalContext ------------------------------------------------------------------

RCcodeParser::BoolvalContext::BoolvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::BoolvalContext::getRuleIndex() const {
  return RCcodeParser::RuleBoolval;
}

void RCcodeParser::BoolvalContext::copyFrom(BoolvalContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FalseExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::FalseExprContext::FALSE() {
  return getToken(RCcodeParser::FALSE, 0);
}

RCcodeParser::FalseExprContext::FalseExprContext(BoolvalContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::FalseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitFalseExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrueExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::TrueExprContext::TRUE() {
  return getToken(RCcodeParser::TRUE, 0);
}

RCcodeParser::TrueExprContext::TrueExprContext(BoolvalContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::TrueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitTrueExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::BoolvalContext* RCcodeParser::boolval() {
  BoolvalContext *_localctx = _tracker.createInstance<BoolvalContext>(_ctx, getState());
  enterRule(_localctx, 30, RCcodeParser::RuleBoolval);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(312);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RCcodeParser::TRUE: {
        _localctx = dynamic_cast<BoolvalContext *>(_tracker.createInstance<RCcodeParser::TrueExprContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(310);
        match(RCcodeParser::TRUE);
        break;
      }

      case RCcodeParser::FALSE: {
        _localctx = dynamic_cast<BoolvalContext *>(_tracker.createInstance<RCcodeParser::FalseExprContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(311);
        match(RCcodeParser::FALSE);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Libcall_statContext ------------------------------------------------------------------

RCcodeParser::Libcall_statContext::Libcall_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Libcall_statContext::getRuleIndex() const {
  return RCcodeParser::RuleLibcall_stat;
}

void RCcodeParser::Libcall_statContext::copyFrom(Libcall_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LibcallExprContext ------------------------------------------------------------------

RCcodeParser::FuncallexprContext* RCcodeParser::LibcallExprContext::funcallexpr() {
  return getRuleContext<RCcodeParser::FuncallexprContext>(0);
}

RCcodeParser::LibcallExprContext::LibcallExprContext(Libcall_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::LibcallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitLibcallExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Libcall_statContext* RCcodeParser::libcall_stat() {
  Libcall_statContext *_localctx = _tracker.createInstance<Libcall_statContext>(_ctx, getState());
  enterRule(_localctx, 32, RCcodeParser::RuleLibcall_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<Libcall_statContext *>(_tracker.createInstance<RCcodeParser::LibcallExprContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(314);
    funcallexpr();
    setState(315);
    match(RCcodeParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncallexprContext ------------------------------------------------------------------

RCcodeParser::FuncallexprContext::FuncallexprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::FuncallexprContext::getRuleIndex() const {
  return RCcodeParser::RuleFuncallexpr;
}

void RCcodeParser::FuncallexprContext::copyFrom(FuncallexprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FuncallExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::FuncallExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

RCcodeParser::ParamsContext* RCcodeParser::FuncallExprContext::params() {
  return getRuleContext<RCcodeParser::ParamsContext>(0);
}

RCcodeParser::FuncallExprContext::FuncallExprContext(FuncallexprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::FuncallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitFuncallExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::FuncallexprContext* RCcodeParser::funcallexpr() {
  FuncallexprContext *_localctx = _tracker.createInstance<FuncallexprContext>(_ctx, getState());
  enterRule(_localctx, 34, RCcodeParser::RuleFuncallexpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<FuncallexprContext *>(_tracker.createInstance<RCcodeParser::FuncallExprContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(317);
    match(RCcodeParser::ID);
    setState(318);
    match(RCcodeParser::T__2);
    setState(319);
    params();
    setState(320);
    match(RCcodeParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

RCcodeParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::ParamsContext::getRuleIndex() const {
  return RCcodeParser::RuleParams;
}

void RCcodeParser::ParamsContext::copyFrom(ParamsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParamlistContext ------------------------------------------------------------------

std::vector<RCcodeParser::NumoridContext *> RCcodeParser::ParamlistContext::numorid() {
  return getRuleContexts<RCcodeParser::NumoridContext>();
}

RCcodeParser::NumoridContext* RCcodeParser::ParamlistContext::numorid(size_t i) {
  return getRuleContext<RCcodeParser::NumoridContext>(i);
}

RCcodeParser::ParamlistContext::ParamlistContext(ParamsContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::ParamlistContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitParamlist(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::ParamsContext* RCcodeParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 36, RCcodeParser::RuleParams);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<ParamsContext *>(_tracker.createInstance<RCcodeParser::ParamlistContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(323);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RCcodeParser::ID

    || _la == RCcodeParser::NUM) {
      setState(322);
      numorid();
    }
    setState(329);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RCcodeParser::T__0) {
      setState(325);
      match(RCcodeParser::T__0);
      setState(326);
      numorid();
      setState(331);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumoridContext ------------------------------------------------------------------

RCcodeParser::NumoridContext::NumoridContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::NumoridContext::getRuleIndex() const {
  return RCcodeParser::RuleNumorid;
}

void RCcodeParser::NumoridContext::copyFrom(NumoridContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::NumExprContext::NUM() {
  return getToken(RCcodeParser::NUM, 0);
}

RCcodeParser::NumExprContext::NumExprContext(NumoridContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::NumExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitNumExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::IdExprContext::ID() {
  return getToken(RCcodeParser::ID, 0);
}

RCcodeParser::IdExprContext::IdExprContext(NumoridContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitIdExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::NumoridContext* RCcodeParser::numorid() {
  NumoridContext *_localctx = _tracker.createInstance<NumoridContext>(_ctx, getState());
  enterRule(_localctx, 38, RCcodeParser::RuleNumorid);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(334);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RCcodeParser::NUM: {
        _localctx = dynamic_cast<NumoridContext *>(_tracker.createInstance<RCcodeParser::NumExprContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(332);
        match(RCcodeParser::NUM);
        break;
      }

      case RCcodeParser::ID: {
        _localctx = dynamic_cast<NumoridContext *>(_tracker.createInstance<RCcodeParser::IdExprContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(333);
        match(RCcodeParser::ID);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Oneinst_statContext ------------------------------------------------------------------

RCcodeParser::Oneinst_statContext::Oneinst_statContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::Oneinst_statContext::getRuleIndex() const {
  return RCcodeParser::RuleOneinst_stat;
}

void RCcodeParser::Oneinst_statContext::copyFrom(Oneinst_statContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OneinstExprContext ------------------------------------------------------------------

RCcodeParser::OneinstContext* RCcodeParser::OneinstExprContext::oneinst() {
  return getRuleContext<RCcodeParser::OneinstContext>(0);
}

RCcodeParser::OneinstExprContext::OneinstExprContext(Oneinst_statContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::OneinstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitOneinstExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::Oneinst_statContext* RCcodeParser::oneinst_stat() {
  Oneinst_statContext *_localctx = _tracker.createInstance<Oneinst_statContext>(_ctx, getState());
  enterRule(_localctx, 40, RCcodeParser::RuleOneinst_stat);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    _localctx = dynamic_cast<Oneinst_statContext *>(_tracker.createInstance<RCcodeParser::OneinstExprContext>(_localctx));
    enterOuterAlt(_localctx, 1);
    setState(336);
    oneinst();
    setState(337);
    match(RCcodeParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OneinstContext ------------------------------------------------------------------

RCcodeParser::OneinstContext::OneinstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t RCcodeParser::OneinstContext::getRuleIndex() const {
  return RCcodeParser::RuleOneinst;
}

void RCcodeParser::OneinstContext::copyFrom(OneinstContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NopExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::NopExprContext::NOP() {
  return getToken(RCcodeParser::NOP, 0);
}

RCcodeParser::NopExprContext::NopExprContext(OneinstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::NopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitNopExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- HaltExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::HaltExprContext::HALT() {
  return getToken(RCcodeParser::HALT, 0);
}

RCcodeParser::HaltExprContext::HaltExprContext(OneinstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::HaltExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitHaltExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RetExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::RetExprContext::RET() {
  return getToken(RCcodeParser::RET, 0);
}

RCcodeParser::RetExprContext::RetExprContext(OneinstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::RetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitRetExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PauseExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::PauseExprContext::PAUSE() {
  return getToken(RCcodeParser::PAUSE, 0);
}

RCcodeParser::PauseExprContext::PauseExprContext(OneinstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::PauseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitPauseExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LabelExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::LabelExprContext::LABEL() {
  return getToken(RCcodeParser::LABEL, 0);
}

RCcodeParser::LabelExprContext::LabelExprContext(OneinstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::LabelExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitLabelExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakExprContext ------------------------------------------------------------------

tree::TerminalNode* RCcodeParser::BreakExprContext::BREAK() {
  return getToken(RCcodeParser::BREAK, 0);
}

RCcodeParser::BreakExprContext::BreakExprContext(OneinstContext *ctx) { copyFrom(ctx); }

antlrcpp::Any RCcodeParser::BreakExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RCcodeVisitor*>(visitor))
    return parserVisitor->visitBreakExpr(this);
  else
    return visitor->visitChildren(this);
}
RCcodeParser::OneinstContext* RCcodeParser::oneinst() {
  OneinstContext *_localctx = _tracker.createInstance<OneinstContext>(_ctx, getState());
  enterRule(_localctx, 42, RCcodeParser::RuleOneinst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RCcodeParser::LABEL: {
        _localctx = dynamic_cast<OneinstContext *>(_tracker.createInstance<RCcodeParser::LabelExprContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(339);
        match(RCcodeParser::LABEL);
        break;
      }

      case RCcodeParser::RET: {
        _localctx = dynamic_cast<OneinstContext *>(_tracker.createInstance<RCcodeParser::RetExprContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(340);
        match(RCcodeParser::RET);
        break;
      }

      case RCcodeParser::NOP: {
        _localctx = dynamic_cast<OneinstContext *>(_tracker.createInstance<RCcodeParser::NopExprContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(341);
        match(RCcodeParser::NOP);
        break;
      }

      case RCcodeParser::PAUSE: {
        _localctx = dynamic_cast<OneinstContext *>(_tracker.createInstance<RCcodeParser::PauseExprContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(342);
        match(RCcodeParser::PAUSE);
        break;
      }

      case RCcodeParser::HALT: {
        _localctx = dynamic_cast<OneinstContext *>(_tracker.createInstance<RCcodeParser::HaltExprContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(343);
        match(RCcodeParser::HALT);
        break;
      }

      case RCcodeParser::BREAK: {
        _localctx = dynamic_cast<OneinstContext *>(_tracker.createInstance<RCcodeParser::BreakExprContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(344);
        match(RCcodeParser::BREAK);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> RCcodeParser::_decisionToDFA;
atn::PredictionContextCache RCcodeParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN RCcodeParser::_atn;
std::vector<uint16_t> RCcodeParser::_serializedATN;

std::vector<std::string> RCcodeParser::_ruleNames = {
  "prog", "block", "stat", "robot_stat", "data_stat", "signal_stat", "math_stat", 
  "call_stat", "assign_stat", "goto_stat", "if_stat", "elseif_stat", "else_stat", 
  "for_stat", "while_stat", "boolval", "libcall_stat", "funcallexpr", "params", 
  "numorid", "oneinst_stat", "oneinst"
};

std::vector<std::string> RCcodeParser::_literalNames = {
  "", "','", "';'", "'('", "')'", "'GOTO'", "'IF'", "'THEN'", "'ELSEIF'", 
  "'ELSE'", "'ENDIF'", "'='", "'WHILE'", "'DO'", "'ENDWL'", "'FOR'", "'TO'", 
  "'BY'", "'ENDFOR'", "'TRUE'", "'FALSE'", "'MOVJ'", "'MOVL'", "'MOVC'", 
  "'MOVS'", "'SHIFTON'", "'SHIFTOFF'", "'SET'", "'SETE'", "'GETE'", "'WAIT'", 
  "'DELAY'", "'SETOUT'", "'DIN'", "", "'RET'", "'NOP'", "'PAUSE'", "'HALT'", 
  "'BREAK'", "'INCR'", "'DECR'", "'CALL'", "'=='", "'>'", "'>='", "'<'", 
  "'<='", "'<>'", "'+'", "'-'", "'*'", "'/'"
};

std::vector<std::string> RCcodeParser::_symbolicNames = {
  "", "", "", "", "", "GOTO", "IF", "THEN", "ELSEIF", "ELSE", "ENDIF", "ASSIGN", 
  "WHILE", "DO", "ENDWL", "FOR", "TO", "BY", "ENDFOR", "TRUE", "FALSE", 
  "MOVJ", "MOVL", "MOVC", "MOVS", "SHIFTON", "SHIFTOFF", "SET", "SETE", 
  "GETE", "WAIT", "DELAY", "SETOUT", "DIN", "LABEL", "RET", "NOP", "PAUSE", 
  "HALT", "BREAK", "INCR", "DECR", "CALL", "EQ", "GT", "GE", "LT", "LE", 
  "NE", "ADD", "SUB", "MUL", "DIV", "FUNC", "TIME", "ELEM", "CSTRING", "CH", 
  "ID", "NUM", "COMMENT", "SPACE", "OTHER"
};

dfa::Vocabulary RCcodeParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> RCcodeParser::_tokenNames;

RCcodeParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x430, 0xd6d1, 0x8206, 0xad2d, 0x4417, 0xaef1, 0x8d80, 0xaadd, 
    0x3, 0x40, 0x15e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x7, 0x3, 0x33, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x36, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x44, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x6d, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x7e, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x86, 0xa, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x98, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0xa5, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xc5, 
    0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xd2, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0xd5, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0xd8, 0xa, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x7, 0xc, 0xe2, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xe5, 0xb, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0xe8, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xf2, 0xa, 
    0xc, 0xc, 0xc, 0xe, 0xc, 0xf5, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0xf8, 0xa, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xfd, 0xa, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0x10f, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x5, 0x10, 0x137, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 
    0x13b, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x5, 0x14, 0x146, 0xa, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x14a, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0x14d, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x151, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x15c, 0xa, 0x17, 0x3, 0x17, 
    0x2, 0x2, 0x18, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2, 0x6, 0x3, 0x2, 0x2d, 0x32, 0x4, 0x2, 0x39, 0x39, 0x3c, 0x3c, 0x4, 
    0x2, 0x39, 0x39, 0x3c, 0x3d, 0x3, 0x2, 0x2d, 0x36, 0x179, 0x2, 0x2e, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x34, 0x3, 0x2, 0x2, 0x2, 0x6, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x6c, 0x3, 0x2, 0x2, 0x2, 0xa, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x97, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0x12, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x14, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x18, 0x10e, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x110, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x136, 0x3, 0x2, 0x2, 0x2, 0x20, 0x13a, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x24, 0x13f, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x145, 0x3, 0x2, 0x2, 0x2, 0x28, 0x150, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x152, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 
    0x5, 0x4, 0x3, 0x2, 0x2f, 0x30, 0x7, 0x2, 0x2, 0x3, 0x30, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x33, 0x5, 0x6, 0x4, 0x2, 0x32, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x44, 0x5, 0x8, 0x5, 0x2, 0x38, 
    0x44, 0x5, 0xa, 0x6, 0x2, 0x39, 0x44, 0x5, 0xc, 0x7, 0x2, 0x3a, 0x44, 
    0x5, 0xe, 0x8, 0x2, 0x3b, 0x44, 0x5, 0x2a, 0x16, 0x2, 0x3c, 0x44, 0x5, 
    0x12, 0xa, 0x2, 0x3d, 0x44, 0x5, 0x14, 0xb, 0x2, 0x3e, 0x44, 0x5, 0x16, 
    0xc, 0x2, 0x3f, 0x44, 0x5, 0x1c, 0xf, 0x2, 0x40, 0x44, 0x5, 0x1e, 0x10, 
    0x2, 0x41, 0x44, 0x5, 0x22, 0x12, 0x2, 0x42, 0x44, 0x5, 0x10, 0x9, 0x2, 
    0x43, 0x37, 0x3, 0x2, 0x2, 0x2, 0x43, 0x38, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x43, 0x40, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x43, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x45, 0x46, 0x7, 0x17, 0x2, 0x2, 0x46, 0x47, 0x7, 0x3c, 0x2, 0x2, 0x47, 
    0x48, 0x7, 0x3, 0x2, 0x2, 0x48, 0x49, 0x7, 0x3c, 0x2, 0x2, 0x49, 0x4a, 
    0x7, 0x3, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x3c, 0x2, 0x2, 0x4b, 0x6d, 0x7, 
    0x4, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x18, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x3c, 
    0x2, 0x2, 0x4e, 0x4f, 0x7, 0x3, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x3c, 0x2, 
    0x2, 0x50, 0x51, 0x7, 0x3, 0x2, 0x2, 0x51, 0x52, 0x7, 0x3c, 0x2, 0x2, 
    0x52, 0x6d, 0x7, 0x4, 0x2, 0x2, 0x53, 0x54, 0x7, 0x19, 0x2, 0x2, 0x54, 
    0x55, 0x7, 0x3c, 0x2, 0x2, 0x55, 0x56, 0x7, 0x3, 0x2, 0x2, 0x56, 0x57, 
    0x7, 0x3c, 0x2, 0x2, 0x57, 0x58, 0x7, 0x3, 0x2, 0x2, 0x58, 0x59, 0x7, 
    0x3c, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x3, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x3c, 
    0x2, 0x2, 0x5b, 0x6d, 0x7, 0x4, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x1a, 0x2, 
    0x2, 0x5d, 0x5e, 0x7, 0x3c, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x3, 0x2, 0x2, 
    0x5f, 0x60, 0x7, 0x3c, 0x2, 0x2, 0x60, 0x61, 0x7, 0x3, 0x2, 0x2, 0x61, 
    0x62, 0x7, 0x3c, 0x2, 0x2, 0x62, 0x63, 0x7, 0x3, 0x2, 0x2, 0x63, 0x64, 
    0x7, 0x3c, 0x2, 0x2, 0x64, 0x6d, 0x7, 0x4, 0x2, 0x2, 0x65, 0x66, 0x7, 
    0x1b, 0x2, 0x2, 0x66, 0x67, 0x7, 0x3c, 0x2, 0x2, 0x67, 0x68, 0x7, 0x3, 
    0x2, 0x2, 0x68, 0x69, 0x7, 0x3c, 0x2, 0x2, 0x69, 0x6d, 0x7, 0x4, 0x2, 
    0x2, 0x6a, 0x6b, 0x7, 0x1c, 0x2, 0x2, 0x6b, 0x6d, 0x7, 0x4, 0x2, 0x2, 
    0x6c, 0x45, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x6c, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x1d, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x3c, 
    0x2, 0x2, 0x70, 0x71, 0x7, 0x3, 0x2, 0x2, 0x71, 0x72, 0x7, 0x3c, 0x2, 
    0x2, 0x72, 0x7e, 0x7, 0x4, 0x2, 0x2, 0x73, 0x74, 0x7, 0x1e, 0x2, 0x2, 
    0x74, 0x75, 0x7, 0x39, 0x2, 0x2, 0x75, 0x76, 0x7, 0x3, 0x2, 0x2, 0x76, 
    0x77, 0x7, 0x3c, 0x2, 0x2, 0x77, 0x7e, 0x7, 0x4, 0x2, 0x2, 0x78, 0x79, 
    0x7, 0x1f, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x3c, 0x2, 0x2, 0x7a, 0x7b, 0x7, 
    0x3, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x39, 0x2, 0x2, 0x7c, 0x7e, 0x7, 0x4, 
    0x2, 0x2, 0x7d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x7d, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7e, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x80, 0x7, 0x20, 0x2, 0x2, 0x80, 0x81, 0x7, 0x3c, 0x2, 0x2, 0x81, 
    0x82, 0x9, 0x2, 0x2, 0x2, 0x82, 0x85, 0x5, 0x28, 0x15, 0x2, 0x83, 0x84, 
    0x7, 0x3, 0x2, 0x2, 0x84, 0x86, 0x7, 0x38, 0x2, 0x2, 0x85, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x87, 0x88, 0x7, 0x4, 0x2, 0x2, 0x88, 0x98, 0x3, 0x2, 0x2, 
    0x2, 0x89, 0x8a, 0x7, 0x21, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x38, 0x2, 0x2, 
    0x8b, 0x98, 0x7, 0x4, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x22, 0x2, 0x2, 0x8d, 
    0x8e, 0x7, 0x3c, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x3, 0x2, 0x2, 0x8f, 0x90, 
    0x5, 0x28, 0x15, 0x2, 0x90, 0x91, 0x7, 0x4, 0x2, 0x2, 0x91, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x23, 0x2, 0x2, 0x93, 0x94, 0x7, 0x3c, 
    0x2, 0x2, 0x94, 0x95, 0x7, 0x3, 0x2, 0x2, 0x95, 0x96, 0x7, 0x3c, 0x2, 
    0x2, 0x96, 0x98, 0x7, 0x4, 0x2, 0x2, 0x97, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x89, 0x3, 0x2, 0x2, 0x2, 0x97, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x98, 0xd, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 
    0x7, 0x2a, 0x2, 0x2, 0x9a, 0x9b, 0x7, 0x3c, 0x2, 0x2, 0x9b, 0xa5, 0x7, 
    0x4, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x2b, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x3c, 
    0x2, 0x2, 0x9e, 0xa5, 0x7, 0x4, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x37, 0x2, 
    0x2, 0xa0, 0xa1, 0x9, 0x3, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x3, 0x2, 0x2, 
    0xa2, 0xa3, 0x9, 0x4, 0x2, 0x2, 0xa3, 0xa5, 0x7, 0x4, 0x2, 0x2, 0xa4, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 
    0x2c, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x3c, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x4, 
    0x2, 0x2, 0xa9, 0x11, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x3c, 0x2, 
    0x2, 0xab, 0xac, 0x7, 0xd, 0x2, 0x2, 0xac, 0xad, 0x5, 0x20, 0x11, 0x2, 
    0xad, 0xae, 0x7, 0x4, 0x2, 0x2, 0xae, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb0, 0x7, 0x3c, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0xd, 0x2, 0x2, 0xb1, 0xb2, 
    0x5, 0x28, 0x15, 0x2, 0xb2, 0xb3, 0x9, 0x5, 0x2, 0x2, 0xb3, 0xb4, 0x5, 
    0x28, 0x15, 0x2, 0xb4, 0xb5, 0x7, 0x4, 0x2, 0x2, 0xb5, 0xc5, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb7, 0x7, 0x3c, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0xd, 0x2, 
    0x2, 0xb8, 0xb9, 0x5, 0x24, 0x13, 0x2, 0xb9, 0xba, 0x7, 0x4, 0x2, 0x2, 
    0xba, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x3c, 0x2, 0x2, 0xbc, 
    0xbd, 0x7, 0xd, 0x2, 0x2, 0xbd, 0xbe, 0x5, 0x28, 0x15, 0x2, 0xbe, 0xbf, 
    0x7, 0x4, 0x2, 0x2, 0xbf, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x7, 
    0x3c, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0xd, 0x2, 0x2, 0xc2, 0xc3, 0x7, 0x3a, 
    0x2, 0x2, 0xc3, 0xc5, 0x7, 0x4, 0x2, 0x2, 0xc4, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0xc4, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xb6, 0x3, 0x2, 0x2, 0x2, 
    0xc4, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x7, 0x2, 0x2, 0xc7, 0xc8, 
    0x7, 0x24, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x4, 0x2, 0x2, 0xc9, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x8, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x28, 
    0x15, 0x2, 0xcc, 0xcd, 0x9, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x28, 0x15, 
    0x2, 0xce, 0xcf, 0x7, 0x9, 0x2, 0x2, 0xcf, 0xd3, 0x5, 0x4, 0x3, 0x2, 
    0xd0, 0xd2, 0x5, 0x18, 0xd, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 
    0xd5, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 
    0x2, 0x2, 0x2, 0xd6, 0xd8, 0x5, 0x1a, 0xe, 0x2, 0xd7, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 0x2, 
    0x2, 0xd9, 0xda, 0x7, 0xc, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x4, 0x2, 0x2, 
    0xdb, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x8, 0x2, 0x2, 0xdd, 
    0xde, 0x5, 0x20, 0x11, 0x2, 0xde, 0xdf, 0x7, 0x9, 0x2, 0x2, 0xdf, 0xe3, 
    0x5, 0x4, 0x3, 0x2, 0xe0, 0xe2, 0x5, 0x18, 0xd, 0x2, 0xe1, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 
    0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 
    0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe8, 0x5, 0x1a, 0xe, 0x2, 
    0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 
    0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x7, 0xc, 0x2, 0x2, 0xea, 0xeb, 
    0x7, 0x4, 0x2, 0x2, 0xeb, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 
    0x8, 0x2, 0x2, 0xed, 0xee, 0x7, 0x3c, 0x2, 0x2, 0xee, 0xef, 0x7, 0x9, 
    0x2, 0x2, 0xef, 0xf3, 0x5, 0x4, 0x3, 0x2, 0xf0, 0xf2, 0x5, 0x18, 0xd, 
    0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x3, 0x2, 0x2, 0x2, 
    0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf8, 
    0x5, 0x1a, 0xe, 0x2, 0xf7, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0xc, 
    0x2, 0x2, 0xfa, 0xfb, 0x7, 0x4, 0x2, 0x2, 0xfb, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0xfc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xdc, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xec, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x17, 0x3, 0x2, 0x2, 0x2, 0xfe, 
    0xff, 0x7, 0xa, 0x2, 0x2, 0xff, 0x100, 0x5, 0x28, 0x15, 0x2, 0x100, 
    0x101, 0x9, 0x2, 0x2, 0x2, 0x101, 0x102, 0x5, 0x28, 0x15, 0x2, 0x102, 
    0x103, 0x7, 0x9, 0x2, 0x2, 0x103, 0x104, 0x5, 0x4, 0x3, 0x2, 0x104, 
    0x10f, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x7, 0xa, 0x2, 0x2, 0x106, 
    0x107, 0x5, 0x20, 0x11, 0x2, 0x107, 0x108, 0x7, 0x9, 0x2, 0x2, 0x108, 
    0x109, 0x5, 0x4, 0x3, 0x2, 0x109, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10a, 
    0x10b, 0x7, 0xa, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x3c, 0x2, 0x2, 0x10c, 
    0x10d, 0x7, 0x9, 0x2, 0x2, 0x10d, 0x10f, 0x5, 0x4, 0x3, 0x2, 0x10e, 
    0xfe, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x105, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10a, 
    0x3, 0x2, 0x2, 0x2, 0x10f, 0x19, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x7, 
    0xb, 0x2, 0x2, 0x111, 0x112, 0x5, 0x4, 0x3, 0x2, 0x112, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x113, 0x114, 0x7, 0x11, 0x2, 0x2, 0x114, 0x115, 0x7, 0x3c, 
    0x2, 0x2, 0x115, 0x116, 0x7, 0xd, 0x2, 0x2, 0x116, 0x117, 0x7, 0x3d, 
    0x2, 0x2, 0x117, 0x118, 0x7, 0x12, 0x2, 0x2, 0x118, 0x119, 0x7, 0x3d, 
    0x2, 0x2, 0x119, 0x11a, 0x7, 0x13, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x3d, 
    0x2, 0x2, 0x11b, 0x11c, 0x5, 0x4, 0x3, 0x2, 0x11c, 0x11d, 0x7, 0x14, 
    0x2, 0x2, 0x11d, 0x11e, 0x7, 0x4, 0x2, 0x2, 0x11e, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x11f, 0x120, 0x7, 0xe, 0x2, 0x2, 0x120, 0x121, 0x5, 0x28, 0x15, 
    0x2, 0x121, 0x122, 0x9, 0x2, 0x2, 0x2, 0x122, 0x123, 0x5, 0x28, 0x15, 
    0x2, 0x123, 0x124, 0x7, 0xf, 0x2, 0x2, 0x124, 0x125, 0x5, 0x4, 0x3, 
    0x2, 0x125, 0x126, 0x7, 0x10, 0x2, 0x2, 0x126, 0x127, 0x7, 0x4, 0x2, 
    0x2, 0x127, 0x137, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x7, 0xe, 0x2, 
    0x2, 0x129, 0x12a, 0x5, 0x20, 0x11, 0x2, 0x12a, 0x12b, 0x7, 0xf, 0x2, 
    0x2, 0x12b, 0x12c, 0x5, 0x4, 0x3, 0x2, 0x12c, 0x12d, 0x7, 0x10, 0x2, 
    0x2, 0x12d, 0x12e, 0x7, 0x4, 0x2, 0x2, 0x12e, 0x137, 0x3, 0x2, 0x2, 
    0x2, 0x12f, 0x130, 0x7, 0xe, 0x2, 0x2, 0x130, 0x131, 0x7, 0x3c, 0x2, 
    0x2, 0x131, 0x132, 0x7, 0xf, 0x2, 0x2, 0x132, 0x133, 0x5, 0x4, 0x3, 
    0x2, 0x133, 0x134, 0x7, 0x10, 0x2, 0x2, 0x134, 0x135, 0x7, 0x4, 0x2, 
    0x2, 0x135, 0x137, 0x3, 0x2, 0x2, 0x2, 0x136, 0x11f, 0x3, 0x2, 0x2, 
    0x2, 0x136, 0x128, 0x3, 0x2, 0x2, 0x2, 0x136, 0x12f, 0x3, 0x2, 0x2, 
    0x2, 0x137, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 0x7, 0x15, 0x2, 
    0x2, 0x139, 0x13b, 0x7, 0x16, 0x2, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 
    0x2, 0x13a, 0x139, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13d, 0x5, 0x24, 0x13, 0x2, 0x13d, 0x13e, 0x7, 0x4, 0x2, 0x2, 
    0x13e, 0x23, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x7, 0x3c, 0x2, 0x2, 
    0x140, 0x141, 0x7, 0x5, 0x2, 0x2, 0x141, 0x142, 0x5, 0x26, 0x14, 0x2, 
    0x142, 0x143, 0x7, 0x6, 0x2, 0x2, 0x143, 0x25, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x146, 0x5, 0x28, 0x15, 0x2, 0x145, 0x144, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x147, 
    0x148, 0x7, 0x3, 0x2, 0x2, 0x148, 0x14a, 0x5, 0x28, 0x15, 0x2, 0x149, 
    0x147, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14b, 
    0x149, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x151, 
    0x7, 0x3d, 0x2, 0x2, 0x14f, 0x151, 0x7, 0x3c, 0x2, 0x2, 0x150, 0x14e, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x151, 0x29, 0x3, 
    0x2, 0x2, 0x2, 0x152, 0x153, 0x5, 0x2c, 0x17, 0x2, 0x153, 0x154, 0x7, 
    0x4, 0x2, 0x2, 0x154, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x155, 0x15c, 0x7, 0x24, 
    0x2, 0x2, 0x156, 0x15c, 0x7, 0x25, 0x2, 0x2, 0x157, 0x15c, 0x7, 0x26, 
    0x2, 0x2, 0x158, 0x15c, 0x7, 0x27, 0x2, 0x2, 0x159, 0x15c, 0x7, 0x28, 
    0x2, 0x2, 0x15a, 0x15c, 0x7, 0x29, 0x2, 0x2, 0x15b, 0x155, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x156, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 
    0x2, 0x2, 0x15b, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x18, 0x34, 0x43, 0x6c, 0x7d, 0x85, 0x97, 0xa4, 0xc4, 0xd3, 0xd7, 
    0xe3, 0xe7, 0xf3, 0xf7, 0xfc, 0x10e, 0x136, 0x13a, 0x145, 0x14b, 0x150, 
    0x15b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

RCcodeParser::Initializer RCcodeParser::_init;
