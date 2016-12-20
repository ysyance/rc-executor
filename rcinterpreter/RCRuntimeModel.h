#pragma once

#include "rc_innerdata.h"
#include "rc_exception.h"
#include "rc_logger.h"


class RCBaseStatement {
public:

	RCBaseStatement(RC_SymbolTable &sym) :
				addrspace(sym.addrspace),
				stringpool(sym.stringpool),
				apaddr(sym.apaddr),
				cpaddr(sym.cpaddr),
				tooladdr(sym.tooladdr),
				cooraddr(sym.cooraddr), 
				lineno(0)
	{}

	virtual int execute(void *cookie) = 0;
	virtual void printInfo() {
		std::cout << "RCBaseStatement" << std::endl;
	}

public:
	RCAddressSpace &addrspace;     // addrspace[0] is the returned value of all the library function  in global
	
	StringPoolSpace &stringpool;
	APDataSpace &apaddr;
	CPDataSpace &cpaddr;
	ToolDataSpace &tooladdr;
	CoorDataSpace &cooraddr;

	int lineno;
};


class RCCallStatement : public RCBaseStatement {
public:
	RCCallStatement(RC_SymbolTable &sym) :  RCBaseStatement(sym)
											 {}
public:
	virtual int execute(void *cookie) override {

	}

public:
	std::string programName;

public:
	virtual void printInfo() override {
		std::cout << "[Line " << lineno << "] ";
		std::cout << "Call " << programName << std::endl;
	}
	
};


class RCSingleInstStatemement : public RCBaseStatement {
public:
	enum INST_TYPE{
		NONE = 0, RET = 1, NOP = 2, PAUSE = 3, HALT = 4, BREAK = 5, LABEL = 6
	};
public:
	RCSingleInstStatemement(RC_SymbolTable &sym) :  RCBaseStatement(sym), 
											type(NONE)
											 {}
public:
	virtual int execute(void *cookie) override {
		switch(type) {
			case RET:
			break;
			case NOP:
			break;
			case PAUSE:
			break;
			case HALT:
			break;
			case BREAK:
			break;
			case LABEL:
			break;
			default:
			break;
		}

	}

public:
	INST_TYPE type;

public:
	virtual void printInfo() {
		std::cout << "[Line " << lineno << "] ";
		if(type == RET) std::cout << "RET" << std::endl;
		else if(type == NOP) std::cout << "NOP" << std::endl;
		else if(type == PAUSE) std::cout << "PAUSE" << std::endl;
		else if(type == HALT) std::cout << "HALT" << std::endl;
		else if(type == BREAK) std::cout << "BREAK" << std::endl;
		else if(type == LABEL) std::cout << "LABEL" << std::endl;
	}
};


class RCRobotStatement : public RCBaseStatement {
public:
	enum INST_TYPE {
		NONE = 0, MOVJ = 1, MOVL = 2, MOVC = 3, MOVS = 4, SHIFTON = 5, SHIFTOFF = 6
	};
	enum RESO_LEVEL {
		Z0 = 0, Z1 = 1, Z2 = 2, Z3 = 3, Z4 = 4, Z5 = 5, Z6 = 6, Z7 = 7, Z8 = 8
	};
public:
	RCRobotStatement(RC_SymbolTable &sym) :  RCBaseStatement(sym), 
											type(NONE),
											endpointIndex(0),
											midpointIndex(0),
											speed(0),
											Z(Z0)
											 {}
public:
	virtual int execute(void *cookie) override {
		switch(type) {
			case MOVJ:
			break;
			case MOVL:
			break;
			case MOVC:
			break;
			case MOVS:
			break;
			case SHIFTON:
			break;
			case SHIFTOFF:
			break;
			default:
			break;
		}
	}
public:
	INST_TYPE type;
	uint32_t endpointIndex;
	uint32_t midpointIndex;
	uint32_t speed;
	RESO_LEVEL Z;
	std::string frame;

public:
	virtual void printInfo() override{
		std::cout << "[Line " << lineno << "]";
		if(type == MOVJ) 
			std::cout << " MOVJ " << endpointIndex << " V" << speed << " Z" << Z << std::endl;
		if(type == MOVL) 
			std::cout << " MOVL " << endpointIndex << " V" << speed << " Z" << Z << std::endl;
		if(type == MOVC)
			std::cout << " MOVC " << endpointIndex << " " << midpointIndex << " V" << speed << " Z" << Z << std::endl;
		if(type == MOVS)
			std::cout << " MOVS " << endpointIndex << " " << midpointIndex << " V" << speed << " Z" << Z << std::endl;
		if(type == SHIFTON)
			std::cout << " SHIFTON " << endpointIndex << " " << frame << std::endl;
		if(type == SHIFTOFF)
			std::cout << " SHIFTOFF" << std::endl;
	}

};




