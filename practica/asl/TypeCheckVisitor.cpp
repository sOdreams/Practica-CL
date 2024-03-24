//////////////////////////////////////////////////////////////////////
//
//    TypeCheckVisitor - Walk the parser tree to do the semantic
//                       typecheck for the Asl programming language
//
//    Copyright (C) 2020-2030  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "TypeCheckVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;


// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr       & Types,
                                   SymTable       & Symbols,
                                   TreeDecoration & Decorations,
                                   SemErrors      & Errors) :
  Types{Types},
  Symbols{Symbols},
  Decorations{Decorations},
  Errors{Errors} {
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId TypeCheckVisitor::getCurrentFunctionTy() const {
  return currFunctionType;
}

void TypeCheckVisitor::setCurrentFunctionTy(TypesMgr::TypeId type) {
  currFunctionType = type;
}

// Methods to visit each kind of node:
//
antlrcpp::Any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx) {
  DEBUG_ENTER();
  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  for (auto ctxFunc : ctx->function()) { 
    visit(ctxFunc);
  }
  if (Symbols.noMainProperlyDeclared())
    Errors.noMainProperlyDeclared(ctx);
  Symbols.popScope();
  Errors.print();
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx) {
  DEBUG_ENTER();

  //tipo return de la funcion en scope
  std::vector<TypesMgr::TypeId> lParamsTy;
  TypesMgr::TypeId tRet = Types.createVoidTy();
  if (ctx->basic_type() != NULL){
    //visit(ctx->basic_type());   //no haria falta, basic_type ya se visito en Symbols.
    tRet = getTypeDecor(ctx->basic_type());
  }
  TypesMgr::TypeId tFunc = Types.createFunctionTy(lParamsTy, tRet); //tipo funcion en scope
  setCurrentFunctionTy(tFunc);

  SymTable::ScopeId sc = getScopeDecor(ctx);
  Symbols.pushThisScope(sc);
  // Symbols.print();
  visit(ctx->statements());
  Symbols.popScope();
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// antlrcpp::Any TypeCheckVisitor::visitType(AslParser::TypeContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx) {
  DEBUG_ENTER();
  visitChildren(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());

  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.copyableTypes(t1, t2)))
    Errors.incompatibleAssignment(ctx->ASSIGN());
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableLeftExpr(ctx->left_expr());
  DEBUG_EXIT();
  return 0;
}


//IF expr THEN statements (ELSE statements)? ENDIF       # ifStmt

antlrcpp::Any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  //decora la expresion (debe ser de tipo BOOL)
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);
  visit(ctx->statements(0)); //hay dos statements el del if y el del else

  //caso de que haya un ELSE
  if(ctx->ELSE()){
    visit(ctx->statements(1));
  }

  DEBUG_EXIT();
  return 0;
}


//WHILE expr DO statements ENDWHILE                       #whileStmt

antlrcpp::Any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx) {
  DEBUG_ENTER();
  //comprueba que la expresion sea BOOLEAN
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    Errors.booleanRequired(ctx);

  visit(ctx->statements());
  DEBUG_EXIT();
  return 0;
}


antlrcpp::Any TypeCheckVisitor::visitProcCall(AslParser::ProcCallContext *ctx) {
  DEBUG_ENTER();
  //si t1 no es una ID valida de una funcion --> error not callable

    // Visit and evaluate the identifier
    visit(ctx->ident());
    TypesMgr::TypeId FuncID = getTypeDecor(ctx->ident());

    //visit parameters
    for (size_t i = 0; i < (ctx->expr()).size(); ++i) {  //visitamo parametros
          visit(ctx->expr(i));
    }

    if(not Types.isFunctionTy(FuncID) and not Types.isErrorTy(FuncID) ){
        Errors.isNotCallable(ctx->ident());
    }

    //si es una functionTy -> no sera un errorTy
    else if (not Types.isErrorTy(FuncID)) {

        // Get the expected parameter types of the function
        std::vector<TypesMgr::TypeId> ParametrosFunction = Types.getFuncParamsTypes(FuncID);
        // Check if the number of parameters matches
        if (ctx->expr().size() != Types.getNumOfParameters(FuncID)) {
            Errors.numberOfParameters(ctx->ident());
        }
        else{

          // Check the type compatibility of each parameter
          for (unsigned long int i = 0; i < ctx->expr().size(); ++i) {
              visit(ctx->expr(i));
              TypesMgr::TypeId typeExpr = getTypeDecor(ctx->expr(i));

              if (!Types.equalTypes(typeExpr, ParametrosFunction[i])) {
                  Errors.incompatibleParameter(ctx->expr(i), ctx->expr().size(), ctx->ident());
              }
          }
        }
  
    }

  DEBUG_EXIT();
  return 0;
}



