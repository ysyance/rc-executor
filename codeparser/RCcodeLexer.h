
// Generated from RCcode.g by ANTLR 4.6

#pragma once


#include "antlr4-runtime.h"




class  RCcodeLexer : public antlr4::Lexer {
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

  RCcodeLexer(antlr4::CharStream *input);
  ~RCcodeLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

