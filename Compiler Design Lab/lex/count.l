%{
#include<stdio.h>
int line=0;
int ch=0;
int word=0;
int blank=0;
%}
%%
\n {line++;word++;}
[ \t] {word++;blank++;}
[A-Za-z] {ch++;}
. ;
%%
void main(){
	FILE *f;
	f=fopen("sample.txt","r");
	yyin=f;
	yylex();
	printf("Lines = %d\n",line);
	printf("Blank = %d\n",blank);
	printf("Characters = %d\n",ch);
	printf("Words = %d\n",word);
}

yywrap(){}