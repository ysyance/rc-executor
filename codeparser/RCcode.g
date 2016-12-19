grammar RCcode;

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
 | libcall_stat 			# libcallStat
 | call_stat				# callStat 
 ;  

robot_stat
 : MOVJ ID ',' ID ',' ID ';'			# movjExpr
 | MOVL ID ',' ID ',' ID ';' 			# movlExpr
 | MOVC ID ',' ID ',' ID ',' ID ';' 	# movcExpr
 | MOVS ID ',' ID ',' ID ',' ID ';'		# movsExpr
 | SHIFTON ID ',' ID ';'				# shiftonExpr
 | SHIFTOFF';' 							# shiftoffExpr
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
 : ID ASSIGN boolval ';' 		# assignExpr1
 | ID ASSIGN numorid op=('+'|'-'|'*'|'/'|'=='|'>='|'<='|'>'|'<'|'<>') numorid ';' # assignExpr2
 | ID ASSIGN libcall_stat ';'  	# assignExpr3
 | ID ASSIGN numorid ';'		# assignExpr4
 ;

goto_stat
 : GOTO LABEL ';'			# gotoExpr
 ;

if_stat  
 : IF numorid RELOP numorid THEN block (elseif_stat)* (else_stat)? ENDIF ';' 	# ifExpr1
 | IF boolval THEN block (elseif_stat)* (else_stat)? ENDIF ';'				 	# ifExpr2
 | IF ID THEN block (elseif_stat)* (else_stat)? ENDIF ';'				 		# ifExpr3
 ;  
  
elseif_stat
 : ELSEIF numorid RELOP numorid THEN block ';'				# elseifExpr1
 | ELSEIF boolval THEN block ';'							# elseifExpr2
 | ELSEIF ID THEN block ';'									# elseifExpr3
 ;

else_stat
 : ELSE block   ';'							# elseExpr
 ;

for_stat
 : FOR ID ASSIGN NUM TO NUM BY NUM block ENDFOR ';' 		# forExpr
 ;

while_stat
 : WHILE numorid RELOP numorid DO block ENDWL ';'   		# whileExpr1
 | WHILE boolval DO block ENDWL ';' 						# whileExpr2
 | WHILE ID DO block ENDWL ';' 								# whileExpr3 
 ;


boolval
 : TRUE 							# trueExpr
 | FALSE 							# falseExpr
 ;

libcall_stat
 : ID '(' params ')'				# libcallExpr
 ;

params
 : numorid? (',' numorid)* 			# paramlist
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

GOTO : 'GOTO';

IF : 'IF' ;
THEN : 'THEN';
ELSEIF : 'ELSEIF';
ELSE : 'ELSE';
ENDIF : 'ENDIF';

ASSIGN : '=';  

WHILE : 'WHILE';
DO : 'DO';
ENDWL : 'ENDWL';

FOR : 'FOR';
TO : 'TO';
BY : 'BY';
ENDFOR : 'ENDFOR';

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

LABEL 
 : 'L' [0-9]+
 ;

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
 | 'T' '.' [0-9]+
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
