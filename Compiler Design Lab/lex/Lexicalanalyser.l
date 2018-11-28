%{
#include<stdio.h>
#include<string.h>
char identifier[30][10],keyword[10][10],operator[5][2],symbol[5][2],delimiter[5][2],literal[20][50],number[5][5],function[20][10];
int i=0,j=0,k=0,o=0,s=0,d=0,l=0,n=0,f=0,id=0,a=0,blank=0,newline=0,flag=0;
%}
%%
int|void|printf|scanf|char|if|else|while|do|for|main  {
							flag=0;
							for(j=0;j<k;j++){
								if(strcmp(yytext,keyword[j])==0){
									flag=1;
									break;}}
							if(flag==0)
								strcpy(keyword[k++],yytext);
                                                       }
[+\-\*\/\=]	{
		flag=0;
		for(j=0;j<0;j++){
			if(strcmp(yytext,operator[j])==0){
				flag=1;
				break;}}
		if(flag==0)
			strcpy(operator[o++],yytext);
		}
[A-Za-z]([A-Za-z][0-9])*	{
				flag=0;
				for(j=0;j<id;j++){
					if(strcmp(yytext,identifier[j])==0){
						flag=1;
						break;}}
				if(flag==0)
					strcpy(identifier[id++],yytext);
				}
[@\$\&\%\#] {strcpy(symbol[s++],yytext);}
[0-9]*	{
		flag=0;
		for(j=0;j<n;j++){
			if(strcmp(yytext,number[j])==0){
				flag=1;
				break;}}
		if(flag==0)
			strcpy(number[n++],yytext);
	}
[,\;\[\]\{\}\(\)\.]	{
			flag=0;
			for(j=0;j<d;j++){
			if(strcmp(yytext,delimiter[j])==0){
				flag=1;
				break;}}
			if(flag==0)
				strcpy(delimiter[d++],yytext);
			}
"//".*[\n]|"/*"(.*[\n].*)*"*/"	{printf("%s is a comment \n",yytext);}
["].*["]	{ strcpy(literal[l++],yytext);}
\n {newline++;}
[\t ] {blank++;}

("int"|"char"|"void")[A-Za-z]([A-Za-z][0-9])*\(.*\) { strcpy(function[f++],yytext);}
,;

%%

void main()
{

FILE *fp=fopen("sample.txt","r");
yyin=fp;
yylex();
printf("\n blanks = %d ",blank);
printf("\n newlines = %d ",newline);
printf("\n keywords  :  ");
for(i=0;i<k;i++){
	printf("    %s",keyword[i]);
	}
printf("\n operators  :  ");
for(i=0;i<o;i++){
	printf("    %s",operator[i]);
	}
printf("\n identifiers  :  ");
for(i=0;i<id;i++){
	printf("\t%s",identifier[i]);
	}
printf("\n symbols  :  ");
for(i=0;i<s;i++){
	printf("    %s",symbol[i]);
	}
printf("\n numbers  :  ");
for(i=0;i<s;i++){
	printf("    %s",number[i]);
	}
printf("\n delimiters  :  ");
for(i=0;i<d;i++){
	printf("    %s",delimiter[i]);
	}
printf("\n functions  :  ");
for(i=0;i<f;i++) {
	printf("    %s",function[i]);
	}
printf("\n literals  :  ");
for(i=0;i<l;i++) {
	printf("    %s",literal[i]);
	}

}

