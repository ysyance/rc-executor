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
public:
	RCAddressSpace &addrspace;     // addrspace[0] is the returned value of all the library function  in global
	
	StringPoolSpace &stringpool;
	APDataSpace &apaddr;
	CPDataSpace &cpaddr;
	ToolDataSpace &tooladdr;
	CoorDataSpace &cooraddr;

	int lineno;
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
											z(Z0)
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
	RESO_LEVEL z;

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

};

class RCSignalStatement : public RCBaseStatement {
public:
	enum INST_TYPE {
		NONE = 0, WAIT = 1, DELAY = 2, SETOUT = 3, DIN = 4
	};
public:
	RCSignalStatement(RC_SymbolTable &sym) : RCBaseStatement(sym), 
											 type(NONE),
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
	uint32_t time;
	uint32_t index1;
	uint32_t index2;
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
};


class RCCallStatement : public RCBaseStatement {
public:
	RCCallStatement(RC_SymbolTable &sym) : RCBaseStatement(sym), 
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
	RCCallStatement* caller;
};

class RCGotoStatement : public RCBaseStatement {
public:
	RCGotoStatement(RC_SymbolTable &sym) : RCBaseStatement(sym)
							
											{}
public:
	virtual int execute(void *cookie) override {}

public:
	uint32_t label;

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