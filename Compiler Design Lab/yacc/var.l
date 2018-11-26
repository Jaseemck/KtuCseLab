%{
	#include "y.tab.h"
%}
%%
[0-9] {return DIGIT;}
[A-Za-z] {return LETTER;}
\n {return 0;}
. {return yytext[0];}
%%

