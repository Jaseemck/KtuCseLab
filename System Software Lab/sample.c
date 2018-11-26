#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
    char path[50];
    char p[10][20];
    char temp[10]="";
    char c[2];
    c[1]='\0';
    int j,i=1;
    strcpy(p[0],"/root");
    printf("\nEnter the path: ");
    scanf("%s",path);
    for(j=6;j<strlen(path);j++){
        c[0]=path[j];
        if(strcmp(c,"/")!=0){
            strcat(temp,c);
        }else{
            strcpy(p[i++],temp);
            strcpy(temp,"");
        }
    }
    strcpy(p[i],"\\0");
    for(int k=0;(strcmp(p[k],"\\0")!=0);k++)
        printf("\n%s",p[k]);
    
}
