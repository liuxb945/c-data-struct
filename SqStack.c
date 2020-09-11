//
// Created by 008 on 2020/9/9.
//

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef struct
{
    SElemType *base; /* 在栈构造之前和销毁之后，base值为NULL */
    SElemType *top;  /* 栈顶指针 */
    int stacksize;   /* 当前已分配的存储空间，以元素为单位 */
}SqStack;

/* 构造一个空战 */
Status InitStack(SqStack *S)
{
    S->base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S->base)
        return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

/* 销毁栈S，S不再存在 */
Status DestoryStack(SqStack *S)
{
    if(!S->base)
        return ERROR;
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
    return OK;
}

/* 把栈S置为空栈 */
Status ClearStack(SqStack *S)
{
    if(!S->base)
        return ERROR;
    S->top =  S->base;
    return OK;
}

/* 如果栈为空则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack *S)
{
    if(!S->base)
        return ERROR;
    if( S->top ==  S->base)
        return TRUE;
    else
        return FALSE;
}

/* 返回栈的长度 */
int StackLength(SqStack *S)
{
    if(!S->base)
        return ERROR;
    return S->top - S->base;
}

/* 若栈不为空，则用e返回S的栈顶元素，并返回OK,否则返回ERROR */
Status GetTop(SqStack *S, SElemType *e)
{
    if(!S->base || S->top == S->base)
        return ERROR;
    *e = *(S->top-1);
    return OK;
}

/* 插入元素e为新的栈顶 */
Status Push(SqStack *S, SElemType e)
{
    if( S->top - S->base >= S->stacksize ) { /* 栈满，追加存储空间 */
        SElemType * ptr = (SElemType *)realloc( S->base,
                                                (S->stacksize + STACK_INCREMENT)*sizeof(SElemType) );
        if(!ptr)
            return ERROR;
        S->base = ptr;
        S->top = S->base + S->stacksize; /* top重新指向新的地址 */
        S->stacksize += STACK_INCREMENT;
    }
    *(S->top) = e;
    S->top++;
    return OK;
}

/* 若栈不空，则弹出栈顶元素，用e保存返回值 */
Status Pop(SqStack *S,SElemType *e)
{
    if(S->top == S->base) /* 栈空了 */
        return ERROR;
    *e = *(S->top-1);
    S->top--;
    return OK;
}

/* 从栈顶往下打印栈中的数据 */
void printSqStack(SqStack *S)
{
    SElemType * p = S->top;
    while (p != S->base) {
        printf("%d ",*(p-1));
        p--;
    }
    printf("\n");
}

int main()
{
    SqStack S;
    SqStack * pS = &S;
    SElemType e;

    // 初始化栈
    InitStack(pS);

    // push 测试
    for(int i=1;i<=110;i++) {
        Push(pS,i);
    }

    // 获取栈长度测试
    printf("len %d\n",StackLength(pS));

    // 弹出栈顶
    Pop(pS,&e);
    printf("pop %d\n",e);

    // 打印栈测试
    printSqStack(pS);

    // 获取栈顶测试
    GetTop(pS,&e);
    printf("top %d\n",e);

    // 销毁测试
    DestoryStack(pS);
    printf("\nreturn 0\n");
}