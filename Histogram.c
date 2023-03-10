#include <stdio.h>

void printHistogram ( int hist[], int n );

int main() {
   int i, j;
   int inputValue;

   printf("Input the amount of values: \n");  
   scanf("%d", &inputValue);
   int hist[inputValue];

   printf("Input the values between 0 and 9 (separated by space): \n");
   for (i = 0; i < inputValue; ++i) {
    scanf("%d", &hist[i]);  
   }

    int results[10] = {0};

    // Processing data to compute histogram, see 5.17
    for (i = 0; i < 10; ++i) {   
      for(j = 0; j < inputValue; j++) {
         if ( hist[j] == i){
            results[i]++;
         }
      } 
   }

    printf("\n");
    printHistogram(results, inputValue);

}

void printHistogram(int hist[], int n) {
      int i, j, k;
      int arr[10]={0};
      for (i = 0; i < n; i++) {
      printf("[%d] ", i);
      for ( j = 0; j < hist[i]; ++j) {
      printf("*");
      }
      printf("\n");
   }
    printf("Frequency array would be: ");
      for ( i = 0; i < n; i++)
   {
    printf(" %d",hist[i]);
   }
   
   for (i = 0; i < 10; ++i) {   
      for(j = 0; j < n; j++) {
         if ( hist[j] == i){
            arr[i]++;
}
      }
   }
}
