#include"all.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/time.h>
#include<unistd.h>
int comp(const void *a,const void *b){
     return *(int *)a - *(int *)b;
}
int search(int arr[], int n, int target){
    int low = 0, high = n - 1, middle;
    while( high >= low ){
        middle = (high + low) / 2;
        if(arr[middle] == target)
            return 1;
        else if(arr[middle] > target)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return 0;
}
void bs_build(int a[],int n,int arr[]){
    for(int i=0;i<n;i++){
        arr[i]=a[i];

    }
qsort(arr,n,sizeof(arr[0]),comp );
}
void bs_search(int arr[],int b[],int n,int m){
    
    int A[m];
    for(int i=0;i<m;i++){//测m笔
        int k=0;
        k=search(arr,n,b[i]);
        if(k==1){
            A[i]=1;
        }
        else{
            A[i]=0;
        }
    }

   // printf("bs_search success\n");
}