
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
    setState(23); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(22);
      function();
      setState(25); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == AslParser::FUNC);
    setState(27);
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

AslParser::TypeContext* AslParser::FunctionContext::type() {
  return getRuleContext<AslParser::TypeContext>(0);
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
    setState(29);
    match(AslParser::FUNC);
    setState(30);
    match(AslParser::ID);
    setState(31);
    match(AslParser::LPAR);
    setState(32);
    parameters();
    setState(33);
    match(AslParser::RPAR);
    setState(36);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::T__0) {
      setState(34);
      match(AslParser::T__0);
      setState(35);
      type();
    }
    setState(38);
    declarations();
    setState(39);
    statements();
    setState(40);
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
    setState(55);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == AslParser::ID) {
      setState(42);
      match(AslParser::ID);
      setState(43);
      match(AslParser::T__0);
      setState(44);
      type();
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == AslParser::T__1) {
        setState(46);
        match(AslParser::T__1);
        setState(47);
        match(AslParser::ID);
        setState(48);
        match(AslParser::T__0);
        setState(49);
        type();
        setState(54);
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
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::VAR) {
      setState(57);
      variable_decl();
      setState(62);
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
    setState(63);
    match(AslParser::VAR);
    setState(64);
    match(AslParser::ID);
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == AslParser::T__1) {
      setState(65);
      match(AslParser::T__1);
      setState(66);
      match(AslParser::ID);
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    match(AslParser::T__0);
    setState(73);
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

tree::TerminalNode* AslParser::TypeContext::INT() {
  return getToken(AslParser::INT, 0);
}

tree::TerminalNode* AslParser::TypeContext::BOOL() {
  return getToken(AslParser::BOOL, 0);
}

tree::TerminalNode* AslParser::TypeContext::FLOAT() {
  return getToken(AslParser::FLOAT, 0);
}

tree::TerminalNode* AslParser::TypeContext::CHAR() {
  return getToken(AslParser::CHAR, 0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
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
  enterRule(_localctx, 12, AslParser::RuleStatements);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AslParser::IF)
      | (1ULL << AslParser::WHILE)
      | (1ULL << AslParser::RETURN)
      | (1ULL << AslParser::READ)
      | (1ULL << AslParser::WRITE)
      | (1ULL << AslParser::ID))) != 0)) {
      setState(77);
      statement();
      setState(82);
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
  enterRule(_localctx, 14, AslParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::AssignStmtContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(83);
      left_expr();
      setState(84);
      match(AslParser::ASSIGN);
      setState(85);
      expr(0);
      setState(86);
      match(AslParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::IfStmtContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(88);
      match(AslParser::IF);
      setState(89);
      expr(0);
      setState(90);
      match(AslParser::THEN);
      setState(91);
      statements();
      setState(94);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == AslParser::ELSE) {
        setState(92);
        match(AslParser::ELSE);
        setState(93);
        statements();
      }
      setState(96);
      match(AslParser::ENDIF);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WhileStmtContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(98);
      match(AslParser::WHILE);
      setState(99);
      expr(0);
      setState(100);
      match(AslParser::DO);
      setState(101);
      statements();
      setState(102);
      match(AslParser::ENDWHILE);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ProcCallContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(104);
      ident();
      setState(105);
      match(AslParser::LPAR);
      setState(106);
      match(AslParser::RPAR);
      setState(107);
      match(AslParser::T__2);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReturnCallContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(109);
      match(AslParser::RETURN);
      setState(111);
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
        setState(110);
        expr(0);
      }
      setState(113);
      match(AslParser::T__2);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::ReadStmtContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(114);
      match(AslParser::READ);
      setState(115);
      left_expr();
      setState(116);
      match(AslParser::T__2);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteExprContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(118);
      match(AslParser::WRITE);
      setState(119);
      expr(0);
      setState(120);
      match(AslParser::T__2);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<AslParser::WriteStringContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(122);
      match(AslParser::WRITE);
      setState(123);
      match(AslParser::STRING);
      setState(124);
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
  enterRule(_localctx, 16, AslParser::RuleLeft_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Left_exprContext *>(_tracker.createInstance<AslParser::Just_identContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(127);
      ident();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Left_exprContext *>(_tracker.createInstance<AslParser::Left_array_accesContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(128);
      ident();
      setState(129);
      match(AslParser::LCOR);
      setState(130);
      expr(0);
      setState(131);
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
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, AslParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(149);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenthesisContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(136);
      match(AslParser::LPAR);
      setState(137);
      expr(0);
      setState(138);
      match(AslParser::RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(140);
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
      setState(141);
      expr(9);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Expr_array_accesContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(142);
      ident();
      setState(143);
      match(AslParser::LCOR);
      setState(144);
      expr(0);
      setState(145);
      match(AslParser::RCOR);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ValueContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(147);
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

    case 5: {
      _localctx = _tracker.createInstance<ExprIdentContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(148);
      ident();
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(168);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(166);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(151);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(152);
          dynamic_cast<ArithmeticContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == AslParser::DIV

          || _la == AslParser::MUL)) {
            dynamic_cast<ArithmeticContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(153);
          expr(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ArithmeticContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(154);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(155);
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
          setState(156);
          expr(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(157);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(158);
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
          setState(159);
          expr(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(160);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(161);
          dynamic_cast<LogicalContext *>(_localctx)->op = match(AslParser::AND);
          setState(162);
          expr(5);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(163);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(164);
          dynamic_cast<LogicalContext *>(_localctx)->op = match(AslParser::OR);
          setState(165);
          expr(4);
          break;
        }

        } 
      }
      setState(170);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
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
  enterRule(_localctx, 20, AslParser::RuleIdent);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
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
    case 9: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AslParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
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
  "type", "statements", "statement", "left_expr", "expr", "ident"
};

std::vector<std::string> AslParser::_literalNames = {
  "", "':'", "','", "';'", "'='", "'=='", "'!='", "'>'", "'>='", "'<='", 
  "'<'", "'not'", "'and'", "'or'", "'-'", "'/'", "'('", "')'", "'['", "']'", 
  "'+'", "'*'", "'var'", "'int'", "'bool'", "'float'", "'char'", "'if'", 
  "'then'", "'else'", "'endif'", "'while'", "'do'", "'endwhile'", "'return'", 
  "'func'", "'endfunc'", "'read'", "'write'"
};

std::vector<std::string> AslParser::_symbolicNames = {
  "", "", "", "", "ASSIGN", "EQUAL", "NEQ", "GT", "GE", "LE", "LT", "NOT", 
  "AND", "OR", "MINUS", "DIV", "LPAR", "RPAR", "LCOR", "RCOR", "PLUS", "MUL", 
  "VAR", "INT", "BOOL", "FLOAT", "CHAR", "IF", "THEN", "ELSE", "ENDIF", 
  "WHILE", "DO", "ENDWHILE", "RETURN", "FUNC", "ENDFUNC", "READ", "WRITE", 
  "INTVAL", "BOOLVAL", "FLOATVAL", "CHARVAL", "ID", "STRING", "COMMENT", 
  "WS"
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
    0x3, 0x30, 0xb0, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x6, 0x2, 0x1a, 0xa, 0x2, 0xd, 0x2, 
    0xe, 0x2, 0x1b, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x27, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x35, 0xa, 0x4, 0xc, 
    0x4, 0xe, 0x4, 0x38, 0xb, 0x4, 0x5, 0x4, 0x3a, 0xa, 0x4, 0x3, 0x5, 0x7, 
    0x5, 0x3d, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x40, 0xb, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x46, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0x49, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x7, 0x8, 0x51, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x54, 0xb, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x61, 0xa, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0x72, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x80, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x88, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x98, 0xa, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x7, 0xb, 0xa9, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xac, 0xb, 0xb, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x2, 0x3, 0x14, 0xd, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x2, 0x8, 0x3, 0x2, 0x19, 0x1c, 
    0x5, 0x2, 0xd, 0xd, 0x10, 0x10, 0x16, 0x16, 0x3, 0x2, 0x29, 0x2c, 0x4, 
    0x2, 0x11, 0x11, 0x17, 0x17, 0x4, 0x2, 0x10, 0x10, 0x16, 0x16, 0x3, 
    0x2, 0x7, 0xc, 0x2, 0xbe, 0x2, 0x19, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x39, 0x3, 0x2, 0x2, 0x2, 0x8, 0x3e, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x41, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x52, 0x3, 0x2, 0x2, 0x2, 0x10, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x14, 0x97, 0x3, 0x2, 0x2, 0x2, 0x16, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 0x18, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x1e, 0x7, 0x2, 0x2, 0x3, 0x1e, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x1f, 0x20, 0x7, 0x25, 0x2, 0x2, 0x20, 0x21, 0x7, 0x2d, 0x2, 0x2, 0x21, 
    0x22, 0x7, 0x12, 0x2, 0x2, 0x22, 0x23, 0x5, 0x6, 0x4, 0x2, 0x23, 0x26, 
    0x7, 0x13, 0x2, 0x2, 0x24, 0x25, 0x7, 0x3, 0x2, 0x2, 0x25, 0x27, 0x5, 
    0xc, 0x7, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x27, 0x28, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x5, 0x8, 0x5, 
    0x2, 0x29, 0x2a, 0x5, 0xe, 0x8, 0x2, 0x2a, 0x2b, 0x7, 0x26, 0x2, 0x2, 
    0x2b, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x2d, 0x2, 0x2, 0x2d, 
    0x2e, 0x7, 0x3, 0x2, 0x2, 0x2e, 0x2f, 0x5, 0xc, 0x7, 0x2, 0x2f, 0x36, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x7, 0x4, 0x2, 0x2, 0x31, 0x32, 0x7, 
    0x2d, 0x2, 0x2, 0x32, 0x33, 0x7, 0x3, 0x2, 0x2, 0x33, 0x35, 0x5, 0xc, 
    0x7, 0x2, 0x34, 0x30, 0x3, 0x2, 0x2, 0x2, 0x35, 0x38, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 0x5, 0xa, 0x6, 0x2, 0x3c, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x18, 0x2, 0x2, 
    0x42, 0x47, 0x7, 0x2d, 0x2, 0x2, 0x43, 0x44, 0x7, 0x4, 0x2, 0x2, 0x44, 
    0x46, 0x7, 0x2d, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4b, 0x7, 0x3, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0xc, 0x7, 
    0x2, 0x4c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x9, 0x2, 0x2, 0x2, 
    0x4e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x5, 0x10, 0x9, 0x2, 0x50, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x5, 0x12, 
    0xa, 0x2, 0x56, 0x57, 0x7, 0x6, 0x2, 0x2, 0x57, 0x58, 0x5, 0x14, 0xb, 
    0x2, 0x58, 0x59, 0x7, 0x5, 0x2, 0x2, 0x59, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x5b, 0x7, 0x1d, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x14, 0xb, 0x2, 0x5c, 
    0x5d, 0x7, 0x1e, 0x2, 0x2, 0x5d, 0x60, 0x5, 0xe, 0x8, 0x2, 0x5e, 0x5f, 
    0x7, 0x1f, 0x2, 0x2, 0x5f, 0x61, 0x5, 0xe, 0x8, 0x2, 0x60, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x63, 0x7, 0x20, 0x2, 0x2, 0x63, 0x80, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x65, 0x7, 0x21, 0x2, 0x2, 0x65, 0x66, 0x5, 0x14, 0xb, 0x2, 
    0x66, 0x67, 0x7, 0x22, 0x2, 0x2, 0x67, 0x68, 0x5, 0xe, 0x8, 0x2, 0x68, 
    0x69, 0x7, 0x23, 0x2, 0x2, 0x69, 0x80, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 
    0x5, 0x16, 0xc, 0x2, 0x6b, 0x6c, 0x7, 0x12, 0x2, 0x2, 0x6c, 0x6d, 0x7, 
    0x13, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x5, 0x2, 0x2, 0x6e, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0x71, 0x7, 0x24, 0x2, 0x2, 0x70, 0x72, 0x5, 0x14, 0xb, 
    0x2, 0x71, 0x70, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x80, 0x7, 0x5, 0x2, 0x2, 0x74, 
    0x75, 0x7, 0x27, 0x2, 0x2, 0x75, 0x76, 0x5, 0x12, 0xa, 0x2, 0x76, 0x77, 
    0x7, 0x5, 0x2, 0x2, 0x77, 0x80, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 
    0x28, 0x2, 0x2, 0x79, 0x7a, 0x5, 0x14, 0xb, 0x2, 0x7a, 0x7b, 0x7, 0x5, 
    0x2, 0x2, 0x7b, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0x28, 0x2, 
    0x2, 0x7d, 0x7e, 0x7, 0x2e, 0x2, 0x2, 0x7e, 0x80, 0x7, 0x5, 0x2, 0x2, 
    0x7f, 0x55, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x64, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x74, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x78, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x80, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x88, 0x5, 0x16, 0xc, 0x2, 0x82, 0x83, 0x5, 0x16, 0xc, 
    0x2, 0x83, 0x84, 0x7, 0x14, 0x2, 0x2, 0x84, 0x85, 0x5, 0x14, 0xb, 0x2, 
    0x85, 0x86, 0x7, 0x15, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x87, 0x82, 0x3, 0x2, 0x2, 0x2, 0x88, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x8, 0xb, 0x1, 0x2, 0x8a, 0x8b, 0x7, 
    0x12, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x14, 0xb, 0x2, 0x8c, 0x8d, 0x7, 0x13, 
    0x2, 0x2, 0x8d, 0x98, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x9, 0x3, 0x2, 
    0x2, 0x8f, 0x98, 0x5, 0x14, 0xb, 0xb, 0x90, 0x91, 0x5, 0x16, 0xc, 0x2, 
    0x91, 0x92, 0x7, 0x14, 0x2, 0x2, 0x92, 0x93, 0x5, 0x14, 0xb, 0x2, 0x93, 
    0x94, 0x7, 0x15, 0x2, 0x2, 0x94, 0x98, 0x3, 0x2, 0x2, 0x2, 0x95, 0x98, 
    0x9, 0x4, 0x2, 0x2, 0x96, 0x98, 0x5, 0x16, 0xc, 0x2, 0x97, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x97, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0xc, 0xa, 0x2, 0x2, 
    0x9a, 0x9b, 0x9, 0x5, 0x2, 0x2, 0x9b, 0xa9, 0x5, 0x14, 0xb, 0xb, 0x9c, 
    0x9d, 0xc, 0x9, 0x2, 0x2, 0x9d, 0x9e, 0x9, 0x6, 0x2, 0x2, 0x9e, 0xa9, 
    0x5, 0x14, 0xb, 0xa, 0x9f, 0xa0, 0xc, 0x8, 0x2, 0x2, 0xa0, 0xa1, 0x9, 
    0x7, 0x2, 0x2, 0xa1, 0xa9, 0x5, 0x14, 0xb, 0x9, 0xa2, 0xa3, 0xc, 0x6, 
    0x2, 0x2, 0xa3, 0xa4, 0x7, 0xe, 0x2, 0x2, 0xa4, 0xa9, 0x5, 0x14, 0xb, 
    0x7, 0xa5, 0xa6, 0xc, 0x5, 0x2, 0x2, 0xa6, 0xa7, 0x7, 0xf, 0x2, 0x2, 
    0xa7, 0xa9, 0x5, 0x14, 0xb, 0x6, 0xa8, 0x99, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0x9c, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0xa8, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xab, 0x15, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0xad, 0xae, 0x7, 0x2d, 0x2, 0x2, 0xae, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x1b, 0x26, 0x36, 0x39, 0x3e, 0x47, 0x52, 0x60, 0x71, 0x7f, 0x87, 
    0x97, 0xa8, 0xaa, 
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
