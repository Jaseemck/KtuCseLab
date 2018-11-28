%{
	#include<stdio.h>
%}

%%
[A-Za-z]([A-Za-z]|[0-9])* {printf("%s is an identifier\n",yytext);}
.*  {printf("Invalid");}
%%

void main(){
	yylex(); 
	return 0;
}

yywrap(){return 1;}