// ident LCOR expr RCOR       # left_array_acces
antlrcpp::Any TypeCheckVisitor::visitLeft_array_acces(AslParser::Left_array_accesContext *ctx){
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  visit(ctx->expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());

  bool es_array = (not Types.isErrorTy(t1));

  if(((not Types.isErrorTy(t1)) and (not Types.isArrayTy(t1)))){ // aqui entra si t1 no es un array
      Errors.nonArrayInArrayAccess(ctx->ident());
      es_array = false;
      t1 = Types.createErrorTy();
  }
  
  if (((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2)))) //aqui entra si el indice no es un numero entero
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());


//t1 es un identificador, necesito decorarlo cnoo el tipo de los valores del array
  if(es_array){
    t1 = Types.getArrayElemType(t1);
  }

  putTypeDecor(ctx, t1);
  putIsLValueDecor(ctx, true);
  DEBUG_EXIT();
  return 0;
}

// ident LCOR expr RCOR       # expr_array_acces
antlrcpp::Any TypeCheckVisitor::visitExpr_array_acces(AslParser::Expr_array_accesContext *ctx){
DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  visit(ctx->expr());
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());

  bool es_array = (not Types.isErrorTy(t1));

  if(((not Types.isErrorTy(t1)) and (not Types.isArrayTy(t1)))){
      Errors.nonArrayInArrayAccess(ctx->ident());
      es_array = false;
      t1 = Types.createErrorTy();
  }
  
  if (((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2))))
    Errors.nonIntegerIndexInArrayAccess(ctx->expr());

  if(es_array){
    t1 = Types.getArrayElemType(t1);
  }

  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}



antlrcpp::Any TypeCheckVisitor::visitReturnCall(AslParser::ReturnCallContext *ctx) {
  DEBUG_ENTER();
  //para el ejercicio 3, las funciones o hacen return (void) o no hacen return.
  //esta funcion tiene pinta de que habrá que ver primero de que tipo retorna la funcion en la
  //que se llama el return. luego habra que ver que haya match entre el tipo que retorna la funcion (void o etc)
  //y el return

  //modificacion para el ejercicio 4, que haya match entre return call y return de la funcion
  //funciones que creo que son relevantes del typemgr --> getFuncReturnType
  // funciones para saber la funcion actual --> Symbols
  

  TypesMgr::TypeId f = getCurrentFunctionTy();

   if(ctx->expr()) { //si es un return con expresion , tiene que hacer match con el return de la funcion, si es sin expresion, tiene que hacer match con void
     visit(ctx->expr());
     TypesMgr::TypeId tipoReturnFuncion = Types.getFuncReturnType(f);
     TypesMgr::TypeId tipoReturn = getTypeDecor(ctx->expr());

  //No hace falta comprobar si tipoReturnFuncion es errorty, ya que ya se hace en visitfunction
     if(not Types.isErrorTy(tipoReturn) && Types.isVoidFunction(f)) Errors.incompatibleReturn(ctx->RETURN());
     else if ((not Types.isErrorTy(tipoReturn)) and (not Types.equalTypes(tipoReturn, tipoReturnFuncion))){
      if (not (Types.isIntegerTy(tipoReturn) and Types.isFloatTy(tipoReturnFuncion))) {
       Errors.incompatibleReturn(ctx->RETURN());   //tipos diferentes en el return, aunque si la funcion es float y retornas int(es correcto)
      }
     }
    }
    //la funcion no es void, pero se pone por erro un return normal
    else if (not Types.isVoidFunction(f)) Errors.incompatibleReturn(ctx->RETURN());  //salida void, funcion no voidelse 
  
  DEBUG_EXIT();
  return 0;

}


//        | READ left_expr ';'                  # readStmt


