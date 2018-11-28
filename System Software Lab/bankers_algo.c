#include<stdio.h>

int maximum[10][10],available[10],allocated[10][10],need[10][10],work[10];
int process,resources;
int finish[10];

int canprocess(){
    int i,j;
    for(i=0;i<process;i++){
        if(finish[i]==0){
            for(j=0;j<resources;j++){
                if(need[i][j]<available[j]){
                    return i;
                }
            }
        }
    }
    return -1;
}

void main(){
    int i,j,p;
    printf("\nEnter the number of processes: ");
    scanf("%d",&process);
    printf("\nEnter the number of resources: ");
    scanf("%d",&resources);
    
    printf("\nEnter the maximum required resources of each type for each process: \n");
    for(i=0;i<process;i++){
        for(j=0;j<resources;j++){
            scanf("%d",&maximum[i][j]);
        }
    }
    printf("\nEnter the allocated resources of each type for each process:\n");
    for(i=0;i<process;i++){
        for(j=0;j<resources;j++){
            scanf("%d",&allocated[i][j]);
        }
    }
    printf("\nEnter the available resources of each type: \n");
    for(i=0;i<resources;i++){
        scanf("%d",&available[i]);
        work[i]=available[i];
    }
    
    /*....Need Calculation....*/
    for(i=0;i<process;i++){
        for(j=0;j<resources;j++){
           need[i][j]=maximum[i][j]-allocated[i][j];
        }
    }
    
    
    /*....Initialise every process unprocessed....*/
    for(i=0;i<process;i++){
        finish[i]=0;
    }
    
    /*....Check if process can be processed....*/
    while(1){
	p=canprocess();
	if(p==-1){
	for(i=0;i<process;i++){
	    if(finish[i]==0){
		printf("\nUnsafe state will be reached on allocation\n");
		return;
	    }
	}
	printf("\nSafe state on allocation of resources\n");
	return;
	}else{
            for(i=0;i<resources;i++){
                work[i]-=allocated[p][i];
            }
            finish[p]=1;
	}
    }
}
