#pragma once
#include "tokenNode.h"
#include "andorNode.h"
#include "macros.h"

class PPPQualifierNode : public Node {
public:
	baseCtor(PPPQualifierNode);

	virtual void build() override {
		this->nodes = {
			_OR_
				MAKE(TokenNode)(PRIVATE),
				MAKE(TokenNode)(PROTECTED),
				MAKE(TokenNode)(PUBLIC)
			__
		};
	}

	virtual void accept(NodeVisitor* v) override {
		v->visit(this);
	}
};
