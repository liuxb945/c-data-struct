//
// Created by 008 on 2020/9/9.
//
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10//线性表长度的最大值

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int Status;//状态值
typedef int ElemType;//结点的数据类型，视实际情况而定。在此以int为例。

typedef struct SqQueue{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}SqQueue;

Status InitSqQueue(SqQueue *Q){
    Q->front = Q->rear = 0;
    return OK;
}

Status ClearSqQueue(SqQueue *Q) {

    Q->rear = Q->front = 0;
    return OK;
}

int GetSqQueueLength(SqQueue Q) {

    int length = (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
    return length;
}

//判断循环队列是否为空
int isSqQueueClear(SqQueue Q) {

    if (Q.rear == Q.front) {
        return 1;
    }else {
        return 0;
    }
}

Status PushSqQueue(SqQueue *Q, ElemType e) {

    //队满不能入队
    if ((Q->rear+1)%MAXSIZE == Q->front) {
        return ERROR;
    }

    Q->data[Q->rear] = e;

    Q->rear = (Q->rear+1)%MAXSIZE;

    return OK;
}

Status PopSqQueue(SqQueue *Q, ElemType *e) {
    //队列为空不能出队
    if (Q->front == Q->rear) {
        return ERROR;
    }
    //返回出队元素
    *e = Q->data[Q->front];

    Q->front = (Q->front+1)%MAXSIZE;

    return OK;
}

void Print(SqQueue Q){
    int i=0;
    printf("\n");
    /*if(Q->front>Q->rear){
        while(Q->front+i==MAXSIZE){
            printf("%d  ",Q->data[Q->front+i]);
            i++;
        }
        i=0;
        while(i!=Q->rear){
            printf("%d  ",Q->data[i]);
            i++;
        }
    }
    else{
        i=Q->front;
        while(i!=Q->rear){
            printf("%d  ",Q->data[i]);
            i++;
        }
    }*/
    int index=Q.front;
    while (index%MAXSIZE!=Q.rear){
        printf("%d  ",Q.data[index%MAXSIZE]);
        index++;
    }
    printf("\n");
}

int main(){
    int num;//要删除的元素个数
    int e;//用于接收删除的元素
    SqQueue Q;
    InitSqQueue(&Q);
    for(int i=0;i<12;i++){//入队列
        PushSqQueue(&Q,i);
    }
    printf("队列长度为：%d \n",GetSqQueueLength(Q));
    Print(Q);
    printf("输入要删除的元素个数（从队首进行删除）\n");
    scanf("%d",&num);
    for(int i=0;i<num;i++){//偷懒通过循环删除队列
        if(!PopSqQueue(&Q,&e))
            break;
        printf("删除了一个元素%d，此时队列为：",e);
        Print(Q);
        printf("\n");
    }
    for(int i=0;i<12;i++){//入队列
        PushSqQueue(&Q,i);
    }
    printf("最终队列为:");
    Print(Q);
}

