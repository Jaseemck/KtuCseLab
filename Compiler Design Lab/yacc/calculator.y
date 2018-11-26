%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM
%start S
%left '+' '-'
%left '*' '/'

%%

S : E {printf("Result = %d\n",$$);}
  ;
E : E '+' E {$$=$1+$3;}
  | E '-' E {$$=$1-$3;}
  | E '*' E {$$=$1*$3;}
  | E '/' E {$$=$1/$3;}
  | NUM {$$=$1;}
  ;
%%
int main(){
  printf("Enter the expression: ");
  yyparse();
  return 0;
}
yywrap()
{
	return 1;
}
int yyerror(){
	printf("Invalid expression\n");
}
