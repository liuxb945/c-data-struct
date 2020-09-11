//
// Created by 008 on 2020/9/9.
//
#include<stdio.h>
#include<stdlib.h>

typedef int QElemType;//��Ϊint ��QElemType

typedef struct QNode{     //���н�㶨��
    QElemType data;       //����һ��������
    struct QNode *next;   //һ��ָ����ָ����һ�����
}QNode,*QueuePtr;

typedef struct{  //���еĽṹ�嶨��
    QueuePtr front,rear;
}LinkQueue;

void InitQueue(LinkQueue *Q){//��ʼ��
    QueuePtr H=(QueuePtr)malloc(sizeof(QNode));//��ͷ�������ڴ�
    if(!H){
        printf("�ڴ����ʧ��");
        exit(1);
    }
    Q->front=H;        //front��rear��ָ��ͷ���
    Q->rear=H;
}

void EnQueue(LinkQueue *Q,QElemType e){//����У�����ͷ���ָ��
    QueuePtr S=(QueuePtr)malloc(sizeof(QNode));//������Ľ����䶯̬�ڴ�
    if(!S){
        exit(2);
    }
    S->next=NULL;//�½���nextָ���
    S->data=e;
    Q->rear->next=S;
    Q->rear=S;
}

void DeQueue(LinkQueue *Q,QElemType *e){//�����У�����*e�洢��ȥ��ֵ
    if(Q->front==Q->rear){
        exit(3);
    }
    QueuePtr P;
    P=Q->front->next;
    *e=P->data;
    Q->front->next=P->next;
    if(Q->rear==P){   //ֻʣ�����һ��Ԫ���ˣ���ô��Ҫ�Ƚ�rearָ��ָ��ͷ���
        Q->rear=Q->front;
    }
    free(P);
}

void Print(LinkQueue *Q){//��ӡ���������пղ���ӡ
    if(Q->front==Q->rear){
        printf("�������ѿ�\n");
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
    printf("��ʱ������Ϊ��");
    Print(&Q);
    printf("����Ҫɾ���Ľ��ĸ�����");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        printf("ɾ����%d����㣬��ʱ������Ϊ��\n",i+1);
        DeQueue(&Q,&e);
        Print(&Q);
    }
    printf("\n���ն���Ϊ��\n");
    Print(&Q);
}
