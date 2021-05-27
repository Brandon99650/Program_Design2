#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/time.h>
#include<unistd.h>
#include"all.h"
int main(int argc ,char **argv){
    struct  timeval first;
    struct  timeval end;
    unsigned  long diff;
    long long int n=atoi(argv[2]);
    long long int m=atoi(argv[4]);
    srand(  time(NULL) );
  int *buf=malloc(sizeof(int)*n);
  int *ptr=malloc(sizeof(int)*m);

  /* 指定亂數範圍 */
  int min = 0;
  int max = 32767;
  int x;
  for(int i=0;i<n;i++){
      x = rand() % (max - min + 1) + min;
      buf[i]=x;
    }
    int arr[n];
  for(int i=0;i<m;i++){
      x = rand() % (max - min + 1) + min;
      ptr[i]=x;
    }

for(int i=6;i<=argc;i++){



    if(strcmp(argv[i-1],"-arr")==0){
        gettimeofday(&first,NULL);
        arr_build(buf, n,arr);
        gettimeofday(&end,NULL);
        diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
        printf("arr:\n");
        printf("building time: %ld sec\n",diff);
        gettimeofday(&first,NULL);
        arr_search(arr,ptr,n,m);
        gettimeofday(&end,NULL);
        diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
        printf("query time: %ld sec\n",diff);
        printf("\n");
        printf("\n");
    }
    if(strcmp(argv[i-1],"-ll")==0){

    link_build(buf,n,m,ptr);

    }
    if(strcmp(argv[i-1],"-bs")==0){
        gettimeofday(&first,NULL);
        bs_build(buf, n,arr);
        gettimeofday(&end,NULL);
        diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
        printf("bs:\n");
        printf("building time: %ld sec\n",diff);
        gettimeofday(&first,NULL);
        bs_search(arr,ptr,n,m);
        gettimeofday(&end,NULL);
        diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
        printf("query time: %ld sec\n",diff);
        printf("\n");
        printf("\n");

    }
    if(strcmp(argv[i-1],"-bst")==0){
    struct tnode{
    int *key;
    struct tnode *Lchild;
    struct tnode *Rchild;
    };

    struct tnode *tree=(struct tnode *) malloc(sizeof(struct tnode));
    struct tnode *query=(struct tnode *) malloc(sizeof(struct tnode));
    char x[10];
    tree = NULL;//
    gettimeofday(&first,NULL);
    for(int i=0;i<n;i++){
        tree = BTS_Insert(tree, buf[i]);
        //printf("asdfghjk\n");
    }
    gettimeofday(&end,NULL);

    diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
        printf("bst:\n");
        printf("building time: %ld sec\n",diff);
        gettimeofday(&first,NULL);
        for(int i=0;i<m;i++){
            query=BTS_find(tree,ptr[i]);
        //printf("asdfghjk\n");
    }
        gettimeofday(&end,NULL);
    diff = 1000000 * (end.tv_sec-first.tv_sec)+ end.tv_usec-first.tv_usec;
        printf("query time: %ld sec\n",diff);
        printf("\n");
        printf("\n");

    }
    if(strcmp(argv[i-1],"-hash")==0){
        
        hash(buf,n,m,ptr);
    }


}






    return 0;
}