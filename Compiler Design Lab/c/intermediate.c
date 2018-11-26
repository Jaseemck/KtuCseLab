// a=b*c+a
#include<stdio.h>
#include<string.h>
char s[20];
void replace(int i,char c){
	printf("\n%c = %c %c %c",c,s[i-1],s[i],s[i+1]);
	s[i-1] = c;
	int k = i+2;
	int j =i;
	while(s[j]!='\0'){
		s[j++] = s[k++];	
	}
	s[j]='\0';
}
void main(){
	char c=65;
	int i=0;
	scanf("%s",s);
	while(s[i]!='\0'){
		if(s[i]=='*' || s[i]=='/'){
			replace(i,c);
			//printf("\n%s",s);
			 c++;
			 // i=0;		
		}
		i++;
	}
	i=0;
	while(s[i]!='\0'){
		if(s[i]=='+' || s[i]=='-'){
			replace(i,c);
			//printf("\n%s",s);
			 c++;
			 // i=0;		
		}
		i++;
	}
}
