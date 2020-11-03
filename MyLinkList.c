//
// Created by 008 on 2020/11/3.
//
#include <stdlib.h>
#include <stdio.h>
#define OK 1;
#define ERROR 0;
#define TRUE 1;
#define FALSE 0;
typedef int Status;
typedef int ElemType;
typedef struct Node{
    ElemType data;
    struct Node *next;
} Node,*LinkList;

Status InitList(LinkList *L){
    *L=(LinkList)malloc(sizeof(Node));
    if(!(*L)){
        return ERROR;
    }
    (*L)->next=NULL;
    return OK;
}

int ListLength(LinkList L){
    int len=0;
    Node *pNode=L->next;
    while (pNode){
        len++;
        pNode=pNode->next;
    }
    return len;
}

Status List_Insert(LinkList *L,int index,ElemType e){

    if(index<1||index>ListLength(*L)+1){
        return ERROR;
    }
    int i=0;
    LinkList pNode=(*L);
    while (i<index-1){
        i++;
        pNode=pNode->next;
    }
    Node *newNode=(LinkList )malloc(sizeof(Node));
    if(!newNode){
        return ERROR;
    }
    newNode->data=e;
    newNode->next=pNode->next;
    pNode->next=newNode;

    return OK;
}

Status GetItem(LinkList L,int index,ElemType *e){
    int len=ListLength(L);
    if(index<1||index>len){
        return ERROR;
    }
    LinkList pNode=L;
    int i=0;
    while (pNode&&i<index){
        pNode=pNode->next;
        i++;
    }
    *e=pNode->data;
    return OK;
}

Status DeleteItem(LinkList *L,int index,ElemType *e){
    int len=ListLength(*L);
    if(index<1||index>len){
        return ERROR;
    }
    LinkList pNode=*L;
    int i=0;
    while (pNode&&i<index-1){
        pNode=pNode->next;
        i++;
    }

    LinkList pOld=pNode->next;
    *e=pOld->data;
    pNode->next=pOld->next;
    free(pOld);
    return OK;
}

int main(){
    LinkList L;
    InitList(&L);
    for(int i=1;i<10;i++){
        List_Insert(&L,i,i);
    }
//    LinkList pNode=L->next;
//    while (pNode){
//        printf("%d,",pNode->data);
//        pNode=pNode->next;
//    }
    ElemType v;
    for(int i=1;i<10;i++){
        GetItem(L,i,&v);
        printf("%d,",v);
    }
    DeleteItem(&L,5,&v);
    printf("\n");
    for(int i=1;i<9;i++){
        GetItem(L,i,&v);
        printf("%d,",v);
    }
    return 0;
}
