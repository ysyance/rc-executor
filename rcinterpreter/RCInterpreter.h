
#pragma once

#include "RCRuntimeModel.h"

class RCInterpreter {
public:
	RCInterpreter(CodeModel &c) : code(c) {}

public:
	int execute() {
		std::cout << std::endl << "| ==== RC executor start ===>" << std::endl << std::endl;
		for(int i = 0; i < code.size(); i ++) {
			code[i]->execute(NULL);
		}
		std::cout << std::endl << " <=== RC executor stop ==== |" << std::endl << std::endl;
		return 0;
	}

public:
	CodeModel &code;
	int period;
}