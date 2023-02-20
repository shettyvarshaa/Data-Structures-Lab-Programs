#include<stdio.h>
void printarr(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d\t",a[i]);
    printf("\n");
}
void sort(int a[],int n){
    int i,j,temp;
    printf("Elements sorted in ascending order\n");
    for ( i = 0; i < n; i++)
    {
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printarr(a,n);
}
void grouping(int a[], int n){
    int i;
    printf("Group 1\n");
    for (i = 0; i < n; i++)
    {
        if(a[i]<=10)
            printf("%d\t",a[i]);
    }
    printf("\n");
    printf("Group 2\n");
    for ( i = 0; i < n; i++)
    {
        if(a[i]>10 && a[i]<=20)
            printf("%d\t",a[i]);
    }
    printf("\n");
    printf("Group 3\n");
    for ( i = 0; i < n; i++)
    {
        if(a[i]>20 && a[i]<=30)
            printf("%d\t",a[i]);
    }
    printf("\n");
    printf("Group 4\n");
    for ( i = 0; i < n; i++)
    {
        if(a[i]>30)
            printf("%d\t",a[i]);
    }
    printf("\n");
}
int main(){
    int i,a[100],n,temp,j;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    printf("The array elements are\n");
    for ( i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a,n);
    grouping(a,n);
}
