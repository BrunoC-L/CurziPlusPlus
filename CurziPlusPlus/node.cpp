#include "node.h"
#include "grammarizer.h"

bool Node::build(Grammarizer* g) {
	build();
#ifdef DEBUG
	_ASSERT(name != "Node");
	const auto& indent = g->getIndent();
	std::cout << indent << name << "\n";
	g->inc();
	bool worked = nodes[0]->build(g);
	g->dec();
	std::cout << indent << name << (worked ? " worked" : " failed") << "\n";
	return worked;
#else
	return nodes[0]->build(g);
#endif // DEBUG
}

JSON Node::toJSON() {
	return nodes[0]->toJSON();
}
