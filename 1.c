#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the size :");
    scanf("%d",&n);
    int ar[n];
    printf("Enter the array :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    printf("Array is :\n");
     for(int i=0;i<n;i++){
       printf("%d  ",ar[i]);
    }
    printf("\nThe required array is :\n");
    int neg[n];
    int p=0;
    for(int i=0;i<n;i++){
        if(ar[i]<0){
            neg[p++]=ar[i];
        }
    }
    for(int i=0;i<n;i++){
        if(ar[i]>=0)
       printf("%d  ",ar[i]);
    }
    for(int i=0;i<p;i++){
        printf("%d  ",neg[i]);
    }
    return 0;
}
