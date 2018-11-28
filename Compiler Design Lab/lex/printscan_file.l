%{
	#include<stdio.h>
	int pcount=0;
	int scount=0;
	FILE *fin,*fout;
	char *p="writef";
	char *s="readf";
%}
%%
printf {
		if(strcmp("printf",yytext)==0){
			fprintf(fout,"%s",p);pcount++;}
		else
			fprintf(fout,"%s",yytext);
		}
scanf {
		if(strcmp("scanf",yytext)==0){
			fprintf(fout,"%s",s);scount++;}
		else
			fprintf(fout,"%s",yytext);
		}
. {fprintf(fout,"%s",yytext);}
\n {fprintf(fout,"%s",yytext);}
%%
void main(){
	fin=fopen("sample.txt","r");
	yyin=fin;
	fout=fopen("rw.txt","w");
	yylex();
	printf("printf count is %d\n",pcount);
	printf(" scanf count is %d\n",scount);
	fclose(fin);
	fclose(fout);
}
 yywrap(){}