#pragma once
#include "multipleInheritanceNode.h"

class ClassInheritanceNode : public Node {
public:
	baseCtor(ClassInheritanceNode);

	virtual void build() override {
		nodes = {
			_AND_
				MAKE(TokenNode)(COLON),
				MAKE(MultipleInheritanceNode)(),
			__
		};
	}
};
