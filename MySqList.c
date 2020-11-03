//
// Created by 008 on 2020/11/3.
//

#include <stdlib.h>
#include <stdio.h>
#define List_Init_Size 20
#define List_Increment 10
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct SqList{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

Status SqList_Init(SqList *L){
    L->elem=(ElemType *)malloc(List_Init_Size*sizeof(ElemType));
    if(!(L->elem)){
        return ERROR;
    }
    L->listsize=List_Init_Size;
    L->length=0;
    return OK;
}

Status SqList_Insert(SqList *L,int index,ElemType e){
    if(index<1||index>L->length+1){
        return ERROR;
    }
    if(!(L->elem)){
        return ERROR;
    }
    if(L->length+1>L->listsize){
        ElemType *newbase=(ElemType *)realloc(L->elem,(L->listsize+List_Increment)*sizeof(ElemType));
        if(!newbase){
            return ERROR;
        }
        L->elem=newbase;
        L->listsize+=List_Increment;
    }
    int i=L->length;
    while (i>=index){
        L->elem[i]=L->elem[i-1];
        i--;
    }
    L->elem[index-1]=e;
    L->length++;
    return OK;
}

Status SqList_Delete(SqList *L,int index,ElemType *e){
    if(index<1||index>L->length){
        return ERROR;
    }
    *e=L->elem[index-1];
    int i=index;
    while (i<L->length){
        L->elem[i-1]=L->elem[i];
        i++;
    }
    L->length--;
    return OK;
}

int main(){
    SqList L;
    SqList_Init(&L);
    for(int i=1;i<30;i++){
        SqList_Insert(&L,i,i);
    }
    for(int i=0;i<L.length;i++){
        printf("%d,",L.elem[i]);
    }
    SqList_Insert(&L,20,30);
    printf("\n");
    for(int i=0;i<L.length;i++){
        printf("%d,",L.elem[i]);
    }
    printf("\n");
    int v;
    SqList_Delete(&L,20,&v);
    for(int i=0;i<L.length;i++){
        printf("%d,",L.elem[i]);
    }
    printf("\n");
    printf("%d",v);
    printf("\n");
}