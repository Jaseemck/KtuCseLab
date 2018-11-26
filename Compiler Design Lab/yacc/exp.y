%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM
%start S
%left '+' '-'
%left '*' '/'

%%

S : E {printf("Valid");}
  ;
E : E '+' E {$$=$1+$3;}
  | E '-' E {$$=$1-$3;}
  | E '*' E {$$=$1+$3;}
  | E '/' E {$$=$1+$3;}
  | NUM {$$=$1;}
%%
 void main(){
  printf("Enter expression: \n");
  yyparse();
}
yyerror(){
	printf("Invalid");
}
