%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%start S


%%


S : A S B 
 |
 ;
 
 
%%


 main(){
  yyparse();
  printf("Valid");
}
yyerror(){
	printf("Invalid");
	exit(0);
}
