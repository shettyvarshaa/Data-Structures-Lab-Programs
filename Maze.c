#include<stdio.h>
//according to the question, it must be #define size 7 
#define size 4

int maze[size][size];
int solution[size][size];

int solvemaze(int r,int c){
    if(r==size-1 && c==size-1){
        solution[r][c]=1;
        return 1;
    }
    if(r<size && c<size && solution[r][c]==0 && maze[r][c]==0){
        solution[r][c]=1;
        if((solvemaze(r+1,c)))
            return 1;
        if((solvemaze(r,c+1)))
            return 1;
        if((solvemaze(r-1,c)))
            return 1;
        if((solvemaze(r,c-1)))
            return 1;
    }
    else{
        solution[r][c]=0;
        return 0;
    }
}

void printsolution(){
    int i,j;
    printf("solution maze is: \n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d\t",solution[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            solution[i][j]=0;
        }
    }
    printf("Enter a maze of 4x4\n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    printf("\n");
    printf("Entered maze is: \n");
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d\t",maze[i][j]);
        }
        printf("\n");
    }
    if(solvemaze(0,0))
        printsolution();
}
