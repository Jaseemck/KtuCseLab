%{
#include<stdio.h>
#include<stdlib.h>
%}
%token DIGIT LETTER
%start S

%%

S : LETTER A
  ;
A : LETTER A
  | DIGIT A
  |
  ;
%%
 main(){
  yyparse();
  printf("Valid");
}
yyerror(){
	printf("Invalid");
}
