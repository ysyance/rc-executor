#include "RCInterpreter.h"






int main() {
	// RCAddressSpace addrspace;     // addrspace[0] is the returned value of all the library function  in global
	
	// StringPoolSpace stringpool;
	// APDataSpace apaddr;
	// CPDataSpace cpaddr;
	// ToolDataSpace tooladdr;
	// CoorDataSpace cooraddr;

	// std::unordered_map<std::string, int> dataIndexMap;		// parser xml file and generator dataMap
	// std::unordered_map<std::string, int> constIndexMap;	// the index of all the constants in addr space 
	// std::unordered_map<std::string, int> funcMap;  	    // all library function map to check if designated function is existed

	// RC_SymbolTable symbolTable(addrspace, stringpool, apaddr, cpaddr, tooladdr, cooraddr,
	// 							dataIndexMap, constIndexMap, funcMap);

	// std::ifstream datafile("test/sample.tid");     
	// ANTLRInputStream datainput(datafile);     
	
	// RCdataLexer datalexer(&datainput);
	// CommonTokenStream datatokens(&datalexer);

	// RCdataParser dataparser(&datatokens);
	// ParseTree *datatree = dataparser.prog();

	// std::cout << datatree->toStringTree(&dataparser) << std::endl;

	// RCdataGenerator DG(symbolTable);
	// try{
	// 	DG.visit(datatree);
	// } catch(rc_exception &e) {
	// 	e.what();
	// } catch(std::exception &e) {
	// 	std::cout << "C++ runtime exception" << std::endl;
	// }
	
	// Utility::printfDataIndexMap(dataIndexMap);
	// Utility::printfStringPool(stringpool);
	// Utility::printfAPDataSpace(apaddr);
	// Utility::printfCPDataSpace(cpaddr);
	// Utility::printfToolDataSpace(tooladdr);
	// Utility::printfCoorDataSpace(cooraddr);
	// Utility::printfAddrspace(addrspace);

	// std::ifstream codeFile("test/sample.tip"); 
	// ANTLRInputStream codeInput(codeFile);

	// RCcodeLexer codeLexer(&codeInput);
	// CommonTokenStream codeTokens(&codeLexer);

	// RCcodeParser codeParser(&codeTokens);
	// ParseTree *codeTree = codeParser.prog();

	// std::cout << codeTree->toStringTree(&codeParser) << std::endl;

	// CodeModel code;

	// RCcodeGenerator CG(code, symbolTable);
	// try {
	// 	CG.visit(codeTree);
	// } catch(rc_exception &e) {
	// 	e.what();
	// } catch(std::exception &e) {
	// 	std::cout << "C++ runtime exception" << std::endl;
	// }

	// Utility::printfAPDataSpace(apaddr);
	// Utility::printfCPDataSpace(cpaddr);
	// Utility::printfAddrspace(addrspace);
	// Utility::printfCodeShadow(code);

	RCInterpreter executor("test", "test/sample");
	try{
		executor.compile();
		executor.execute();
	} catch(rc_exception &e) {
		e.what();
	} catch(std::exception &e) {
		std::cout << "C++ runtime exception" << std::endl;
	}
	

	return 0;
}