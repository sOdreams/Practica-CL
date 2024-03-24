
// Generated from Asl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AslLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, ASSIGN = 4, EQUAL = 5, NEQ = 6, GT = 7, 
    GE = 8, LE = 9, LT = 10, NOT = 11, AND = 12, OR = 13, MINUS = 14, DIV = 15, 
    MOD = 16, LPAR = 17, RPAR = 18, LCOR = 19, RCOR = 20, PLUS = 21, MUL = 22, 
    VAR = 23, INT = 24, BOOL = 25, FLOAT = 26, CHAR = 27, IF = 28, THEN = 29, 
    ELSE = 30, ENDIF = 31, WHILE = 32, DO = 33, ENDWHILE = 34, RETURN = 35, 
    FUNC = 36, ENDFUNC = 37, READ = 38, WRITE = 39, ARRAY = 40, OF = 41, 
    INTVAL = 42, BOOLVAL = 43, FLOATVAL = 44, CHARVAL = 45, ID = 46, STRING = 47, 
    COMMENT = 48, WS = 49
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

