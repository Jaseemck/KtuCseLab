// a+a
#include<stdio.h>
#include<string.h>
char stack[30]={'$'};

int top = 0;
char op[10][10]=
   {'e','+','-','*','/','^','a','(',')','$',
	'+','>','>','<','<','<','<','<','>','>',
	'-','>','>','<','<','<','<','<','>','>',
	'*','>','>','>','>','<','<','<','>','>',
	'/','>','>','>','>','<','<','<','>','>',
	'^','>','>','>','>','<','<','<','>','>',
	'a','>','>','>','>','>','e','e','>','>',
	'(','<','<','<','<','<','<','<','=','e',
	')','>','>','>','>','>','e','e','>','>',
	'$','<','<','<','<','<','<','<','e','e'};


int getIndex(char c){
	int i;
	for(i=0;i<10;i++)
		if(op[0][i] == c)
			return i;
	return -1;
}

void push(char c){
	stack[++top] = c;
}

char pop(){
	return stack[top--];
}

int main()
{
	char input[20],temp; 
	scanf("%s",input);
	int len = strlen(input);
	input[len] = '$';
	input[++len] = '\0';
	int p=0;
	int x,y;
	while(1){
		if(stack[top] == '$' && input[p] == '$'){
			printf("\nSuccessfully Parsed\n");
			break;
		}
		x = getIndex(stack[top]);
		y = getIndex(input[p]);
		printf("\n%c %c %c",stack[top],op[x][y],input[p]);
		if(op[x][y] == '<' || op[x][y] == '='){
			
			printf("   Push %c",input[p]);
			push(input[p++]);
		}
		else if(op[x][y] == '>'){
			do{
				temp = pop();
				x = getIndex(stack[top]);
				y = getIndex(temp);
				printf("   Pop %c",temp);
			}while(op[x][y] == '>' || op[x][y] == '=');
		}
		else{
			printf("\nParsing Failed\n");
			break;
		}

	}
	return 0;
}
