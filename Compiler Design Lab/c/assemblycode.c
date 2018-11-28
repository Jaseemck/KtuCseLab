// a=b*c
// b=a+f
// exit
#include<stdio.h>
#include<stdio.h>
#include<string.h>
void main()
{
	char icode[10][30],str[20],opr[10];
	int i=0;
	printf("\nEnter code :\n");
	do
	{
		scanf("%s",icode[i]);
	}while(strcmp(icode[i++],"exit")!=0);
	
	
	i=0;
	do
	{
		strcpy(str,icode[i]);
		if(str[3]=='\0'){
			printf("\n\tMOV %c,R%d",str[2],i);
			printf("\n\tMOV R%d,%c",i,str[0]);
			continue;
		}
		switch(str[3])
		{
			case '+':
			strcpy(opr,"ADD");
			break;
			case '-':
			strcpy(opr,"SUB");
			break;
			case '*':
			strcpy(opr,"MUL");
			break;
			case '/':
			strcpy(opr,"DIV");
			break;
		}
		printf("\n\tMOV %c,R%d",str[2],i); //move first operand to register
		printf("\n\t%s %c,R%d",opr,str[4],i); //perform operation (opcode sec_operand register)
		printf("\n\tMOV R%d,%c",i,str[0]); //move result in register to LHS symbol
		
	}while(strcmp(icode[++i],"exit")!=0);
 printf("\n");
}
