
#pragma once


#include <iostream>
#include <exception>
#include <unordered_map>

enum RC_EXCEPTION_TYPE{
	EXCEP_RUNTIME = 0,
	EXECP_VAR_DUP,
	EXECP_NUM_FORMAT,
	EXECP_POINT_NOT_DEFINED,
	EXECP_NULL_INSTRUCTION,
};

static std::vector<std::string> rc_excep_info = {
	"RC executor general runtime exception",
	"RC variable duplicated defination",
	"RC bad number format or bad number type",
	"RC the point is not defined",
	"RC the instruction type is null"
};


class rc_exception : public std::exception {
public:
	rc_exception() {
		this->type = EXCEP_RUNTIME;
	}
	rc_exception(int t): type(t) {}
	rc_exception(int t, int l, int c): type(t), line(l), col(c) {}

public:
	virtual void what() {
		std::cerr << "[EXCEPTION" << " " << type << "]: " << rc_excep_info[type] << std::endl;
	} 

public:
	int type;
	int line;
	int col;
};


class rc_vardup_exception : public rc_exception {
public:
	rc_vardup_exception() : rc_exception(EXECP_VAR_DUP, 0, 0){
	}

	rc_vardup_exception(int l, int c, std::string s) : rc_exception(EXECP_VAR_DUP, l, c), var(s){
	}

public:
	virtual void what() {
		std::cerr << "[EXCEPTION" << " " << type << "] " 
					<< "line " << line << ":" << col << " " 
					<< "[Var:" << var << "] --> "
					<< rc_excep_info[type] 
					<< std::endl;
	}

private:
	std::string var;

};


class rc_numformat_exception : public rc_exception {
public:
	rc_numformat_exception() : rc_exception(EXECP_NUM_FORMAT, 0, 0){
	}

	rc_numformat_exception(int l, int c, std::string s) : rc_exception(EXECP_NUM_FORMAT, l, c), num(s){
	}

public:
	virtual void what() {
		std::cerr << "[EXCEPTION" << " " << type << "] " 
					<< "line " << line << ":" << col << " " 
					<< "[NUM:" << num << "] --> "
					<< rc_excep_info[type] 
					<< std::endl;
	}

private:
	std::string num;

};



class rc_pointnotdefined_exception :  public rc_exception {
public:
	rc_pointnotdefined_exception() : rc_exception(EXECP_POINT_NOT_DEFINED, 0, 0){
	}

	rc_pointnotdefined_exception(int l, int c, std::string s) : rc_exception(EXECP_POINT_NOT_DEFINED, l, c), point(s){
	}
public:
	virtual void what() {
		std::cerr << "[EXCEPTION" << " " << type << "] " 
					<< "line " << line << ":" << col << " " 
					<< "[NUM:" << point << "] --> "
					<< rc_excep_info[type] 
					<< std::endl;
	}

private:
	std::string point;

};


class rc_nullinstruction_exception : public rc_exception {
public:
	rc_nullinstruction_exception() : rc_exception(EXECP_NULL_INSTRUCTION, 0, 0) {
	}

	rc_nullinstruction_exception(int l, int c, std::string s) : rc_exception(EXECP_NULL_INSTRUCTION, l, c), inst(s){
	}

public:
	virtual void what() {
		std::cerr << "[EXCEPTION" << " " << type << "] " 
					<< "line " << line << ":" << col << " " 
					<< "[INST:" << inst << "] --> "
					<< rc_excep_info[type] 
					<< std::endl;
	}

private:
	std::string inst;

};