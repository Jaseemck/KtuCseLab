%{
	#include "y.tab.h"
	#include<ctype.h>
%}
%%
[0-9]*[A-Za-z]+ {    yylval=atoi(yytext);
								return NUM;}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
\n {return 0;}
. {return yytext[0];}
%%

yywrap(){}