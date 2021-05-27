#include"all.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include <sys/time.h>
#include<unistd.h>
int hashcode(int a){
    return a%5;
}
void hash(int A[],int n,int m,int b[]){
    struct  timeval first;
    struct  timeval end;
    unsigned  long diff;
    struct link{
    int a;
    struct link *next;
};
    int index;
    struct link *start0=NULL,*tmp0 ;
    struct link *start1=NULL,*tmp1 ;
    struct link *start2=NULL,*tmp2 ;
    struct link *start3=NULL,*tmp3 ;
    struct link *start4=NULL,*tmp4 ;
    //----------------------测时间------------//
    gettimeofday(&first,NULL);
    for(int i=0;i<n;i++){
        index=hashcode(A[i]);
        if(index==0){
            struct link *newer0=(struct link*) malloc(sizeof(struct link));
            newer0->a=A[i];
            tmp0=start0;
            start0=newer0;
            newer0->next=tmp0;
        }
        if(index==1){
            struct link *newer1=(struct link*) malloc(sizeof(struct link));
            newer1->a=A[i];
            tmp1=start1;
            start1=newer1;
            newer1->next=tmp1;
        }
        if(index==2){
            struct link *newer2=(struct link*) malloc(sizeof(struct link));
            newer2->a=A[i];
            tmp2=start2;
            start2=newer2;
            newer2->next=tmp2;
        }
        if(index==3){
            struct link *newer3=(struct link*) malloc(sizeof(struct link));
            newer3->a=A[i];
            tmp3=start3;
            start3=newer3;
            newer3->next=tmp3;
        }
        if(index==4){
            struct link *newer4=(struct link*) malloc(sizeof(struct link));
            newer4->a=A[i];
            tmp4=start4;
            start4=newer4;
            newer4->next=tmp4;
        }

    }
    gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
    //----------------------测时间------------//

    printf("hash:\n");
    printf("building time: %ld sec\n",diff);

    //----------------------测时间------------//
    gettimeofday(&first,NULL);
    int arr[m];
    for(int i=0;i<m;i++){
        //printf("its ok?\n");
        tmp0=start0;
        tmp1=start1;
        tmp2=start2;
        tmp3=start3;
        tmp4=start4;
        int k=0;
        index=hashcode(b[i]);
        if(index==0){
           while(tmp0!=NULL){
               //printf("its ok?\n");
                if(tmp0->a==b[i]){                    
                    k=1;
                    break;
                    }
                else{
                    tmp0=tmp0->next;
                    }
             
                }
            continue;
           }
        if(index==1){
           // printf("index1");
             while(tmp1!=NULL){
                if(tmp1->a==b[i]){                    
                    k=1;
                    break;
                    }
                else{
                    tmp1=tmp1->next;
                    }
             
                }
                continue;
           }
           if(index==2){
               // printf("index2");
                while(tmp2!=NULL){
                if(tmp2->a==b[i]){                    
                    k=1;
                    break;
                    }
                else{
                    tmp2=tmp2->next;
                    }
             
                }
                 continue;
           }
           if(index==3){
                //printf("index3");
                while(tmp3!=NULL){
                if(tmp3->a==b[i]){                    
                    k=1;
                    break;
                    }
                else{
                    tmp3=tmp3->next;
                    }
             
                }
                continue;
           }
           if(index==4){
               // printf("index4");
                while(tmp4!=NULL){
                if(tmp4->a==b[i]){                    
                    k=1;
                    break;
                    }
                else{
                    tmp4=tmp4->next;
                    }
             
                }
                continue;
           }
           if(k==1){
            arr[i]=1;
        }
        else{
            arr[i]=0;
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