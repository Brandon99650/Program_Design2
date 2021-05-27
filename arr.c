#include"all.h"
void arr_build(int a[],int n,int arr[]){

    for(int i=0;i<n;i++){
        arr[i]=a[i];

    }
    //printf("arr_build success\n");

}
void arr_search(int arr[],int b[],int n,int m){//b是要search的m笔资料，arr为上个函式建立的
    int A[m];
    for(int i=0;i<m;i++){//测m笔
        int k=0;
        for(int j=0;j<n;j++){//找n次
            if(b[i]==arr[j]){
                k=1;
                break;
            }
        }
        if(k==1){
            A[i]=1;
        }
        else{
            A[i]=0;
        }
    }
}