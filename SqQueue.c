//
// Created by 008 on 2020/9/9.
//
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10//���Ա��ȵ����ֵ

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int Status;//״ֵ̬
typedef int ElemType;//�����������ͣ���ʵ������������ڴ���intΪ����

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

//�ж�ѭ�������Ƿ�Ϊ��
int isSqQueueClear(SqQueue Q) {

    if (Q.rear == Q.front) {
        return 1;
    }else {
        return 0;
    }
}

Status PushSqQueue(SqQueue *Q, ElemType e) {

    //�����������
    if ((Q->rear+1)%MAXSIZE == Q->front) {
        return ERROR;
    }

    Q->data[Q->rear] = e;

    Q->rear = (Q->rear+1)%MAXSIZE;

    return OK;
}

Status PopSqQueue(SqQueue *Q, ElemType *e) {
    //����Ϊ�ղ��ܳ���
    if (Q->front == Q->rear) {
        return ERROR;
    }
    //���س���Ԫ��
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
    int num;//Ҫɾ����Ԫ�ظ���
    int e;//���ڽ���ɾ����Ԫ��
    SqQueue Q;
    InitSqQueue(&Q);
    for(int i=0;i<12;i++){//�����
        PushSqQueue(&Q,i);
    }
    printf("���г���Ϊ��%d \n",GetSqQueueLength(Q));
    Print(Q);
    printf("����Ҫɾ����Ԫ�ظ������Ӷ��׽���ɾ����\n");
    scanf("%d",&num);
    for(int i=0;i<num;i++){//͵��ͨ��ѭ��ɾ������
        if(!PopSqQueue(&Q,&e))
            break;
        printf("ɾ����һ��Ԫ��%d����ʱ����Ϊ��",e);
        Print(Q);
        printf("\n");
    }
    for(int i=0;i<12;i++){//�����
        PushSqQueue(&Q,i);
    }
    printf("���ն���Ϊ:");
    Print(Q);
}

