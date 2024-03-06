
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, ASSIGN = 3, EQUAL = 4, NEQ = 5, GT = 6, GE = 7, 
    LE = 8, LT = 9, NOT = 10, AND = 11, OR = 12, MINUS = 13, DIV = 14, LPAR = 15, 
    RPAR = 16, PLUS = 17, MUL = 18, VAR = 19, INT = 20, BOOL = 21, FLOAT = 22, 
    CHAR = 23, IF = 24, THEN = 25, ELSE = 26, ENDIF = 27, FUNC = 28, ENDFUNC = 29, 
    READ = 30, WRITE = 31, ID = 32, INTVAL = 33, BOOLVAL = 34, FLOATVAL = 35, 
    CHARVAL = 36, STRING = 37, COMMENT = 38, WS = 39
  };

  AslLexer(antlr4::CharStream *input);
  ~AslLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
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
  static std::vector<std::string> _channelNames;
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

