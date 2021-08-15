#pragma once
#include "nodeVisitor.h"
#include "json.h"
#include "fileNode.h";

class JSONNodeVisitor : public NodeVisitor {
protected:
    JSON value;
public:
    JSON getValue() {
        return value;
    }

	virtual void visit(FileNode* node) override {
        JSON res;
        if (node->nodes[0]->nodes.size()) {
            node->nodes[0]->nodes[0]->accept(this);
            res["class"] = value;
        }
        value = res;
    }
    
	virtual void visit(ClassNode* node) override {
        JSON res;
        auto& children = node->nodes[0]->nodes;
        children[1]->accept(this);
        res["className"] = value;
        children[2]->accept(this);
        res["inheritance"] = value;
        children[4]->accept(this);
        res["classElements"] = value;
        value = res;
    }
    
	virtual void visit(OPTNode* node) override {
        if (node->nodes.size() == 0)
            value = JSON();
        else
            node->nodes[0]->accept(this);
    }
    
	virtual void visit(StarNode* node) override {
        JSON res("[]");
        for (const auto& node : node->nodes) {
            node->accept(this);
            res.push(value);
        }
        value = res;
    }
    
	virtual void visit(PlusNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(OrNode* node) override {
        if (node->nodes.size() == 0)
            value = JSON();
        else
            node->nodes[0]->accept(this);
    }
    
	virtual void visit(TokenNode* node) override {
        value = "'" + node->value + "'";
    }
    
	virtual void visit(UntilTokenNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    

	virtual void visit(ClassElementNode* node) override {
        _ASSERT(node->nodes[0]->nodes.size());
        node->nodes[0]->nodes[0]->accept(this);
    }
    
	virtual void visit(ClassMemberNode* node) override {
        JSON res;
        res["which"] = node->name;
        if (node->nodes[0]->nodes.size()) {
            node->nodes[0]->nodes[0]->accept(this);
            res["member"] = value;
        }
        value = res;
    }
    
	virtual void visit(MemberVariableNode* node) override {
        JSON res;
        auto children = node->nodes[0]->nodes;
        res["which"] = node->name;
        children[0]->accept(this);
        res["qualifiers"] = value;
        children[1]->accept(this);
        res["type"] = value;
        children[2]->accept(this);
        res["name"] = value;
        value = res;
    }
    
	virtual void visit(MethodNode* node) override {
        JSON res;
        const auto children = node->nodes[0]->nodes;
        res["which"] = node->name;
        children[0]->accept(this);
        res["qualifiers"] = value;
        children[1]->accept(this);
        res["type"] = value;
        children[2]->accept(this);
        res["name"] = value;
        children[4]->accept(this);
        res["arguments"] = value;
        children[6]->accept(this);
        res["code"] = value;
        value = res;
    }
    
	virtual void visit(ClassMemberQualifiers* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(ConstructorNode* node) override {
        JSON res;
        const auto children = node->nodes[0]->nodes;
        res["which"] = node->name;
        children[0]->accept(this);
        res["qualifiers"] = value;
        children[1]->accept(this);
        res["type"] = value;
        children[2]->accept(this);
        res["name"] = value;
        children[3]->accept(this);
        res["arguments"] = value;
        children[5]->accept(this);
        res["code"] = value;
        value = res;
    }
    

	virtual void visit(ExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(AssignmentExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(ConditionalExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(OrExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(AndExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(BitOrExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(BitXorExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(BitAndExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(EqualityExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(CompareExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(BitShiftExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(AdditiveExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(MultiplicativeExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(UnaryExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(PostfixExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(ParenExpressionNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    

	virtual void visit(ClassInheritanceNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(MultipleInheritanceNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(SingleInheritanceNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(MacroNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(UsingNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    

	virtual void visit(StatementNode* node) override {
        return node->nodes[0]->accept(this);
    }

    virtual void visit(ExpressionStatementNode* node) override {
        JSON res;
        res["which"] = node->name;
        node->nodes[0]->nodes[0]->accept(this);
        res["expression"] = value;
        value = res;
    }
    
	virtual void visit(ElseStatementNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(IfStatementNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(ForStatementNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    

	virtual void visit(TypenameNode* node) override {
        JSON res;
        res["which"] = node->name;
        res["type"] = "[]";
        node->nodes[0]->nodes[0]->accept(this);
        res["type"].push(value);
        for (const auto& child : node->nodes[0]->nodes[1]->nodes) {
            child->accept(this);
            res["type"].push(value);
        }
        value = res;
    }
    
	virtual void visit(NSTypenameNode* node) override {
        JSON res;
        res["which"] = node->name;
        node->nodes[0]->nodes[1]->accept(this);
        res["type"] = value;
        value = res;
    }
    
	virtual void visit(TypenameListNode* node) override {
        JSON res;
        res["which"] = node->name;
        node->nodes[0]->nodes[1]->accept(this);
        res["type"] = value;
        value = res;
    }
    
	virtual void visit(TemplateTypenameNode* node) override {
        JSON res;
        res["which"] = node->name;
        node->nodes[0]->nodes[1]->accept(this);
        res["type"] = value;
        value = res;
    }
    
	virtual void visit(ParenthesisTypenameNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(PointerTypenameNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(PPPQualifierNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    

	virtual void visit(ArgumentsSignatureNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(InnerArgumentsNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(ParenArgumentsNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(BracketArgumentsNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(BraceArgumentsNode* node) override {
        JSON res;
        res["which"] = node->name;
        value = res;
    }
    
	virtual void visit(CodeBlockNode* node) override {
        node->nodes[0]->accept(this);
    }

    virtual void visit(BracedCodeBlockNode* node) override {
        node->nodes[0]->nodes[1]->accept(this);
    }
};