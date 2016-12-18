#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

#include "antlr4-runtime.h"

#include "rc_helper.h"
#include "rc_logger.h"
#include "rc_exception.h"
#include "rc_innerdata.h"
#include "RCdataLexer.h"
#include "RCdataGenerator.h"


using namespace antlr4;
using namespace antlr4::tree;



int main() {
	RCAddressSpace addrspace;     // addrspace[0] is the returned value of all the library function  in global
	
	StringPoolSpace stringpool;
	APDataSpace apaddr;
	CPDataSpace cpaddr;
	ToolDataSpace tooladdr;
	CoorDataSpace cooraddr;

	std::unordered_map<std::string, int> dataIndexMap;		// parser xml file and generator dataMap
	std::unordered_map<std::string, int> constIndexMap;	// the index of all the constants in addr space 
	std::unordered_map<std::string, int> funcMap;  	    // all library function map to check if designated function is existed

	RC_SymbolTable symbolTable(addrspace, stringpool, apaddr, cpaddr, tooladdr, cooraddr,
								dataIndexMap, constIndexMap, funcMap);

	std::ifstream infile("test/sample.tid");     
	ANTLRInputStream input(infile);     
	
	RCdataLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	RCdataParser parser(&tokens);
	ParseTree *tree = parser.prog();

	RCdataGenerator RG(symbolTable);
	try{
		RG.visit(tree);
	} catch(rc_exception &e) {
		e.what();
	} catch(std::exception &e) {
		std::cout << "C++ runtime exception" << std::endl;
	}
	
	Utility::printfDataIndexMap(dataIndexMap);
	Utility::printfStringPool(stringpool);
	Utility::printfAPDataSpace(apaddr);
	Utility::printfCPDataSpace(cpaddr);
	Utility::printfToolDataSpace(tooladdr);
	Utility::printfCoorDataSpace(cooraddr);
	Utility::printfAddrspace(addrspace);


	std::cout << tree->toStringTree(&parser) << std::endl;
	return 0;
}