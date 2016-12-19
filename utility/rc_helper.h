#pragma once

#include "rc_innerdata.h"
#include "unordered_map"
#include "rc_exception.h"


class Utility {
public:
	static void printfAddrspace(RCAddressSpace &addrspace) {
		std::cout << "[>>>>>>>>>>>  Addrspace  <<<<<<<<<<<<]" << std::endl;
		for(int i = 0; i < addrspace.size(); i ++) {
			std::cout << "[" << i << "] " << addrspace[i] << std::endl;
		}
		std::cout << std::endl;
	}

	static void printfDataIndexMap(std::unordered_map<std::string, int> &dataIndexMap) {
		std::cout << "[>----------  DataIndexMap  --------<]" << std::endl;
		for(auto &e : dataIndexMap) {
			std::cout << e.first << " --> [" << e.second << "]" << std::endl; 
		}
		std::cout << std::endl;
	}


	static void printfStringPool(StringPoolSpace &stringpool) {
		std::cout << "[>+++++++++++++  StringPool  +++++++++++<]" << std::endl;
		for(int i = 0; i < stringpool.size(); i ++) {
			std::cout << "[" << i << "] " << stringpool[i] << std::endl;
		}
		std::cout << std::endl;
	}

	static void printfAPDataSpace(APDataSpace &apaddr) {
		std::cout << "[>************  APDataSpace  ***********<]" << std::endl;
		for(int i = 0; i < apaddr.size(); i ++) {
			std::cout << "[" << i << "] " ;
			int len = apaddr[i].size();
			for(int j = 0; j < len; j ++) {
				std::cout << apaddr[i][j];
				if(j < len-1) std::cout << ", ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	static void printfCPDataSpace(CPDataSpace &cpaddr) {
		std::cout << "[>************  CPDataSpace  ***********<]" << std::endl;
		for(int i = 0; i < cpaddr.size(); i ++) {
			std::cout << "[" << i << "] " ;
			int len = cpaddr[i].size();
			for(int j = 0; j < len; j ++) {
				std::cout << cpaddr[i][j];
				if(j < len-1) std::cout << ", ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	static void printfToolDataSpace(ToolDataSpace &tooladdr) {
		std::cout << "[>==========  ToolDataSpace  ===========<]" << std::endl;
		for(int i = 0; i < tooladdr.size(); i ++) {
			std::cout << "[" << i << "] " ;
			int len = tooladdr[i].size();
			for(int j = 0; j < len; j ++) {
				std::cout << tooladdr[i][j];
				if(j < len-1) std::cout << ", ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	static void printfCoorDataSpace(CoorDataSpace &cooraddr) {
		std::cout << "[>==========  CoorDataSpace  ===========<]" << std::endl;
		for(int i = 0; i < cooraddr.size(); i ++) {
			std::cout << "[" << i << "] " ;
			std::cout << cooraddr[i].type << " " 
						<< cooraddr[i].p1 << " "
						<< cooraddr[i].p2 << " "
						<< cooraddr[i].p3 ;
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

public:
	static int parseInt(std::string &str) {
		if(checkInt(str)) {
			if(str.find("^B") == 0) {
				std::string num = str.substr(2);
				return std::stoi(num, 0, 2);
			} else if(str.find("^H") == 0) {
				std::string num = str.substr(2);
				return std::stoi(num, 0, 16);
			} else {
				return std::stoi(str);
			}
		} else {
			throw std::exception();
		}
	}	

	static double parseDouble(std::string &str) {
	
		if(str.find("^B") == std::string::npos && str.find("^H") == std::string::npos) {
			return std::stod(str);
		} else {
			throw std::exception();
		}
	}	

	static int parseSpeed(std::string &str) {
		int size = str.size();
		if(size < 2) return -1;
		for(int i = 0; i < size; i ++) {
			if(i == 0 && str[i] != 'V')  return -1;
			if(i != 0 && (str[i] < '0' || str[i] > '9')) return -1 
		}
		return std::stoi(str.substr(1));
	}
	

private:
	static bool checkInt(std::string &str) {
		return str.find(".") == std::string::npos;
	}

	static bool startWith(std::string &str, std::string &pattern) {
		return str.find(pattern) == 0;
	}



};

