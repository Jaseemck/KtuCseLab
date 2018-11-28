%{
	#include "y.tab.h";
	extern int val;
%}
%%
[0-9]* {val=atoi(yytext); return NUM;}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
\n {return 0;}
. {return yytext;}
%%

