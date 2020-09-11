//
// Created by 008 on 2020/9/9.
//
#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;//认为int 是QElemType

typedef struct QNode{     //队列结点定义
    QElemType data;       //包括一个数据域
    struct QNode *next;   //一个指针域，指向下一个结点
}QNode,*QueuePtr;

typedef struct{  //队列的结构体定义
    QueuePtr front,rear;
}LinkQueue;

void InitQueue(LinkQueue *Q){//初始化
    QueuePtr H=(QueuePtr)malloc(sizeof(QNode));//给头结点分配内存
    if(!H){
        printf("内存分配失败");
        exit(1);
    }
    Q->front=H;        //front和rear都指向头结点
    Q->rear=H;
}

void EnQueue(LinkQueue *Q,QElemType e){//入队列，传入头结点指针
    QueuePtr S=(QueuePtr)malloc(sizeof(QNode));//给插入的结点分配动态内存
    if(!S){
        exit(2);
    }
    S->next=NULL;//新结点的next指向空
    S->data=e;
    Q->rear->next=S;
    Q->rear=S;
}

void DeQueue(LinkQueue *Q,QElemType *e){//出队列，并用*e存储出去的值
    if(Q->front==Q->rear){
        exit(3);
    }
    QueuePtr P;
    P=Q->front->next;
    *e=P->data;
    Q->front->next=P->next;
    if(Q->rear==P){   //只剩下最后一个元素了，那么就要先将rear指针指向头结点
        Q->rear=Q->front;
    }
    free(P);
}

void Print(LinkQueue *Q){//打印函数，队列空不打印
    if(Q->front==Q->rear){
        printf("链队列已空\n");
        exit(3);
    }
    QueuePtr p;
    p=Q->front->next;
    while(p){
        printf("%d  ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    LinkQueue Q;
    InitQueue(&Q);
    int num,e,i;
    for(i=0;i<10;i++){
        EnQueue(&Q,i);
    }
    printf("此时链队列为：");
    Print(&Q);
    printf("输入要删除的结点的个数：");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("删除第%d个结点，此时链队列为：\n",i+1);
        DeQueue(&Q,&e);
        Print(&Q);
    }
    printf("\n最终队列为：\n");
    Print(&Q);
}
