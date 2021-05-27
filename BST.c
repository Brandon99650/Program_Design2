#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sys/time.h>
#include<unistd.h>
#include"all.h"
struct tnode{
    int key;
    struct tnode *Lchild;
    struct tnode *Rchild;
    };
struct tnode *BTS_Insert(struct tnode *T, int key){

    if (T==NULL){
        struct tnode *p=(struct tnode *) malloc(sizeof(struct tnode));
        p->key=key;
        p->Lchild=NULL;
        p->Rchild=NULL;
        //printf("5");
        return p; 
    }
    
    if (key-T->key<0) T->Lchild=BTS_Insert(T->Lchild, key);
    else T->Rchild =BTS_Insert(T->Rchild, key);

    return T;
}

struct tnode *BTS_find(struct tnode *T, int key){
    if (T==NULL) return NULL;

    int c=key-T->key;
    
    if (c==0) return T;
    else if (c>0) return BTS_find(T->Rchild, key);
    else return BTS_find(T->Lchild, key);
}