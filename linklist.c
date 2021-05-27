#include"all.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <sys/time.h>
#include<unistd.h>
void link_build(int A[],int n,int m,int b[]){
    struct  timeval first;
    struct  timeval end;
    unsigned  long diff;
    struct link{
    int a;
    struct link *next;
};
    struct link *start=NULL,*tmp ,*newer;
    //----------------------测时间------------//
    gettimeofday(&first,NULL);
    for(int i=0;i<n;i++){
        struct link *newer=(struct link*) malloc(sizeof(struct link));
        newer->a=A[i];
        tmp=start;
        start=newer;
        newer->next=tmp;

    }
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
    //----------------------测时间------------//

    printf("ll:\n");
    printf("building time: %ld sec\n",diff);

    //----------------------测时间------------//
    gettimeofday(&first,NULL);
    int arr[m];
    for(int i=0;i<m;i++){
        tmp=start;
        int k=0;
        for(int j=0;j<n;j++){
            if(b[i]==tmp->a){
                k=1;
                break;
            }
            else{
                tmp=tmp->next;
            }
            if(k==1){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
        }
    }
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
    //----------------------测时间------------//
    printf("query time: %ld sec\n",diff);
    printf("\n");
    printf("\n");
    //print();


}