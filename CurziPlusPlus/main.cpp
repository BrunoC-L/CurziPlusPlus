#include <iostream>
#include <fstream>
#include "fileNode.h"
#include <algorithm>
#include <filesystem>
#include "JSONNodeVisitor.h"
#include "simpleJSONVisitor.h"
#include "cppElements.h"

auto green = "\033[1;32m", red = "\033[1;31m", reset = "\033[0m";
std::string testfolder = "";

void test(int i, std::tuple<std::shared_ptr<Node>, std::string>&& testCase) {
	std::string& program = get<std::string>(testCase);
	std::shared_ptr<Node>& expected = get<std::shared_ptr<Node>>(testCase);
	std::forward_list<TOKENVALUE> tokens(Tokenizer(program).read());
	Grammarizer g(tokens);
	bool nodeBuilt = expected->build(&g);
	bool programReadEntirely = g.it == g.tokens.end() || (++g.it) ==  g.tokens.end(); // need to also parse END token for most rules during tests (only FileNode expects END)
	auto nodeBuiltColor = nodeBuilt ? green : red;
	auto programReadEntirelyColor = programReadEntirely ? green : red;
	std::cout << i << (i < 10 ? " : " : ": ")
		<< "built: " << nodeBuiltColor << nodeBuilt << reset
		<< ", entirely: " << programReadEntirelyColor << programReadEntirely << reset << "\n";
	if (!nodeBuilt || !programReadEntirely)
		std::cout << program << "\n\n";
	if (nodeBuilt) {
		auto outFileName = testfolder + "/" + std::to_string(i) + ".json";
		JSONNodeVisitor v;
		expected->accept(&v);
		JSON out = v.getValue();
		std::ofstream output(outFileName);
		auto b = output.is_open();
		output << out.asString("  ", false) << std::endl;
		output.close();
	}
}

void test() {
	for (const auto& entry : std::filesystem::directory_iterator(testfolder))
		std::filesystem::remove_all(entry.path());
	test(__LINE__, { MAKE(ClassNode)(""), "class A:\n" });
	test(__LINE__, { MAKE(ClassNode)(""), "class A extends B:\n" });
	test(__LINE__, { MAKE(ClassNode)(""), "class A extends B:\n\tA a\n" });
	test(__LINE__, { MAKE(ClassNode)(""), "class A extends B:\n\tA a\n\tA a\n\tA a\n\tA a\n" });
	test(__LINE__, { MAKE(ClassNode)("", 1), "class A extends B:\n\t\tA a\n\t\tA a\n\t\tA a\n\t\tA a\n" });
	test(__LINE__, { MAKE(ClassNode)("", 1), "class A extends B:\n\t\tA a\n" });
	test(__LINE__, { MAKE(IfStatementNode)(""), "if a:\n" });
	test(__LINE__, { MAKE(StatementNode)(""), "if a:\n" });
	test(__LINE__, { MAKE(IfStatementNode)(""), "if a:\n\tb\n" });
	test(__LINE__, { MAKE(IfStatementNode)(""), "if a:\n\tif a:\n\t\tb\n" });
	test(__LINE__, { MAKE(IfStatementNode)("", 1), "if a:\n\t\tb\n" });
	test(__LINE__, { MAKE(ForStatementNode)(""), "for a in b:\n\tb\n" });
	test(__LINE__, { MAKE(ForStatementNode)(""), "for a in b:\n" });
	test(__LINE__, { MAKE(StatementNode)(""), "for a in b:\n\tif a:\n\t\tb\n" });
	test(__LINE__, { MAKE(StatementNode)(""), "for i in arr:\n" });
	test(__LINE__, { MAKE(MethodNode)(""), "private static E<F<H,I>>::G method1(K k, U u, R<U,E<H>,I>::V kuv):\n" });
	test(__LINE__, { MAKE(MethodNode)("", 1), "private static E<F<H,I>>::G method1(K k, U u, R<U,E<H>,I>::V kuv):\n\n\n\t\n\t\n\n\t\tfor i in arr:\n" });
	test(__LINE__, { MAKE(ClassNode)(""), "class A extends F<H, I>:\n\tprivate static E<F<H,I>>::G method1(K k, U u, R<U,E<H>,I>::V kuv):\n" });
	test(__LINE__, { MAKE(ClassNode)(""), "class A extends F<H, I>:\n\tprivate static E<F<H,I>>::G method1(K k, U u, R<U,E<H>,I>::V kuv):\n\t\tfor i in arr:\n" });
	test(__LINE__, { MAKE(MethodNode)("", 1), "private static E<F<H,I>>::G method1(K k, U u, R<U,E<H>,I>::V kuv):\n" });
	test(__LINE__, { MAKE(MethodNode)("", 1), "private static E<F<H,I>>::G method1(K k, U u, R<U,E<H>,I>::V kuv):\n\t\tfor i in arr:\n" });
	test(__LINE__, { MAKE(ClassElementNode)("", 1), "private static E<F<H,I>>::G method1(K k, U u, R<U,E<H>,I>::V kuv):\n\t\tfor i in arr:\n" });
	test(__LINE__, { MAKE(StatementNode)("", 1), "\tfor i in arr:\n" });
	test(__LINE__, { MAKE(MethodNode)(""), "void a():\n" });
	test(__LINE__, { MAKE(CodeBlockNode)("", 1), "\tif a:\n" });
	test(__LINE__, { MAKE(WhileStatementNode)(""), "while a:\n" });
	test(__LINE__, { MAKE(ReturnStatementNode)(""), "return a, b, \n" });
	test(__LINE__, { MAKE(ReturnStatementNode)(""), "return a, b\n" });
}