class RCDataStatement : public RCBaseStatement {
public:
	enum INST_TYPE {
		NONE = 0, SET = 1, SETE = 2, GETE = 3
	};
public:
	RCDataStatement(RC_SymbolTable &sym) :  RCBaseStatement(sym), 
											type(NONE),
											index1(0),
											index2(0)
											{}
public:
	virtual int execute(void *cookie) override {
		switch(type) {
			case SET:
			break;
			case SETE:
			break;
			case GETE:
			break;
			default:
			break;
		}
	}

public:
	INST_TYPE type;
	uint32_t index1;
	uint32_t index2;
	std::pair<uint32_t, uint32_t> elem;

public:
	virtual void printInfo() override{
		std::cout << "[Line " << lineno << "]";
		if(type == SET) {
			std::cout << " SET " << index1 << " " << index2 << std::endl;
		} else if(type == SETE) {
			std::cout << " SETE " << elem.first << "(" << elem.second << ") " << index2 << std::endl;
		} else if(type == GETE) {
			std::cout << " GETE " << index1 << " " << elem.first << "(" << elem.second << ")" << std::endl;
		}
	}

};

class RCSignalStatement : public RCBaseStatement {
public:
	enum INST_TYPE {
		NONE = 0, WAIT = 1, DELAY = 2, SETOUT = 3, DIN = 4
	};
	enum OP_TYPE {
		EQ = 0, GE = 1, GT = 2, LE = 3, LT = 4, NE = 5
	};
public:
	RCSignalStatement(RC_SymbolTable &sym) : RCBaseStatement(sym), 
											 type(NONE),
											 op(EQ),
											 time(0),
											 index1(0),
											 index2(0)
											 {}
public:
	virtual int execute(void *cookie) override {
		switch(type) {
			case WAIT:
			break;
			case DELAY:
			break;
			case SETOUT:
			break;
			case DIN:
			break;
			default:
			break;
		}
	}

public:
	INST_TYPE type;
	OP_TYPE op;
	double time;
	uint32_t index1;
	uint32_t index2;

public:
	virtual void printInfo() override {
		std::cout << "[Line " << lineno << "]";
		if(type == WAIT) {
			std::cout << " WAIT " << index1 << " op<" << op << "> " << index2 << " T" << time << std::endl;
		} else if(type == DELAY) {
			std::cout << " DELAY " << "T" << time << std::endl;
		} else if(type == SETOUT) {
			std::cout << " SETOUT " << index1 << " " << index2 << std::endl;
		} else if(type == DIN) {
			std::cout << " DIN " << index1 << " " << index2 << std::endl;
		}
	}
};


class RCMathStatement : public RCBaseStatement {
public:
	enum INST_TYPE {
		NONE = 0, INCR = 1, DECR = 2, 
		ADD = 3, SUB = 4, MUL = 5, DIV = 6, 
		SIN = 7, COS = 8, ATAN = 9, SQRT = 10, 
		AND = 11, OR = 12, NOT = 13, XOR = 14
	};
public:
	RCMathStatement(RC_SymbolTable &sym) : RCBaseStatement(sym), 
											 type(NONE),
											 index1(0),
											 index2(0)
											 {}
public:
	virtual int execute(void *cookie) override {
		switch(type) {
			case INCR:
			break;
			case DECR:
			break;
			case ADD:
			break;
			case SUB:
			break;
			case MUL:
			break;
			case DIV:
			break;
			case SIN:
			break;
			case COS:
			break;
			case ATAN:
			break;
			case SQRT:
			break;
			case AND:
			break;
			case OR:
			break;
			case NOT:
			break;
			case XOR:
			break;
			default:
			break;
		}
		
	}

public:
	uint32_t type;
	uint32_t index1;
	uint32_t index2;
	std::pair<int32_t, int32_t> elem1;
	std::pair<int32_t, int32_t> elem2;


public:
	virtual void printInfo() override {
		std::cout << "[Line " << lineno << "]";
		if(type == INCR) {
			std::cout << " INCR " << index1 << std::endl;
		} else if(type == DECR) {
			std::cout << " DECR " << index1 << std::endl;
		} else  {
			if(type == ADD) std::cout << " ADD " ;
			else if(type == SUB) std::cout << " SUB " ;
			else if(type == MUL) std::cout << " MUL ";
			else if(type == DIV) std::cout << " DIV ";
			else if(type == SIN) std::cout << " SIN ";
			else if(type == COS) std::cout << " COS ";
			else if(type == ATAN) std::cout << " ATAN ";
			else if(type == SQRT) std::cout << " SQRT ";
			else if(type == AND) std::cout << " AND ";
			else if(type == OR) std::cout << " OR ";
			else if(type == NOT) std::cout << " NOT ";
			else if(type == XOR) std::cout << " XOR ";
			if(index1 == 0) std::cout << elem1.first << "(" << elem1.second << ") ";
			else std::cout << index1 << " ";
			if(index2 == 0) std::cout << elem2.first << "(" << elem2.second << ") ";
			else std::cout << index2 << " " << std::endl;
		}

	}
};


