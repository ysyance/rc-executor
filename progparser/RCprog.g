grammar RCprog;

options{
	language = Cpp;
}
  
prog 
 : block EOF  			# program	
 ;  
  
block  
 : stat*  				# statBlock
 ;  
  
stat 
 : robot_stat  				# robotStat 
 | data_stat				# dataStat
 | signal_stat  			# signalStat
 | math_stat				# mathStat
 | oneinst_stat				# onewordStat
 | assign_stat 				# assignStat
 | goto_stat				# gotoStat
 | if_stat 					# ifStat
 | for_stat 				# forStat
 | while_stat 				# whileStat
 | do_stat 					# doStat
 | libcall_stat 			# libcallStat
 | call_stat				# callStat 
 ;  

robot_stat
 : MOVJ ID ',' ID ',' ID ';'			# movjExpr
 | MOVL ID ',' ID ',' ID ';' 			# movlExpr
 | MOVC ID ',' ID ',' ID ',' ID ';' 	# movcExpr
 | MOVS ID ',' ID ',' ID ',' ID ';'		# movsExpr
 | SHIFTON ID ',' ID ';'				# shiftonExpr
 | SHIFTOFF; 							# shiftoffExpr
 ;

data_stat
 : SET ID ',' ID ';'		# setExpr
 | SETE ELEM ',' ID	';'		# seteExpr
 | GETE ID ',' ELEM ';'  	# geteExpr
 ;

signal_stat
 : WAIT ID RELOP numorid (',' TIME) ';'  	# waitExpr
 | DELAY TIME ';' 							# delayExpr
 | SETOUT ID ',' ID ';'						# setoutExpr
 | DIN ID ',' ID ';' 						# dinExpr
 ;

math_stat
 : INCR ID ';'  								# incExpr
 | DECR ID ';' 									# decExpr
 | FUNC op1=(ELEM | ID) ',' op2=(ELEM | ID)';' 	# funcExpr
 ;

call_stat
 : CALL ID ';'			# callExpr
 ;

assign_stat
 : ID ASSIGN expr   	# assignExpr 
 ;

if_stat  
 : IF expr THEN block (elseif_stat)* (else_stat)? END_IF	# ifExpr
 ;  
  
elseif_stat
 : ELSE IF expr THEN block 				# elseifExpr
 ;

else_stat
 : ELSE block   						# elseExpr
 ;

libcall_stat
 : ID '(' params ')'			# libcallExpr
 ;

expr  
 : numorid 							# variable
 | libcall_stat						# call
 ;  

numorid
 : NUM 						# numExpr
 | ID 						# idExpr
 ;

oneinst_stat
 : oneinst ';'	# oneinstExpr
 ;

oneinst
 : LABEL 	 	# labelExpr
 | RET 		 	# retExpr
 | NOP 			# nopExpr
 | PAUSE 		# pauseExpr
 | HALT 		# haltExpr
 | BREAK 		# breakExpr
 ;



ASSIGN : '=';  

TRUE : 'TRUE';
FALSE : 'FALSE';

MOVJ : 'MOVJ';
MOVL : 'MOVL';
MOVC : 'MOVC';
MOVS : 'MOVS';
SHIFTON : 'SHIFTON';
SHIFTOFF : 'SHIFTOFF';

SET : 'SET';
SETE : 'SETE';
GETE : 'GETE';

WAIT : 'WAIT';
DELAY : 'DELAY';
SETOUT : 'SETOUT';
DIN : 'DIN';

LABEL : 'L';
RET : 'RET';
NOP : 'NOP';
PAUSE : 'PAUSE';
HALT : 'HALT';
BREAK : 'BREAK';

INCR : 'INCR';
DECR : 'DECR';

CALL : 'CALL';

FUNC 
 : 'ADD'
 | 'SUB'
 | 'MUL'
 | 'DIV'
 | 'SIN'
 | 'COS'
 | 'ATAN'
 | 'SQRT'
 | 'AND'
 | 'OR'
 | 'NOT'
 | 'XOR'
 ;

RELOP 
 : '=='
 | '>='
 | '<='
 | '<>'
 | '>'
 | '<'
 ;

TIME 
 : 'T' [0-9]+ '.' [0-9]* 
 : 'T' '.' [0-9]+
 | 'T' [0-9]+
 ; 

ELEM 
 : ID '(' [0-6] ')' 
 ;

CSTRING
 : '"' [a-zA-Z_0-9]* '"'
 ;

CH 
 : '\'' [0-9A-Za-z_] '\''
 ;

ID  
 : [a-zA-Z_] [a-zA-Z_0-9]*  
 ;  
    
  
NUM  
 : '^B' '-'? [01]+
 | '^H' '-'? [0-9A-F]+ 
 | '-'? [0-9]+ '.' [0-9]*   
 | '-'? '.' [0-9]+  
 | '-'? [0-9]+
 ;  
  
COMMENT  
 : '#' ~[\r\n]* -> skip  
 ;  
  
SPACE  
 : [ \t\r\n] -> skip  
 ;  
  
OTHER  
 : .   
 ;  