void toJSON(const std::filesystem::path& fileName, const std::string& outFileNameNoExt) {
	std::string program;
	{
		std::ifstream input(fileName);
		std::stringstream buffer;
		buffer << input.rdbuf();
		program = buffer.str();
	}
	std::forward_list<TOKENVALUE> tokens(Tokenizer(program).read());
	Grammarizer g(tokens);
	std::unique_ptr<Node> expected = std::make_unique<FileNode>("file");
	bool nodeBuilt = expected->build(&g);
	bool programReadEntirely = g.it == g.tokens.end();
	auto nodeBuiltColor = nodeBuilt ? green : red;
	auto programReadEntirelyColor = programReadEntirely ? green : red;
	std::cout << fileName
		<< "built: " << nodeBuiltColor << nodeBuilt << reset
		<< ", entirely: " << programReadEntirelyColor << programReadEntirely << reset << "\n";
	if (!nodeBuilt || !programReadEntirely) {
		for (const auto& t : tokens) {
			if (t.second[0] != '\\')
				std::cout << t.second;
			else if (t.second[1] == 'n') {
				std::cout << "\n";
			}
			else if (t.second[1] == 't') {
				std::cout << "\t";
			}
			else if (t.second[1] == '\\') {
				std::cout << "\\";
			}
		}
		std::cout << "\n\n";
	}
	if (nodeBuilt && programReadEntirely) {
		SimpleJSONNodeVisitor v;
		expected->accept(&v);
		const JSON& out = v.getValue();
		std::string jsonFN = outFileNameNoExt + ".json";
		std::ofstream output(jsonFN);
		auto is_open = output.is_open();
		if (!is_open)
			throw std::exception();
		output << out.asString("  ", false) << std::endl;
	}
}

void toCPP(const std::string& inFileNameNoExt, const std::string& outFileNameNoExt) {
	std::ifstream json(inFileNameNoExt + ".json");
	std::ofstream h(outFileNameNoExt + ".h", std::ios::trunc);
	std::ofstream cpp(outFileNameNoExt + ".cpp", std::ios::trunc);
	auto json_is_open = json.is_open();
	auto h_is_open = h.is_open();
	auto cpp_is_open = cpp.is_open();
	if (!h_is_open)
		throw std::exception();
	if (!cpp_is_open)
		throw std::exception();
	if (!json_is_open)
		throw std::exception();
	std::string filecontent;
	std::getline(json, filecontent, '\0');
	const JSON jsonfile(filecontent);
	stream s;
	const CPPelementFactory factory;
	File(s, jsonfile, factory).toString(0);
	h << s.header.str();
}

void transpile(const std::filesystem::path& fileName, std::string folder) {
	const std::string outFileNameNoExt = folder + std::string(reinterpret_cast<const char*>(fileName.stem().c_str())) + +"/out";
	toJSON(fileName, outFileNameNoExt);
	//toCPP(outFileNameNoExt, outFileNameNoExt);
}

int main(int argc, char* argv[]) {
	auto folder = std::string(argv[1]); // github repo "tests" folder path without a trailing '/'
	testfolder = folder + "/out/tests";
	std::cout << std::boolalpha;
	test();
	std::cout << "\n\n";
	for (int i = 1; i < argc; ++i)
		for (const auto& file : std::filesystem::directory_iterator(argv[i])) {
			const std::filesystem::path& fileName = file.path();
			if (fileName.extension() == ".curzi")
				transpile(fileName, std::string(argv[i]) + "\\out\\");
		}
	return 0;
}
