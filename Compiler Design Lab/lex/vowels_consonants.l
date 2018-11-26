%{
	#include<stdio.h>
	int vowels=0;
	int consonant=0;
%}
%%
[AEIOUaeiou] {vowels++;}
[A-Za-z] {consonant++;}
. ;
%%
void main(){
	FILE *fin;
	fin = fopen("sample.txt","r");
	yyin=fin;
	yylex();
	printf("Vowels = %d\n",vowels);
	printf("Consonants = %d",consonant);
}
yywrap()
{}