antlrcpp::Any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->left_expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
      (not Types.isFunctionTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
    Errors.nonReferenceableExpression(ctx);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
    Errors.readWriteRequireBasic(ctx);
  DEBUG_EXIT();
  return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
//   DEBUG_ENTER();
//   antlrcpp::Any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

antlrcpp::Any TypeCheckVisitor::visitJust_ident(AslParser::Just_identContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());

  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  TypesMgr::TypeId t = Types.createIntegerTy();

  if (ctx->MOD()) {   //MOD solo a enteros
     if (((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1))) or 
        ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2))))
        Errors.incompatibleOperator(ctx->op);
  }
  else {
    if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
        ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
      Errors.incompatibleOperator(ctx->op);

    if(Types.isFloatTy(t1) or Types.isFloatTy(t2)){  //CONVERSION A FLOAT
      t = Types.createFloatTy();
    }
  }
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx) {//EQ,NEQ.. COmprobar que son comparableTypes()
  DEBUG_ENTER();
  visit(ctx->expr(0));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  std::string oper = ctx->op->getText();
  if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
      (not Types.comparableTypes(t1, t2, oper)))
    Errors.incompatibleOperator(ctx->op);

  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitValue(AslParser::ValueContext *ctx) {
  DEBUG_ENTER();
  if (ctx->INTVAL()) {
    TypesMgr::TypeId t = Types.createIntegerTy();
    putTypeDecor(ctx, t);
  }
  else if(ctx ->FLOATVAL()){
    TypesMgr::TypeId t = Types.createFloatTy();
    putTypeDecor(ctx, t);
  }
  else if (ctx->BOOLVAL()) {
    TypesMgr::TypeId t = Types.createBooleanTy();
    putTypeDecor(ctx, t);
  }
  else if (ctx->CHARVAL()) {
    TypesMgr::TypeId t = Types.createCharacterTy();
    putTypeDecor(ctx, t);
  }
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx) {
  DEBUG_ENTER();
  visit(ctx->ident());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
  putTypeDecor(ctx, t1);
  bool b = getIsLValueDecor(ctx->ident());
  putIsLValueDecor(ctx, b);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx) {
  DEBUG_ENTER();
  std::string ident = ctx->getText();
  if (Symbols.findInStack(ident) == -1) {
    Errors.undeclaredIdent(ctx->ID());
    TypesMgr::TypeId te = Types.createErrorTy();
    putTypeDecor(ctx, te);
    putIsLValueDecor(ctx, true);
  }
  else {
    TypesMgr::TypeId t1 = Symbols.getType(ident);
    putTypeDecor(ctx, t1);
    if (Symbols.isFunctionClass(ident))
      putIsLValueDecor(ctx, false);
    else
      putIsLValueDecor(ctx, true);
  }
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitUnary(AslParser::UnaryContext *ctx){ //2 casos, si es NOT o numero_negativo
  DEBUG_ENTER();
  if (ctx->NOT()) {
    visit(ctx->expr());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

    if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))))
      Errors.incompatibleOperator(ctx->op);

    TypesMgr::TypeId t = Types.createBooleanTy();
    putTypeDecor(ctx, t);
  }
  else if(ctx->MINUS()){//otros 2 casos, -int, -float
    visit(ctx->expr());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

    if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))))
      Errors.incompatibleOperator(ctx->op);

    if(Types.isFloatTy(t1)){
      TypesMgr::TypeId t = Types.createFloatTy();
      putTypeDecor(ctx, t);
    }
    else{
      TypesMgr::TypeId t = Types.createIntegerTy();
      putTypeDecor(ctx, t);
    }
  }
  else if (ctx -> PLUS()){
    visit(ctx->expr());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());

    if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))))
      Errors.incompatibleOperator(ctx->op);

    if(Types.isFloatTy(t1)){
      TypesMgr::TypeId t = Types.createFloatTy();
      putTypeDecor(ctx, t);
    }
    else{
      TypesMgr::TypeId t = Types.createIntegerTy();
      putTypeDecor(ctx, t);
    }

  }
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx){ //decorar el nodo con el tipo de ("expr") directamenre
  visit(ctx->expr());
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
  putTypeDecor(ctx, t1);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitLogical(AslParser::LogicalContext *ctx){ //AND y OR, solo pueden ser con BOOLS: isBooleanTy()
  DEBUG_ENTER();
  visit(ctx->expr(0));
  visit(ctx->expr(1));
  TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
  TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));

  if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
      ((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2))))
    Errors.incompatibleOperator(ctx->op);

  TypesMgr::TypeId t = Types.createBooleanTy();
  putTypeDecor(ctx, t);
  putIsLValueDecor(ctx, false);
  DEBUG_EXIT();
  return 0;
}

