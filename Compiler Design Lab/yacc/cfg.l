%{
	#include "y.tab.h"
%}


%%


"a" {return A;}
"b" {return B;}
\n {return 0;}
. {return yytext;}


%%
yywrap(){}
