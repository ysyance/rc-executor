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
				cooraddr(sym.cooraddr)
	{}

	virtual int execute(void *cookie) = 0;
public:
	RCAddressSpace &addrspace;     // addrspace[0] is the returned value of all the library function  in global
	
	StringPoolSpace &stringpool;
	APDataSpace &apaddr;
	CPDataSpace &cpaddr;
	ToolDataSpace &tooladdr;
	CoorDataSpace &cooraddr;
};