antlrcpp::Any TypeCheckVisitor::visitFunc_call(AslParser::Func_callContext *ctx) {
    DEBUG_ENTER();
    
    // Visit and evaluate the identifier
    visit(ctx->ident());
    TypesMgr::TypeId FuncID = getTypeDecor(ctx->ident());
     TypesMgr::TypeId tipoReturn = Types.createErrorTy();
    // Check if FuncID corresponds to a function

    //std::cout << ctx->ident()->getText()<< "type: " << Types.to_string(getTypeDecor(ctx->ident())) << std::endl;

    if(not Types.isFunctionTy(FuncID) and not Types.isErrorTy(FuncID)){
        Errors.isNotCallable(ctx->ident());
    }

    //si es una functionTy -> no sera un errorTy
    if (Types.isFunctionTy(FuncID)) {

        // Get the return type of the function
        tipoReturn = Types.getFuncReturnType(FuncID);
        
        // Check if the function returns void
        if (Types.isVoidFunction(FuncID)) {
            Errors.isNotFunction(ctx->ident());
            tipoReturn = Types.createErrorTy();
        }

        // Get the expected parameter types of the function
        std::vector<TypesMgr::TypeId> ParametrosFunction = Types.getFuncParamsTypes(FuncID);
        // Check if the number of parameters matches
        if (ctx->expr().size() != Types.getNumOfParameters(FuncID)) {
            Errors.numberOfParameters(ctx->ident());
        }

        else{
          // Check the type compatibility of each parameter
          for (unsigned long int i = 0; i < ctx->expr().size(); ++i) {
              visit(ctx->expr(i));
              TypesMgr::TypeId typeExpr = getTypeDecor(ctx->expr(i));

              if (!Types.equalTypes(typeExpr, ParametrosFunction[i])) {
                if (not Types.isErrorTy(typeExpr) and not (Types.isIntegerTy(typeExpr) and Types.isFloatTy(ParametrosFunction[i])))
                  Errors.incompatibleParameter(ctx->expr(i), i+1, ctx);
              }
          }
        }
    }
    else{
      for (unsigned long int i = 0; i < ctx->expr().size(); ++i) visit(ctx->expr(i));
    } 

    // Decorate the return type
    putTypeDecor(ctx, tipoReturn);
    putIsLValueDecor(ctx, false);
    
    DEBUG_EXIT();
    return 0;
}

// antlrcpp::Any TypeCheckVisitor::visitProcedure_call(AslParser::Procedure_callContext *ctx) {
//     DEBUG_ENTER();
    
//     // Visit and evaluate the identifier
//     visit(ctx->ident());
//     TypesMgr::TypeId FuncID = getTypeDecor(ctx->ident());

//     // Check if FuncID corresponds to a function
//     if (Types.isFunctionTy(FuncID)) {

//         // Get the return type of the function
//         TypesMgr::TypeId tipoReturn = Types.getFuncReturnType(FuncID);
        
//         // // Check if the function returns void
//         // if (Types.isVoidFunction(FuncID)) {
//         //     Errors.isNotCallable(ctx->ident());
//         // } AHORA SI PUEDE SER VOID, DE HECHO DEBERIA SER VOID

//         // Get the expected parameter types of the function
//         std::vector<TypesMgr::TypeId> ParametrosFunction = Types.getFuncParamsTypes(FuncID);

//         // Check if the number of parameters matches
//         if (ctx->expr().size() != ParametrosFunction.size()) {
//             Errors.numberOfParameters(ctx->ident());
//         }

//         // Check the type compatibility of each parameter
//         for (unsigned long int i = 0; i < ctx->expr().size(); ++i) {
//             visit(ctx->expr(i));
//             TypesMgr::TypeId typeExpr = getTypeDecor(ctx->expr(i));

//             if (!Types.equalTypes(typeExpr, ParametrosFunction[i])) {
//                 Errors.incompatibleParameter(ctx->expr(i), ctx->expr().size(), ctx->ident());
//             }
//         }

//         // Decorate the return type
//         putTypeDecor(ctx, tipoReturn);
//         putIsLValueDecor(ctx, false);
//     } else  if(((not Types.isErrorTy(FuncID)) and (not Types.isFunctionTy(FuncID)))){
//         Errors.isNotFunction(ctx->ident());}

//     DEBUG_EXIT();
//     return 0;
// }


// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getType(ctx);
}
bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx) {
  return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s) {
  Decorations.putScope(ctx, s);
}
void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t) {
  Decorations.putType(ctx, t);
}
void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b) {
  Decorations.putIsLValue(ctx, b);
}


