%{
 #include<stdio.h>
 #include<stdlib.h>
    int flag=0;  
struct node{
	char c;
	struct node* prev;
	struct node* next;
};


struct node* make_leaf(char ch)
{  
   struct node* temp=(struct node *)malloc(sizeof(struct node));
   if (temp==NULL)
	return NULL;
   temp->c=ch;
   temp->prev=NULL;
   temp->next=NULL;
   return temp;
}

struct node* make_node(char op,struct node* left,struct node* right)
{  
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   if (temp==NULL)
	return NULL;
   temp->c=op;
   temp->prev=left;
   temp->next=right;
   return temp;
}


void pre_order(struct node* temp)
{
   if(temp==NULL)
	return;
   printf("%c ",temp->c);
   pre_order(temp->prev);
   pre_order(temp->next);
}

%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%

S: E   { pre_order($1);
         return 0;
       }

E:E'+'E {$$=make_node('+',$1,$3);}

 |E'-'E {$$=make_node('-',$1,$3);}

 |E'*'E {$$=make_node('*',$1,$3);}

 |E'/'E {$$=make_node('/',$1,$3);}

 |E'%'E {$$=make_node('%',$1,$3);}

 |'('E')' {$$=$2;}

 | NUMBER {$$=make_leaf($1+'0');}

;

%%

void main(){
 	char str[20];
	printf("Enter the string : ");
 yyparse();
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  if(flag==0)
    printf("\nEntered expression is Valid\n\n");
}

void yyerror()
{   printf("\nEntered expression is Invalid\n\n");
   flag=1;
}
	 	


 
