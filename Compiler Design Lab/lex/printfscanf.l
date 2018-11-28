%{
	#include<stdio.h>
	int pcount=0;
	int scount=0;
%}
%%
printf {printf("writef");pcount++;}
scanf {printf("readf");scount++;}
. {printf("%s",yytext);}
%%
void main(){
	FILE *fin;
	fin=fopen("sample.txt","r");
	yyin=fin;
	yylex();
	printf("\n%d\n",pcount);
	printf("%d\n",scount);
	fclose(fin);
}
yywrap(){}