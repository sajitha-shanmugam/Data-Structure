// Online C compiler to run C program online
#include <stdio.h>

int main() {
   int n,min,temp;
   printf("Enter size of array:");
   scanf("%d",&n);
   int arr[n];
   printf("Enter the elements of array: ");
   for(int i=0;i<n;i++){
       scanf("%d",&arr[i]);
   }
   
   for(int i=0;i<n-1;i++){
       min = i;
       for(int j=i+1;j<n;j++){
           if(arr[j] < arr[min]){
               min = j;
           }
       }
       if(min !=i){
           temp = arr[i];
           arr[i] = arr[min];
           arr[min] = temp;
       }
       
   }
   printf("Sorted array:");
   for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
   }
    return 0;
}