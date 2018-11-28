%{
	#include<stdio.h>
%}
%%
[A-Z] ;
[ \t\n] ;
%%
void main(){
	FILE *fin;
	fin=fopen("sample.txt","r");
	yyin=fin;
	yylex();
}
yywrap(){}