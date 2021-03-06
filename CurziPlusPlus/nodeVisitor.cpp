#include "nodeVisitor.h"
#include "fileNode.h"

void NodeVisitor::default_behavior(Node* node) { throw std::exception("unsupported type"); }

void NodeVisitor::visit(Node* node) { default_behavior(node); }
void NodeVisitor::visit(OPTNode* node) { default_behavior(node); }
void NodeVisitor::visit(StarNode* node) { default_behavior(node); }
void NodeVisitor::visit(PlusNode* node) { default_behavior(node); }
void NodeVisitor::visit(CommaStarNode* node) { default_behavior(node); }
void NodeVisitor::visit(CommaPlusNode* node) { default_behavior(node); }
void NodeVisitor::visit(OrNode* node) { default_behavior(node); }
void NodeVisitor::visit(AndNode* node) { default_behavior(node); }
void NodeVisitor::visit(TokenNode_* node) { default_behavior(node); }
void NodeVisitor::visit(PublicToken* node) { default_behavior(node); }
void NodeVisitor::visit(ProtectedToken* node) { default_behavior(node); }
void NodeVisitor::visit(PrivateToken* node) { default_behavior(node); }
void NodeVisitor::visit(WordTokenNode* node) { default_behavior(node); }
void NodeVisitor::visit(NumberTokenNode* node) { default_behavior(node); }
void NodeVisitor::visit(UntilTokenNode* node) { default_behavior(node); }
void NodeVisitor::visit(IndentNode* node) { default_behavior(node); }
void NodeVisitor::visit(FileNode* node) { default_behavior(node); }
void NodeVisitor::visit(ClassNode* node) { default_behavior(node); }
void NodeVisitor::visit(FunctionNode* node) { default_behavior(node); }
void NodeVisitor::visit(ClassElementNode* node) { default_behavior(node); }
void NodeVisitor::visit(ClassMemberNode* node) { default_behavior(node); }
void NodeVisitor::visit(MemberVariableNode* node) { default_behavior(node); }
void NodeVisitor::visit(MethodNode* node) { default_behavior(node); }
void NodeVisitor::visit(ClassMemberQualifiers* node) { default_behavior(node); }
void NodeVisitor::visit(ConstructorNode* node) { default_behavior(node); }
void NodeVisitor::visit(ExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(AssignmentExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(ConditionalExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(OrExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(AndExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(EqualityExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(CompareExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(AdditiveExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(MultiplicativeExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(UnaryExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(PostfixExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(ParenExpressionNode* node) { default_behavior(node); }
void NodeVisitor::visit(ClassInheritanceNode* node) { default_behavior(node); }
void NodeVisitor::visit(MultipleInheritanceNode* node) { default_behavior(node); }
void NodeVisitor::visit(MacroNode* node) { default_behavior(node); }
void NodeVisitor::visit(UsingNode* node) { default_behavior(node); }
void NodeVisitor::visit(StatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(ExpressionStatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(ElseStatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(IfStatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(ForStatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(IForStatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(WhileStatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(ReturnStatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(BreakStatementNode* node) { default_behavior(node); }
void NodeVisitor::visit(TypenameNode* node) { default_behavior(node); }
void NodeVisitor::visit(NSTypenameNode* node) { default_behavior(node); }
void NodeVisitor::visit(TypenameListNode* node) { default_behavior(node); }
void NodeVisitor::visit(TypenameListNodeEndingWithRShift* node) { default_behavior(node); }
void NodeVisitor::visit(TemplateTypenameNode* node) { default_behavior(node); }
void NodeVisitor::visit(ParenthesisTypenameNode* node) { default_behavior(node); }
void NodeVisitor::visit(PointerTypenameNode* node) { default_behavior(node); }
void NodeVisitor::visit(PPPQualifierNode* node) { default_behavior(node); }
void NodeVisitor::visit(ArgumentsSignatureNode* node) { default_behavior(node); }
void NodeVisitor::visit(InnerArgumentsNode* node) { default_behavior(node); }
void NodeVisitor::visit(ParenArgumentsNode* node) { default_behavior(node); }
void NodeVisitor::visit(BracketArgumentsNode* node) { default_behavior(node); }
void NodeVisitor::visit(BraceArgumentsNode* node) { default_behavior(node); }
void NodeVisitor::visit(CodeBlockNode* node) { default_behavior(node); }
void NodeVisitor::visit(ColonIndentCodeBlockNode* node) { default_behavior(node); }