class RCLibCallStatement : public RCBaseStatement {
public:
	RCLibCallStatement(RC_SymbolTable &sym) : RCBaseStatement(sym), 
											 index(0)
											 {}
public:
	virtual int execute(void *cookie) override {

	}	
public:
	uint32_t index;						// the index of library function
	std::vector<int> params;			// the index of function parameters
};


class RCAssignStatement : public RCBaseStatement {
public:
	enum INST_TYPE {
		NONE = 0, GENERIC = 1, CALL = 2, ARITHMETIC = 3
	};
public:
	RCAssignStatement(RC_SymbolTable &sym) : RCBaseStatement(sym), 
											type(NONE),
											left(0),
											right(0)
											{}
public:
	virtual int execute(void *cookie) override {
		switch(type) {
			case GENERIC:
			break;
			case CALL:
			break;
			case ARITHMETIC:
			break;
			default:
			break;
		}
	}	

public:
	INST_TYPE type;
	uint32_t left;
	uint32_t right;
	std::vector<uint32_t> oprand;
	std::vector<char> op; 
	RCLibCallStatement* caller;
};

class RCGotoStatement : public RCBaseStatement {
public:
	RCGotoStatement(RC_SymbolTable &sym) : RCBaseStatement(sym)
							
											{}
public:
	virtual int execute(void *cookie) override {}

public:
	std::string label;

};

class RCIfStatement : public RCBaseStatement {
public:
	enum INST_TYPE {
		NONE = 0, GENERIC = 1, BOOLVALUE = 2, VAR = 3
	};

public:
	RCIfStatement(RC_SymbolTable &sym) : RCBaseStatement(sym),
											type(NONE)
											{}
public:
	virtual int execute(void *cookie) override {
		switch(type) {
			case GENERIC:
			break;
			case BOOLVALUE:
			break;
			case VAR:
			break;
			default:
			break;
		}
	}

public:
	INST_TYPE type;
	uint32_t exprVarIndex;
	char op;
	uint32_t oprand1;
	uint32_t oprand2;

	std::vector<RCBaseStatement*> *ifThenStat;
	std::vector<RCBaseStatement*> *elseifThenStat;
	std::vector<RCBaseStatement*> *elseThenStat;

};


class RCForStatement : public RCBaseStatement {
public:
	RCForStatement(RC_SymbolTable &sym) : RCBaseStatement(sym),
											varIndex(0),
											initValue(0),
											stopValue(0),
											step(0)
											{}
public:
	virtual int execute(void *cookie) override {}

public:
	uint32_t varIndex;				// the index of var in for statement
	int32_t initValue;				// the init value of var
	int32_t stopValue; 				// the end value of var
	int32_t step; 					// the step value of var in every cycle

	std::vector<RCBaseStatement*> *block;
};


class RCWhileStatement : public RCBaseStatement {
public:
	enum INST_TYPE{
		NONE = 0, GENERIC = 1, BOOLVALUE = 2, VAR = 3
	};
public:
	RCWhileStatement(RC_SymbolTable &sym) : RCBaseStatement(sym)
											{}
public:
	virtual int execute(void *cookie) override {
		switch(type) {
			case GENERIC:
			break;
			case BOOLVALUE:
			break;
			case VAR:
			break;
			default:
			break;
		}
	}

public:
	INST_TYPE type;

	uint32_t exprVarIndex;
	char op;
	uint32_t oprand1;
	uint32_t oprand2;

	std::vector<RCBaseStatement*> *block;
};





typedef std::vector<RCBaseStatement*> CodeModel;   // rc code in memory 