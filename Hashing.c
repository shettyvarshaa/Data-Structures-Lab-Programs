#include<stdio.h>
#include<stdlib.h>
#define max 100
int m,count=0,key,ht[max]={0},hi=0;// m: size of hashtable(ht), count: no. of elements in ht, key: key to be inserted, hi: hash function

void createtable(){
    if(m<=0){
        printf("Ivalid Hash table, Enter a valid number\n");
        scanf("%d",&m);
    }
}

void placekey(int k){
    int flag=0;
    hi=(2*k+3)%m;
    while(ht[hi]!=0){
        hi=(hi+1)%m;
        flag=1;
    }
    if(flag){
        printf("Collision Detected and avoided by Linear Probing!\n");
        flag = 0;
    }
    ht[hi]=k;
    count++;
}

void display(){
    int i;
    printf("Hash table is\n");
    for(i=0;i<m;i++)
        printf("ht[%d] --> %d\n",i,ht[i]);
    if(count==m){
        printf("No more keys can be added\n TABLE IS FULL\n");
        exit(0);
    }
}

void main(){
    printf("Enter number of slots in the hash table:\n");
    scanf("%d",&m);
    createtable();
    do{
        printf("Enter the key to be inserted ('0' to end)\n");
        scanf("%d",&key);
        if(key!=0 && count!=m){
            placekey(key);
        }
        else
            break;
    }
    while(key);
    display();
}
