
// Generated from Asl.g4 by ANTLR 4.7.2


#include "AslVisitor.h"

#include "AslParser.h"


using namespace antlrcpp;
using namespace antlr4;

AslParser::AslParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AslParser::~AslParser() {
  delete _interpreter;
}

std::string AslParser::getGrammarFileName() const {
  return "Asl.g4";
}

const std::vector<std::string>& AslParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AslParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

AslParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::ProgramContext::EOF() {
  return getToken(AslParser::EOF, 0);
}

std::vector<AslParser::FunctionContext *> AslParser::ProgramContext::function() {
  return getRuleContexts<AslParser::FunctionContext>();
}

AslParser::FunctionContext* AslParser::ProgramContext::function(size_t i) {
  return getRuleContext<AslParser::FunctionContext>(i);
}


size_t AslParser::ProgramContext::getRuleIndex() const {
  return AslParser::RuleProgram;
}

antlrcpp::Any AslParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ProgramContext* AslParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, AslParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(27); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      function();
      setState(29); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(31);
    match(AslParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

AslParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::FunctionContext::FUNC() {
  return getToken(AslParser::FUNC, 0);
}

tree::TerminalNode* AslParser::FunctionContext::ID() {
  return getToken(AslParser::ID, 0);
}

tree::TerminalNode* AslParser::FunctionContext::LPAR() {
  return getToken(AslParser::LPAR, 0);
}

AslParser::ParametersContext* AslParser::FunctionContext::parameters() {
  return getRuleContext<AslParser::ParametersContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::RPAR() {
  return getToken(AslParser::RPAR, 0);
}

AslParser::DeclarationsContext* AslParser::FunctionContext::declarations() {
  return getRuleContext<AslParser::DeclarationsContext>(0);
}

AslParser::StatementsContext* AslParser::FunctionContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::FunctionContext::ENDFUNC() {
  return getToken(AslParser::ENDFUNC, 0);
}

AslParser::Basic_typeContext* AslParser::FunctionContext::basic_type() {
  return getRuleContext<AslParser::Basic_typeContext>(0);
}


size_t AslParser::FunctionContext::getRuleIndex() const {
  return AslParser::RuleFunction;
}

antlrcpp::Any AslParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

AslParser::FunctionContext* AslParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 2, AslParser::RuleFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    match(AslParser::FUNC);
    setState(34);
    match(AslParser::ID);
    setState(35);
    match(AslParser::LPAR);
    setState(36);
    parameters();
    setState(37);
    match(AslParser::RPAR);
    setState(40);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::T__0) {
      setState(38);
      match(AslParser::T__0);
      setState(39);
      basic_type();
    }
    setState(42);
    declarations();
    setState(43);
    statements();
    setState(44);
    match(AslParser::ENDFUNC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

AslParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> AslParser::ParametersContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::ParametersContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

std::vector<AslParser::TypeContext *> AslParser::ParametersContext::type() {
  return getRuleContexts<AslParser::TypeContext>();
}

AslParser::TypeContext* AslParser::ParametersContext::type(size_t i) {
  return getRuleContext<AslParser::TypeContext>(i);
}


size_t AslParser::ParametersContext::getRuleIndex() const {
  return AslParser::RuleParameters;
}

antlrcpp::Any AslParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ParametersContext* AslParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, AslParser::RuleParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::ID) {
      setState(46);
      match(AslParser::ID);
      setState(47);
      match(AslParser::T__0);
      setState(48);
      type();
      setState(56);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__1) {
        setState(50);
        match(AslParser::T__1);
        setState(51);
        match(AslParser::ID);
        setState(52);
        match(AslParser::T__0);
        setState(53);
        type();
        setState(58);
        _errHandler->sync(this);
        _la = _input->LA(1);
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

//----------------- DeclarationsContext ------------------------------------------------------------------

AslParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::Variable_declContext *> AslParser::DeclarationsContext::variable_decl() {
  return getRuleContexts<AslParser::Variable_declContext>();
}

AslParser::Variable_declContext* AslParser::DeclarationsContext::variable_decl(size_t i) {
  return getRuleContext<AslParser::Variable_declContext>(i);
}


size_t AslParser::DeclarationsContext::getRuleIndex() const {
  return AslParser::RuleDeclarations;
}

antlrcpp::Any AslParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

AslParser::DeclarationsContext* AslParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 6, AslParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(61);
      variable_decl();
      setState(66);
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

//----------------- Variable_declContext ------------------------------------------------------------------

AslParser::Variable_declContext::Variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Variable_declContext::VAR() {
  return getToken(AslParser::VAR, 0);
}

std::vector<tree::TerminalNode *> AslParser::Variable_declContext::ID() {
  return getTokens(AslParser::ID);
}

tree::TerminalNode* AslParser::Variable_declContext::ID(size_t i) {
  return getToken(AslParser::ID, i);
}

AslParser::TypeContext* AslParser::Variable_declContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
}


size_t AslParser::Variable_declContext::getRuleIndex() const {
  return AslParser::RuleVariable_decl;
}

antlrcpp::Any AslParser::Variable_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitVariable_decl(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Variable_declContext* AslParser::variable_decl() {
  Variable_declContext *_localctx = _tracker.createInstance<Variable_declContext>(_ctx, getState());
  enterRule(_localctx, 8, AslParser::RuleVariable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    match(AslParser::VAR);
    setState(68);
    match(AslParser::ID);
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__1) {
      setState(69);
      match(AslParser::T__1);
      setState(70);
      match(AslParser::ID);
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    match(AslParser::T__0);
    setState(77);
    type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

AslParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AslParser::Basic_typeContext* AslParser::TypeContext::basic_type() {
  return getRuleContext<AslParser::Basic_typeContext>(0);
}

AslParser::Array_typeContext* AslParser::TypeContext::array_type() {
  return getRuleContext<AslParser::Array_typeContext>(0);
}


size_t AslParser::TypeContext::getRuleIndex() const {
  return AslParser::RuleType;
}

antlrcpp::Any AslParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

AslParser::TypeContext* AslParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 10, AslParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AslParser::INT:
      case AslParser::BOOL:
      case AslParser::FLOAT:
      case AslParser::CHAR: {
        enterOuterAlt(_localctx, 1);
        setState(79);
        basic_type();
        break;
      }

      case AslParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(80);
        array_type();
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

//----------------- Array_typeContext ------------------------------------------------------------------

AslParser::Array_typeContext::Array_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Array_typeContext::ARRAY() {
  return getToken(AslParser::ARRAY, 0);
}

tree::TerminalNode* AslParser::Array_typeContext::LCOR() {
  return getToken(AslParser::LCOR, 0);
}

tree::TerminalNode* AslParser::Array_typeContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::Array_typeContext::RCOR() {
  return getToken(AslParser::RCOR, 0);
}

tree::TerminalNode* AslParser::Array_typeContext::OF() {
  return getToken(AslParser::OF, 0);
}

AslParser::Basic_typeContext* AslParser::Array_typeContext::basic_type() {
  return getRuleContext<AslParser::Basic_typeContext>(0);
}


size_t AslParser::Array_typeContext::getRuleIndex() const {
  return AslParser::RuleArray_type;
}

antlrcpp::Any AslParser::Array_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArray_type(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Array_typeContext* AslParser::array_type() {
  Array_typeContext *_localctx = _tracker.createInstance<Array_typeContext>(_ctx, getState());
  enterRule(_localctx, 12, AslParser::RuleArray_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(AslParser::ARRAY);
    setState(84);
    match(AslParser::LCOR);
    setState(85);
    match(AslParser::INTVAL);
    setState(86);
    match(AslParser::RCOR);
    setState(87);
    match(AslParser::OF);
    setState(88);
    basic_type();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Basic_typeContext ------------------------------------------------------------------

AslParser::Basic_typeContext::Basic_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::Basic_typeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::Basic_typeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
}


size_t AslParser::Basic_typeContext::getRuleIndex() const {
  return AslParser::RuleBasic_type;
}

antlrcpp::Any AslParser::Basic_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitBasic_type(this);
  else
    return visitor->visitChildren(this);
}

AslParser::Basic_typeContext* AslParser::basic_type() {
  Basic_typeContext *_localctx = _tracker.createInstance<Basic_typeContext>(_ctx, getState());
  enterRule(_localctx, 14, AslParser::RuleBasic_type);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::INT)
      | (1ULL << AslParser::BOOL)
      | (1ULL << AslParser::FLOAT)
      | (1ULL << AslParser::CHAR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

AslParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<AslParser::StatementContext *> AslParser::StatementsContext::statement() {
  return getRuleContexts<AslParser::StatementContext>();
}

AslParser::StatementContext* AslParser::StatementsContext::statement(size_t i) {
  return getRuleContext<AslParser::StatementContext>(i);
}


size_t AslParser::StatementsContext::getRuleIndex() const {
  return AslParser::RuleStatements;
}

antlrcpp::Any AslParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

AslParser::StatementsContext* AslParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 16, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::RETURN)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(92);
      statement();
      setState(97);
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

//----------------- StatementContext ------------------------------------------------------------------

AslParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::StatementContext::getRuleIndex() const {
  return AslParser::RuleStatement;
}

void AslParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ProcCallContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ProcCallContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::ProcCallContext::LPAR() {
  return getToken(AslParser::LPAR, 0);
}

tree::TerminalNode* AslParser::ProcCallContext::RPAR() {
  return getToken(AslParser::RPAR, 0);
}

std::vector<AslParser::ExprContext *> AslParser::ProcCallContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ProcCallContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::ProcCallContext::ProcCallContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ProcCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitProcCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnCallContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReturnCallContext::RETURN() {
  return getToken(AslParser::RETURN, 0);
}

AslParser::ExprContext* AslParser::ReturnCallContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::ReturnCallContext::ReturnCallContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ReturnCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReturnCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteExprContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteExprContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

AslParser::ExprContext* AslParser::WriteExprContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::WriteExprContext::WriteExprContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WriteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WhileStmtContext::WHILE() {
  return getToken(AslParser::WHILE, 0);
}

AslParser::ExprContext* AslParser::WhileStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::DO() {
  return getToken(AslParser::DO, 0);
}

AslParser::StatementsContext* AslParser::WhileStmtContext::statements() {
  return getRuleContext<AslParser::StatementsContext>(0);
}

tree::TerminalNode* AslParser::WhileStmtContext::ENDWHILE() {
  return getToken(AslParser::ENDWHILE, 0);
}

AslParser::WhileStmtContext::WhileStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::IfStmtContext::IF() {
  return getToken(AslParser::IF, 0);
}

AslParser::ExprContext* AslParser::IfStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::IfStmtContext::THEN() {
  return getToken(AslParser::THEN, 0);
}

std::vector<AslParser::StatementsContext *> AslParser::IfStmtContext::statements() {
  return getRuleContexts<AslParser::StatementsContext>();
}

AslParser::StatementsContext* AslParser::IfStmtContext::statements(size_t i) {
  return getRuleContext<AslParser::StatementsContext>(i);
}

tree::TerminalNode* AslParser::IfStmtContext::ENDIF() {
  return getToken(AslParser::ENDIF, 0);
}

tree::TerminalNode* AslParser::IfStmtContext::ELSE() {
  return getToken(AslParser::ELSE, 0);
}

AslParser::IfStmtContext::IfStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReadStmtContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ReadStmtContext::READ() {
  return getToken(AslParser::READ, 0);
}

AslParser::Left_exprContext* AslParser::ReadStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

AslParser::ReadStmtContext::ReadStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ReadStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitReadStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignStmtContext ------------------------------------------------------------------

AslParser::Left_exprContext* AslParser::AssignStmtContext::left_expr() {
  return getRuleContext<AslParser::Left_exprContext>(0);
}

tree::TerminalNode* AslParser::AssignStmtContext::ASSIGN() {
  return getToken(AslParser::ASSIGN, 0);
}

AslParser::ExprContext* AslParser::AssignStmtContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

AslParser::AssignStmtContext::AssignStmtContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WriteStringContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::WriteStringContext::WRITE() {
  return getToken(AslParser::WRITE, 0);
}

tree::TerminalNode* AslParser::WriteStringContext::STRING() {
  return getToken(AslParser::STRING, 0);
}

AslParser::WriteStringContext::WriteStringContext(StatementContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::WriteStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitWriteString(this);
  else
    return visitor->visitChildren(this);
}
AslParser::StatementContext* AslParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(98);
      left_expr();
      setState(99);
      match(AslParser::ASSIGN);
      setState(100);
      expr(0);
      setState(101);
      match(AslParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(103);
      match(AslParser::IF);
      setState(104);
      expr(0);
      setState(105);
      match(AslParser::THEN);
      setState(106);
      statements();
      setState(109);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(107);
        match(AslParser::ELSE);
        setState(108);
        statements();
      }
      setState(111);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(113);
      match(AslParser::WHILE);
      setState(114);
      expr(0);
      setState(115);
      match(AslParser::DO);
      setState(116);
      statements();
      setState(117);
      match(AslParser::ENDWHILE);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(119);
      ident();
      setState(120);
      match(AslParser::LPAR);
      setState(129);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::LPAR)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(121);
        expr(0);
        setState(126);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__1) {
          setState(122);
          match(AslParser::T__1);
          setState(123);
          expr(0);
          setState(128);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(131);
      match(AslParser::RPAR);
      setState(132);
      match(AslParser::T__2);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReturnCallContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(134);
      match(AslParser::RETURN);
      setState(136);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::LPAR)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(135);
        expr(0);
      }
      setState(138);
      match(AslParser::T__2);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(139);
      match(AslParser::READ);
      setState(140);
      left_expr();
      setState(141);
      match(AslParser::T__2);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(143);
      match(AslParser::WRITE);
      setState(144);
      expr(0);
      setState(145);
      match(AslParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(147);
      match(AslParser::WRITE);
      setState(148);
      match(AslParser::STRING);
      setState(149);
      match(AslParser::T__2);
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

//----------------- Left_exprContext ------------------------------------------------------------------

AslParser::Left_exprContext::Left_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::Left_exprContext::getRuleIndex() const {
  return AslParser::RuleLeft_expr;
}

void AslParser::Left_exprContext::copyFrom(Left_exprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Just_identContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::Just_identContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::Just_identContext::Just_identContext(Left_exprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::Just_identContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitJust_ident(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Left_array_accesContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::Left_array_accesContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::Left_array_accesContext::LCOR() {
  return getToken(AslParser::LCOR, 0);
}

AslParser::ExprContext* AslParser::Left_array_accesContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::Left_array_accesContext::RCOR() {
  return getToken(AslParser::RCOR, 0);
}

AslParser::Left_array_accesContext::Left_array_accesContext(Left_exprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::Left_array_accesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLeft_array_acces(this);
  else
    return visitor->visitChildren(this);
}
AslParser::Left_exprContext* AslParser::left_expr() {
  Left_exprContext *_localctx = _tracker.createInstance<Left_exprContext>(_ctx, getState());
  enterRule(_localctx, 20, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(158);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Left_exprContext *>(_tracker.createInstance<AslParser::Just_identContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(152);
      ident();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Left_exprContext *>(_tracker.createInstance<AslParser::Left_array_accesContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(153);
      ident();
      setState(154);
      match(AslParser::LCOR);
      setState(155);
      expr(0);
      setState(156);
      match(AslParser::RCOR);
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

//----------------- ExprContext ------------------------------------------------------------------

AslParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AslParser::ExprContext::getRuleIndex() const {
  return AslParser::RuleExpr;
}

void AslParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expr_array_accesContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::Expr_array_accesContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::Expr_array_accesContext::LCOR() {
  return getToken(AslParser::LCOR, 0);
}

AslParser::ExprContext* AslParser::Expr_array_accesContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::Expr_array_accesContext::RCOR() {
  return getToken(AslParser::RCOR, 0);
}

AslParser::Expr_array_accesContext::Expr_array_accesContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::Expr_array_accesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExpr_array_acces(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprIdentContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::ExprIdentContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

AslParser::ExprIdentContext::ExprIdentContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ExprIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitExprIdent(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArithmeticContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::ArithmeticContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::ArithmeticContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::ArithmeticContext::MUL() {
  return getToken(AslParser::MUL, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::DIV() {
  return getToken(AslParser::DIV, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MOD() {
  return getToken(AslParser::MOD, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

tree::TerminalNode* AslParser::ArithmeticContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

AslParser::ArithmeticContext::ArithmeticContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ArithmeticContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitArithmetic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::RelationalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::RelationalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::RelationalContext::EQUAL() {
  return getToken(AslParser::EQUAL, 0);
}

tree::TerminalNode* AslParser::RelationalContext::NEQ() {
  return getToken(AslParser::NEQ, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GT() {
  return getToken(AslParser::GT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::GE() {
  return getToken(AslParser::GE, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LT() {
  return getToken(AslParser::LT, 0);
}

tree::TerminalNode* AslParser::RelationalContext::LE() {
  return getToken(AslParser::LE, 0);
}

AslParser::RelationalContext::RelationalContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::RelationalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitRelational(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryContext ------------------------------------------------------------------

AslParser::ExprContext* AslParser::UnaryContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::UnaryContext::NOT() {
  return getToken(AslParser::NOT, 0);
}

tree::TerminalNode* AslParser::UnaryContext::MINUS() {
  return getToken(AslParser::MINUS, 0);
}

tree::TerminalNode* AslParser::UnaryContext::PLUS() {
  return getToken(AslParser::PLUS, 0);
}

AslParser::UnaryContext::UnaryContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesisContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ParenthesisContext::LPAR() {
  return getToken(AslParser::LPAR, 0);
}

AslParser::ExprContext* AslParser::ParenthesisContext::expr() {
  return getRuleContext<AslParser::ExprContext>(0);
}

tree::TerminalNode* AslParser::ParenthesisContext::RPAR() {
  return getToken(AslParser::RPAR, 0);
}

AslParser::ParenthesisContext::ParenthesisContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ParenthesisContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitParenthesis(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Func_callContext ------------------------------------------------------------------

AslParser::IdentContext* AslParser::Func_callContext::ident() {
  return getRuleContext<AslParser::IdentContext>(0);
}

tree::TerminalNode* AslParser::Func_callContext::LPAR() {
  return getToken(AslParser::LPAR, 0);
}

tree::TerminalNode* AslParser::Func_callContext::RPAR() {
  return getToken(AslParser::RPAR, 0);
}

std::vector<AslParser::ExprContext *> AslParser::Func_callContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::Func_callContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

AslParser::Func_callContext::Func_callContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::Func_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitFunc_call(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ValueContext ------------------------------------------------------------------

tree::TerminalNode* AslParser::ValueContext::INTVAL() {
  return getToken(AslParser::INTVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::FLOATVAL() {
  return getToken(AslParser::FLOATVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::BOOLVAL() {
  return getToken(AslParser::BOOLVAL, 0);
}

tree::TerminalNode* AslParser::ValueContext::CHARVAL() {
  return getToken(AslParser::CHARVAL, 0);
}

AslParser::ValueContext::ValueContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalContext ------------------------------------------------------------------

std::vector<AslParser::ExprContext *> AslParser::LogicalContext::expr() {
  return getRuleContexts<AslParser::ExprContext>();
}

AslParser::ExprContext* AslParser::LogicalContext::expr(size_t i) {
  return getRuleContext<AslParser::ExprContext>(i);
}

tree::TerminalNode* AslParser::LogicalContext::AND() {
  return getToken(AslParser::AND, 0);
}

tree::TerminalNode* AslParser::LogicalContext::OR() {
  return getToken(AslParser::OR, 0);
}

AslParser::LogicalContext::LogicalContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any AslParser::LogicalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitLogical(this);
  else
    return visitor->visitChildren(this);
}

AslParser::ExprContext* AslParser::expr() {
   return expr(0);
}

AslParser::ExprContext* AslParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AslParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  AslParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(188);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(161);
      match(AslParser::LPAR);
      setState(162);
      expr(0);
      setState(163);
      match(AslParser::RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(165);
      dynamic_cast<UnaryContext *>(_localctx)->op = _input->LT(1);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::PLUS))) != 0))) {
        dynamic_cast<UnaryContext *>(_localctx)->op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(166);
      expr(10);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Expr_array_accesContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(167);
      ident();
      setState(168);
      match(AslParser::LCOR);
      setState(169);
      expr(0);
      setState(170);
      match(AslParser::RCOR);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Func_callContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(172);
      ident();
      setState(173);
      match(AslParser::LPAR);
      setState(182);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::NOT)
        | (1ULL << AslParser::MINUS)
        | (1ULL << AslParser::LPAR)
        | (1ULL << AslParser::PLUS)
        | (1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL)
        | (1ULL << AslParser::ID))) != 0)) {
        setState(174);
        expr(0);
        setState(179);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == AslParser::T__1) {
          setState(175);
          match(AslParser::T__1);
          setState(176);
          expr(0);
          setState(181);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(184);
      match(AslParser::RPAR);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << AslParser::INTVAL)
        | (1ULL << AslParser::BOOLVAL)
        | (1ULL << AslParser::FLOATVAL)
        | (1ULL << AslParser::CHARVAL))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      ident();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(207);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(205);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(190);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(191);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::DIV)
            | (1ULL << AslParser::MOD)
            | (1ULL << AslParser::MUL))) != 0))) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(192);
          expr(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(193);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(194);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::MINUS

          || _la == AslParser::PLUS)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(195);
          expr(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(196);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(197);
          dynamic_cast<RelationalContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << AslParser::EQUAL)
            | (1ULL << AslParser::NEQ)
            | (1ULL << AslParser::GT)
            | (1ULL << AslParser::GE)
            | (1ULL << AslParser::LE)
            | (1ULL << AslParser::LT))) != 0))) {
            dynamic_cast<RelationalContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(198);
          expr(8);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(199);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(200);
          dynamic_cast<LogicalContext *>(_localctx)->op = match(AslParser::AND);
          setState(201);
          expr(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(202);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(203);
          dynamic_cast<LogicalContext *>(_localctx)->op = match(AslParser::OR);
          setState(204);
          expr(4);
          break;
        }

        } 
      }
      setState(209);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

AslParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AslParser::IdentContext::ID() {
  return getToken(AslParser::ID, 0);
}


size_t AslParser::IdentContext::getRuleIndex() const {
  return AslParser::RuleIdent;
}

antlrcpp::Any AslParser::IdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AslVisitor*>(visitor))
    return parserVisitor->visitIdent(this);
  else
    return visitor->visitChildren(this);
}

AslParser::IdentContext* AslParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 24, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(AslParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool AslParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 7);
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> AslParser::_decisionToDFA;
atn::PredictionContextCache AslParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AslParser::_atn;
std::vector<uint16_t> AslParser::_serializedATN;

std::vector<std::string> AslParser::_ruleNames = {
  "program", "function", "parameters", "declarations", "variable_decl", 
  "type", "array_type", "basic_type", "statements", "statement", "left_expr", 
  "expr", "ident"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "':'", "','", "';'", "'='", "'=='", "'!='", "'>'", "'>='", "'<='", 
  "'<'", "'not'", "'and'", "'or'", "'-'", "'/'", "'%'", "'('", "')'", "'['", 
  "']'", "'+'", "'*'", "'var'", "'int'", "'bool'", "'float'", "'char'", 
  "'if'", "'then'", "'else'", "'endif'", "'while'", "'do'", "'endwhile'", 
  "'return'", "'func'", "'endfunc'", "'read'", "'write'", "'array'", "'of'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "ASSIGN", "EQUAL", "NEQ", "GT", "GE", "LE", "LT", "NOT", 
  "AND", "OR", "MINUS", "DIV", "MOD", "LPAR", "RPAR", "LCOR", "RCOR", "PLUS", 
  "MUL", "VAR", "INT", "BOOL", "FLOAT", "CHAR", "IF", "THEN", "ELSE", "ENDIF", 
  "WHILE", "DO", "ENDWHILE", "RETURN", "FUNC", "ENDFUNC", "READ", "WRITE", 
  "ARRAY", "OF", "INTVAL", "BOOLVAL", "FLOATVAL", "CHARVAL", "ID", "STRING", 
  "COMMENT", "WS"
};

dfa::Vocabulary AslParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AslParser::_tokenNames;

AslParser::Initializer::Initializer() {
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
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x33, 0xd7, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x3, 
    0x2, 0x6, 0x2, 0x1e, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1f, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x2b, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x7, 0x4, 0x39, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x3c, 0xb, 0x4, 
    0x5, 0x4, 0x3e, 0xa, 0x4, 0x3, 0x5, 0x7, 0x5, 0x41, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x44, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x4a, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x4d, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x54, 0xa, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0xa, 0x7, 0xa, 0x60, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x63, 
    0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x70, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 
    0xb, 0x7f, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x82, 0xb, 0xb, 0x5, 0xb, 0x84, 
    0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x8b, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0x99, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x5, 0xc, 0xa1, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 
    0xd, 0xb4, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xb7, 0xb, 0xd, 0x5, 0xd, 0xb9, 
    0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xbf, 0xa, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x7, 0xd, 0xd0, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xd3, 0xb, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x2, 0x3, 0x18, 0xf, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x2, 0x8, 0x3, 
    0x2, 0x1a, 0x1d, 0x5, 0x2, 0xd, 0xd, 0x10, 0x10, 0x17, 0x17, 0x3, 0x2, 
    0x2c, 0x2f, 0x4, 0x2, 0x11, 0x12, 0x18, 0x18, 0x4, 0x2, 0x10, 0x10, 
    0x17, 0x17, 0x3, 0x2, 0x7, 0xc, 0x2, 0xe9, 0x2, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x23, 0x3, 0x2, 0x2, 0x2, 0x6, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0xa, 0x45, 0x3, 0x2, 0x2, 0x2, 0xc, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x55, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x61, 0x3, 0x2, 0x2, 0x2, 0x14, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x18, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1e, 0x5, 0x4, 0x3, 0x2, 
    0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0x21, 0x22, 0x7, 0x2, 0x2, 0x3, 0x22, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x23, 0x24, 0x7, 0x26, 0x2, 0x2, 0x24, 0x25, 0x7, 0x30, 
    0x2, 0x2, 0x25, 0x26, 0x7, 0x13, 0x2, 0x2, 0x26, 0x27, 0x5, 0x6, 0x4, 
    0x2, 0x27, 0x2a, 0x7, 0x14, 0x2, 0x2, 0x28, 0x29, 0x7, 0x3, 0x2, 0x2, 
    0x29, 0x2b, 0x5, 0x10, 0x9, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 
    0x5, 0x8, 0x5, 0x2, 0x2d, 0x2e, 0x5, 0x12, 0xa, 0x2, 0x2e, 0x2f, 0x7, 
    0x27, 0x2, 0x2, 0x2f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x30, 
    0x2, 0x2, 0x31, 0x32, 0x7, 0x3, 0x2, 0x2, 0x32, 0x33, 0x5, 0xc, 0x7, 
    0x2, 0x33, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x7, 0x4, 0x2, 0x2, 
    0x35, 0x36, 0x7, 0x30, 0x2, 0x2, 0x36, 0x37, 0x7, 0x3, 0x2, 0x2, 0x37, 
    0x39, 0x5, 0xc, 0x7, 0x2, 0x38, 0x34, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x3b, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 
    0x2, 0x2, 0x3d, 0x30, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x41, 0x5, 0xa, 0x6, 0x2, 
    0x40, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 
    0x19, 0x2, 0x2, 0x46, 0x4b, 0x7, 0x30, 0x2, 0x2, 0x47, 0x48, 0x7, 0x4, 
    0x2, 0x2, 0x48, 0x4a, 0x7, 0x30, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x4a, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x3, 0x2, 0x2, 0x4f, 0x50, 
    0x5, 0xc, 0x7, 0x2, 0x50, 0xb, 0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 0x5, 
    0x10, 0x9, 0x2, 0x52, 0x54, 0x5, 0xe, 0x8, 0x2, 0x53, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x56, 0x7, 0x2a, 0x2, 0x2, 0x56, 0x57, 0x7, 0x15, 0x2, 0x2, 
    0x57, 0x58, 0x7, 0x2c, 0x2, 0x2, 0x58, 0x59, 0x7, 0x16, 0x2, 0x2, 0x59, 
    0x5a, 0x7, 0x2b, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0x10, 0x9, 0x2, 0x5b, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x9, 0x2, 0x2, 0x2, 0x5d, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x60, 0x5, 0x14, 0xb, 0x2, 0x5f, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x63, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x5, 0x16, 0xc, 0x2, 0x65, 
    0x66, 0x7, 0x6, 0x2, 0x2, 0x66, 0x67, 0x5, 0x18, 0xd, 0x2, 0x67, 0x68, 
    0x7, 0x5, 0x2, 0x2, 0x68, 0x99, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 
    0x1e, 0x2, 0x2, 0x6a, 0x6b, 0x5, 0x18, 0xd, 0x2, 0x6b, 0x6c, 0x7, 0x1f, 
    0x2, 0x2, 0x6c, 0x6f, 0x5, 0x12, 0xa, 0x2, 0x6d, 0x6e, 0x7, 0x20, 0x2, 
    0x2, 0x6e, 0x70, 0x5, 0x12, 0xa, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x72, 0x7, 0x21, 0x2, 0x2, 0x72, 0x99, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 
    0x7, 0x22, 0x2, 0x2, 0x74, 0x75, 0x5, 0x18, 0xd, 0x2, 0x75, 0x76, 0x7, 
    0x23, 0x2, 0x2, 0x76, 0x77, 0x5, 0x12, 0xa, 0x2, 0x77, 0x78, 0x7, 0x24, 
    0x2, 0x2, 0x78, 0x99, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x5, 0x1a, 0xe, 
    0x2, 0x7a, 0x83, 0x7, 0x13, 0x2, 0x2, 0x7b, 0x80, 0x5, 0x18, 0xd, 0x2, 
    0x7c, 0x7d, 0x7, 0x4, 0x2, 0x2, 0x7d, 0x7f, 0x5, 0x18, 0xd, 0x2, 0x7e, 
    0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x82, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x83, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x85, 0x86, 0x7, 0x14, 0x2, 0x2, 0x86, 0x87, 0x7, 0x5, 0x2, 0x2, 
    0x87, 0x99, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8a, 0x7, 0x25, 0x2, 0x2, 0x89, 
    0x8b, 0x5, 0x18, 0xd, 0x2, 0x8a, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x99, 0x7, 
    0x5, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x28, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x16, 
    0xc, 0x2, 0x8f, 0x90, 0x7, 0x5, 0x2, 0x2, 0x90, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x91, 0x92, 0x7, 0x29, 0x2, 0x2, 0x92, 0x93, 0x5, 0x18, 0xd, 0x2, 
    0x93, 0x94, 0x7, 0x5, 0x2, 0x2, 0x94, 0x99, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x96, 0x7, 0x29, 0x2, 0x2, 0x96, 0x97, 0x7, 0x31, 0x2, 0x2, 0x97, 0x99, 
    0x7, 0x5, 0x2, 0x2, 0x98, 0x64, 0x3, 0x2, 0x2, 0x2, 0x98, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x73, 0x3, 0x2, 0x2, 0x2, 0x98, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x88, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x91, 0x3, 0x2, 0x2, 0x2, 0x98, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x15, 0x3, 0x2, 0x2, 0x2, 0x9a, 0xa1, 0x5, 0x1a, 0xe, 0x2, 0x9b, 
    0x9c, 0x5, 0x1a, 0xe, 0x2, 0x9c, 0x9d, 0x7, 0x15, 0x2, 0x2, 0x9d, 0x9e, 
    0x5, 0x18, 0xd, 0x2, 0x9e, 0x9f, 0x7, 0x16, 0x2, 0x2, 0x9f, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x8, 0xd, 0x1, 
    0x2, 0xa3, 0xa4, 0x7, 0x13, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x18, 0xd, 0x2, 
    0xa5, 0xa6, 0x7, 0x14, 0x2, 0x2, 0xa6, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa8, 0x9, 0x3, 0x2, 0x2, 0xa8, 0xbf, 0x5, 0x18, 0xd, 0xc, 0xa9, 0xaa, 
    0x5, 0x1a, 0xe, 0x2, 0xaa, 0xab, 0x7, 0x15, 0x2, 0x2, 0xab, 0xac, 0x5, 
    0x18, 0xd, 0x2, 0xac, 0xad, 0x7, 0x16, 0x2, 0x2, 0xad, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xaf, 0x5, 0x1a, 0xe, 0x2, 0xaf, 0xb8, 0x7, 0x13, 0x2, 
    0x2, 0xb0, 0xb5, 0x5, 0x18, 0xd, 0x2, 0xb1, 0xb2, 0x7, 0x4, 0x2, 0x2, 
    0xb2, 0xb4, 0x5, 0x18, 0xd, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0xb7, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0xb8, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x14, 0x2, 
    0x2, 0xbb, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbf, 0x9, 0x4, 0x2, 0x2, 
    0xbd, 0xbf, 0x5, 0x1a, 0xe, 0x2, 0xbe, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xbe, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xae, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0xc, 0xb, 
    0x2, 0x2, 0xc1, 0xc2, 0x9, 0x5, 0x2, 0x2, 0xc2, 0xd0, 0x5, 0x18, 0xd, 
    0xc, 0xc3, 0xc4, 0xc, 0xa, 0x2, 0x2, 0xc4, 0xc5, 0x9, 0x6, 0x2, 0x2, 
    0xc5, 0xd0, 0x5, 0x18, 0xd, 0xb, 0xc6, 0xc7, 0xc, 0x9, 0x2, 0x2, 0xc7, 
    0xc8, 0x9, 0x7, 0x2, 0x2, 0xc8, 0xd0, 0x5, 0x18, 0xd, 0xa, 0xc9, 0xca, 
    0xc, 0x6, 0x2, 0x2, 0xca, 0xcb, 0x7, 0xe, 0x2, 0x2, 0xcb, 0xd0, 0x5, 
    0x18, 0xd, 0x7, 0xcc, 0xcd, 0xc, 0x5, 0x2, 0x2, 0xcd, 0xce, 0x7, 0xf, 
    0x2, 0x2, 0xce, 0xd0, 0x5, 0x18, 0xd, 0x6, 0xcf, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xcf, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc6, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd0, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x30, 0x2, 0x2, 0xd5, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x15, 0x1f, 0x2a, 0x3a, 0x3d, 0x42, 0x4b, 0x53, 0x61, 0x6f, 
    0x80, 0x83, 0x8a, 0x98, 0xa0, 0xb5, 0xb8, 0xbe, 0xcf, 0xd1, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AslParser::Initializer AslParser::_init;
