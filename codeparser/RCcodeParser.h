
// Generated from RCcode.g by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"




class  RCcodeParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, GOTO = 5, IF = 6, THEN = 7, 
    ELSEIF = 8, ELSE = 9, ENDIF = 10, ASSIGN = 11, WHILE = 12, DO = 13, 
    ENDWL = 14, FOR = 15, TO = 16, BY = 17, ENDFOR = 18, TRUE = 19, FALSE = 20, 
    MOVJ = 21, MOVL = 22, MOVC = 23, MOVS = 24, SHIFTON = 25, SHIFTOFF = 26, 
    SET = 27, SETE = 28, GETE = 29, WAIT = 30, DELAY = 31, SETOUT = 32, 
    DIN = 33, LABEL = 34, RET = 35, NOP = 36, PAUSE = 37, HALT = 38, BREAK = 39, 
    INCR = 40, DECR = 41, CALL = 42, EQ = 43, GT = 44, GE = 45, LT = 46, 
    LE = 47, NE = 48, ADD = 49, SUB = 50, MUL = 51, DIV = 52, FUNC = 53, 
    TIME = 54, ELEM = 55, CSTRING = 56, CH = 57, ID = 58, NUM = 59, COMMENT = 60, 
    SPACE = 61, OTHER = 62
  };

  enum {
    RuleProg = 0, RuleBlock = 1, RuleStat = 2, RuleRobot_stat = 3, RuleData_stat = 4, 
    RuleSignal_stat = 5, RuleMath_stat = 6, RuleCall_stat = 7, RuleAssign_stat = 8, 
    RuleGoto_stat = 9, RuleIf_stat = 10, RuleElseif_stat = 11, RuleElse_stat = 12, 
    RuleFor_stat = 13, RuleWhile_stat = 14, RuleBoolval = 15, RuleLibcall_stat = 16, 
    RuleFuncallexpr = 17, RuleParams = 18, RuleNumorid = 19, RuleOneinst_stat = 20, 
    RuleOneinst = 21
  };

  RCcodeParser(antlr4::TokenStream *input);
  ~RCcodeParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgContext;
  class BlockContext;
  class StatContext;
  class Robot_statContext;
  class Data_statContext;
  class Signal_statContext;
  class Math_statContext;
  class Call_statContext;
  class Assign_statContext;
  class Goto_statContext;
  class If_statContext;
  class Elseif_statContext;
  class Else_statContext;
  class For_statContext;
  class While_statContext;
  class BoolvalContext;
  class Libcall_statContext;
  class FuncallexprContext;
  class ParamsContext;
  class NumoridContext;
  class Oneinst_statContext;
  class OneinstContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ProgContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ProgContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ProgramContext : public ProgContext {
  public:
    ProgramContext(ProgContext *ctx);

    BlockContext *block();
    antlr4::tree::TerminalNode *EOF();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ProgContext* prog();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BlockContext() : antlr4::ParserRuleContext() { }
    void copyFrom(BlockContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StatBlockContext : public BlockContext {
  public:
    StatBlockContext(BlockContext *ctx);

    std::vector<StatContext *> stat();
    StatContext* stat(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BlockContext* block();

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatContext() : antlr4::ParserRuleContext() { }
    void copyFrom(StatContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WhileStatContext : public StatContext {
  public:
    WhileStatContext(StatContext *ctx);

    While_statContext *while_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForStatContext : public StatContext {
  public:
    ForStatContext(StatContext *ctx);

    For_statContext *for_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignStatContext : public StatContext {
  public:
    AssignStatContext(StatContext *ctx);

    Assign_statContext *assign_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GotoStatContext : public StatContext {
  public:
    GotoStatContext(StatContext *ctx);

    Goto_statContext *goto_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MathStatContext : public StatContext {
  public:
    MathStatContext(StatContext *ctx);

    Math_statContext *math_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RobotStatContext : public StatContext {
  public:
    RobotStatContext(StatContext *ctx);

    Robot_statContext *robot_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfStatContext : public StatContext {
  public:
    IfStatContext(StatContext *ctx);

    If_statContext *if_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DataStatContext : public StatContext {
  public:
    DataStatContext(StatContext *ctx);

    Data_statContext *data_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SignalStatContext : public StatContext {
  public:
    SignalStatContext(StatContext *ctx);

    Signal_statContext *signal_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LibcallStatContext : public StatContext {
  public:
    LibcallStatContext(StatContext *ctx);

    Libcall_statContext *libcall_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallStatContext : public StatContext {
  public:
    CallStatContext(StatContext *ctx);

    Call_statContext *call_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OnewordStatContext : public StatContext {
  public:
    OnewordStatContext(StatContext *ctx);

    Oneinst_statContext *oneinst_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatContext* stat();

  class  Robot_statContext : public antlr4::ParserRuleContext {
  public:
    Robot_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Robot_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Robot_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MovlExprContext : public Robot_statContext {
  public:
    MovlExprContext(Robot_statContext *ctx);

    antlr4::tree::TerminalNode *MOVL();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MovcExprContext : public Robot_statContext {
  public:
    MovcExprContext(Robot_statContext *ctx);

    antlr4::tree::TerminalNode *MOVC();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MovjExprContext : public Robot_statContext {
  public:
    MovjExprContext(Robot_statContext *ctx);

    antlr4::tree::TerminalNode *MOVJ();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShiftoffExprContext : public Robot_statContext {
  public:
    ShiftoffExprContext(Robot_statContext *ctx);

    antlr4::tree::TerminalNode *SHIFTOFF();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MovsExprContext : public Robot_statContext {
  public:
    MovsExprContext(Robot_statContext *ctx);

    antlr4::tree::TerminalNode *MOVS();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ShiftonExprContext : public Robot_statContext {
  public:
    ShiftonExprContext(Robot_statContext *ctx);

    antlr4::tree::TerminalNode *SHIFTON();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Robot_statContext* robot_stat();

  class  Data_statContext : public antlr4::ParserRuleContext {
  public:
    Data_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Data_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Data_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SetExprContext : public Data_statContext {
  public:
    SetExprContext(Data_statContext *ctx);

    antlr4::tree::TerminalNode *SET();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SeteExprContext : public Data_statContext {
  public:
    SeteExprContext(Data_statContext *ctx);

    antlr4::tree::TerminalNode *SETE();
    antlr4::tree::TerminalNode *ELEM();
    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GeteExprContext : public Data_statContext {
  public:
    GeteExprContext(Data_statContext *ctx);

    antlr4::tree::TerminalNode *GETE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ELEM();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Data_statContext* data_stat();

  class  Signal_statContext : public antlr4::ParserRuleContext {
  public:
    Signal_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Signal_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Signal_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WaitExprContext : public Signal_statContext {
  public:
    WaitExprContext(Signal_statContext *ctx);

    antlr4::Token *op = nullptr;
    antlr4::tree::TerminalNode *WAIT();
    antlr4::tree::TerminalNode *ID();
    NumoridContext *numorid();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *NE();
    antlr4::tree::TerminalNode *TIME();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DelayExprContext : public Signal_statContext {
  public:
    DelayExprContext(Signal_statContext *ctx);

    antlr4::tree::TerminalNode *DELAY();
    antlr4::tree::TerminalNode *TIME();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SetoutExprContext : public Signal_statContext {
  public:
    SetoutExprContext(Signal_statContext *ctx);

    antlr4::tree::TerminalNode *SETOUT();
    antlr4::tree::TerminalNode *ID();
    NumoridContext *numorid();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DinExprContext : public Signal_statContext {
  public:
    DinExprContext(Signal_statContext *ctx);

    antlr4::tree::TerminalNode *DIN();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Signal_statContext* signal_stat();

  class  Math_statContext : public antlr4::ParserRuleContext {
  public:
    Math_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Math_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Math_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DecExprContext : public Math_statContext {
  public:
    DecExprContext(Math_statContext *ctx);

    antlr4::tree::TerminalNode *DECR();
    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FuncExprContext : public Math_statContext {
  public:
    FuncExprContext(Math_statContext *ctx);

    antlr4::Token *op1 = nullptr;
    antlr4::Token *op2 = nullptr;
    antlr4::tree::TerminalNode *FUNC();
    std::vector<antlr4::tree::TerminalNode *> ELEM();
    antlr4::tree::TerminalNode* ELEM(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *NUM();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IncExprContext : public Math_statContext {
  public:
    IncExprContext(Math_statContext *ctx);

    antlr4::tree::TerminalNode *INCR();
    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Math_statContext* math_stat();

  class  Call_statContext : public antlr4::ParserRuleContext {
  public:
    Call_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Call_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Call_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CallExprContext : public Call_statContext {
  public:
    CallExprContext(Call_statContext *ctx);

    antlr4::tree::TerminalNode *CALL();
    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Call_statContext* call_stat();

  class  Assign_statContext : public antlr4::ParserRuleContext {
  public:
    Assign_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Assign_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Assign_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AssignExpr4Context : public Assign_statContext {
  public:
    AssignExpr4Context(Assign_statContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    NumoridContext *numorid();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExpr5Context : public Assign_statContext {
  public:
    AssignExpr5Context(Assign_statContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    antlr4::tree::TerminalNode *CSTRING();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExpr3Context : public Assign_statContext {
  public:
    AssignExpr3Context(Assign_statContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    FuncallexprContext *funcallexpr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExpr2Context : public Assign_statContext {
  public:
    AssignExpr2Context(Assign_statContext *ctx);

    antlr4::Token *op = nullptr;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<NumoridContext *> numorid();
    NumoridContext* numorid(size_t i);
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *NE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExpr1Context : public Assign_statContext {
  public:
    AssignExpr1Context(Assign_statContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    BoolvalContext *boolval();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Assign_statContext* assign_stat();

  class  Goto_statContext : public antlr4::ParserRuleContext {
  public:
    Goto_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Goto_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Goto_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  GotoExprContext : public Goto_statContext {
  public:
    GotoExprContext(Goto_statContext *ctx);

    antlr4::tree::TerminalNode *GOTO();
    antlr4::tree::TerminalNode *LABEL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Goto_statContext* goto_stat();

  class  If_statContext : public antlr4::ParserRuleContext {
  public:
    If_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    If_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(If_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IfExpr1Context : public If_statContext {
  public:
    IfExpr1Context(If_statContext *ctx);

    antlr4::Token *op = nullptr;
    antlr4::tree::TerminalNode *IF();
    std::vector<NumoridContext *> numorid();
    NumoridContext* numorid(size_t i);
    antlr4::tree::TerminalNode *THEN();
    BlockContext *block();
    antlr4::tree::TerminalNode *ENDIF();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *NE();
    std::vector<Elseif_statContext *> elseif_stat();
    Elseif_statContext* elseif_stat(size_t i);
    Else_statContext *else_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfExpr3Context : public If_statContext {
  public:
    IfExpr3Context(If_statContext *ctx);

    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *THEN();
    BlockContext *block();
    antlr4::tree::TerminalNode *ENDIF();
    std::vector<Elseif_statContext *> elseif_stat();
    Elseif_statContext* elseif_stat(size_t i);
    Else_statContext *else_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfExpr2Context : public If_statContext {
  public:
    IfExpr2Context(If_statContext *ctx);

    antlr4::tree::TerminalNode *IF();
    BoolvalContext *boolval();
    antlr4::tree::TerminalNode *THEN();
    BlockContext *block();
    antlr4::tree::TerminalNode *ENDIF();
    std::vector<Elseif_statContext *> elseif_stat();
    Elseif_statContext* elseif_stat(size_t i);
    Else_statContext *else_stat();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  If_statContext* if_stat();

  class  Elseif_statContext : public antlr4::ParserRuleContext {
  public:
    Elseif_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Elseif_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Elseif_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ElseifExpr1Context : public Elseif_statContext {
  public:
    ElseifExpr1Context(Elseif_statContext *ctx);

    antlr4::Token *op = nullptr;
    antlr4::tree::TerminalNode *ELSEIF();
    std::vector<NumoridContext *> numorid();
    NumoridContext* numorid(size_t i);
    antlr4::tree::TerminalNode *THEN();
    BlockContext *block();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *NE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ElseifExpr2Context : public Elseif_statContext {
  public:
    ElseifExpr2Context(Elseif_statContext *ctx);

    antlr4::tree::TerminalNode *ELSEIF();
    BoolvalContext *boolval();
    antlr4::tree::TerminalNode *THEN();
    BlockContext *block();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ElseifExpr3Context : public Elseif_statContext {
  public:
    ElseifExpr3Context(Elseif_statContext *ctx);

    antlr4::tree::TerminalNode *ELSEIF();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *THEN();
    BlockContext *block();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Elseif_statContext* elseif_stat();

  class  Else_statContext : public antlr4::ParserRuleContext {
  public:
    Else_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Else_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Else_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ElseExprContext : public Else_statContext {
  public:
    ElseExprContext(Else_statContext *ctx);

    antlr4::tree::TerminalNode *ELSE();
    BlockContext *block();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Else_statContext* else_stat();

  class  For_statContext : public antlr4::ParserRuleContext {
  public:
    For_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    For_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(For_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ForExprContext : public For_statContext {
  public:
    ForExprContext(For_statContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<antlr4::tree::TerminalNode *> NUM();
    antlr4::tree::TerminalNode* NUM(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *BY();
    BlockContext *block();
    antlr4::tree::TerminalNode *ENDFOR();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  For_statContext* for_stat();

  class  While_statContext : public antlr4::ParserRuleContext {
  public:
    While_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    While_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(While_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WhileExpr2Context : public While_statContext {
  public:
    WhileExpr2Context(While_statContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    BoolvalContext *boolval();
    antlr4::tree::TerminalNode *DO();
    BlockContext *block();
    antlr4::tree::TerminalNode *ENDWL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileExpr3Context : public While_statContext {
  public:
    WhileExpr3Context(While_statContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *DO();
    BlockContext *block();
    antlr4::tree::TerminalNode *ENDWL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileExpr1Context : public While_statContext {
  public:
    WhileExpr1Context(While_statContext *ctx);

    antlr4::Token *op = nullptr;
    antlr4::tree::TerminalNode *WHILE();
    std::vector<NumoridContext *> numorid();
    NumoridContext* numorid(size_t i);
    antlr4::tree::TerminalNode *DO();
    BlockContext *block();
    antlr4::tree::TerminalNode *ENDWL();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *NE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  While_statContext* while_stat();

  class  BoolvalContext : public antlr4::ParserRuleContext {
  public:
    BoolvalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BoolvalContext() : antlr4::ParserRuleContext() { }
    void copyFrom(BoolvalContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FalseExprContext : public BoolvalContext {
  public:
    FalseExprContext(BoolvalContext *ctx);

    antlr4::tree::TerminalNode *FALSE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TrueExprContext : public BoolvalContext {
  public:
    TrueExprContext(BoolvalContext *ctx);

    antlr4::tree::TerminalNode *TRUE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BoolvalContext* boolval();

  class  Libcall_statContext : public antlr4::ParserRuleContext {
  public:
    Libcall_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Libcall_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Libcall_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LibcallExprContext : public Libcall_statContext {
  public:
    LibcallExprContext(Libcall_statContext *ctx);

    FuncallexprContext *funcallexpr();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Libcall_statContext* libcall_stat();

  class  FuncallexprContext : public antlr4::ParserRuleContext {
  public:
    FuncallexprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FuncallexprContext() : antlr4::ParserRuleContext() { }
    void copyFrom(FuncallexprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FuncallExprContext : public FuncallexprContext {
  public:
    FuncallExprContext(FuncallexprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    ParamsContext *params();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FuncallexprContext* funcallexpr();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ParamsContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ParamsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParamlistContext : public ParamsContext {
  public:
    ParamlistContext(ParamsContext *ctx);

    std::vector<NumoridContext *> numorid();
    NumoridContext* numorid(size_t i);
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ParamsContext* params();

  class  NumoridContext : public antlr4::ParserRuleContext {
  public:
    NumoridContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NumoridContext() : antlr4::ParserRuleContext() { }
    void copyFrom(NumoridContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumExprContext : public NumoridContext {
  public:
    NumExprContext(NumoridContext *ctx);

    antlr4::tree::TerminalNode *NUM();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExprContext : public NumoridContext {
  public:
    IdExprContext(NumoridContext *ctx);

    antlr4::tree::TerminalNode *ID();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NumoridContext* numorid();

  class  Oneinst_statContext : public antlr4::ParserRuleContext {
  public:
    Oneinst_statContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Oneinst_statContext() : antlr4::ParserRuleContext() { }
    void copyFrom(Oneinst_statContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OneinstExprContext : public Oneinst_statContext {
  public:
    OneinstExprContext(Oneinst_statContext *ctx);

    OneinstContext *oneinst();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Oneinst_statContext* oneinst_stat();

  class  OneinstContext : public antlr4::ParserRuleContext {
  public:
    OneinstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OneinstContext() : antlr4::ParserRuleContext() { }
    void copyFrom(OneinstContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NopExprContext : public OneinstContext {
  public:
    NopExprContext(OneinstContext *ctx);

    antlr4::tree::TerminalNode *NOP();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  HaltExprContext : public OneinstContext {
  public:
    HaltExprContext(OneinstContext *ctx);

    antlr4::tree::TerminalNode *HALT();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RetExprContext : public OneinstContext {
  public:
    RetExprContext(OneinstContext *ctx);

    antlr4::tree::TerminalNode *RET();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PauseExprContext : public OneinstContext {
  public:
    PauseExprContext(OneinstContext *ctx);

    antlr4::tree::TerminalNode *PAUSE();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LabelExprContext : public OneinstContext {
  public:
    LabelExprContext(OneinstContext *ctx);

    antlr4::tree::TerminalNode *LABEL();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakExprContext : public OneinstContext {
  public:
    BreakExprContext(OneinstContext *ctx);

    antlr4::tree::TerminalNode *BREAK();
    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OneinstContext* oneinst();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

