#include <stdio.h>
#include <stdlib.h>
#ifndef DECLARATION_H_INCLUDED
#define DECLARATION_H_INCLUDED
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define ElemType int
typedef int Status;
#define LIST_INIT_SIZE 100      //线性表存储空间的初始分配量
#define LISTINCREMENT 10          //线性表存储空间的分配增量
typedef struct
{
    ElemType *elem;         //存储空间基址
    int length;                     //当前长度
    int listsize;                   //当前分配的存储容量(以sizeof(ElemType)为单位)
}SqList;
#endif // DECLARATION_H_INCLUDED

#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
Status InitList_Sq(SqList *L);
//构造一个空的线性表L
Status DestroyList_Sq(SqList *L);
//初始条件:线性表已存在；操作结果:销毁线性表L
Status ClearList_Sq(SqList *L);
//初始条件:线性表已存在；操作结果:将线性表L置为空表
Status ListEmpty_Sq(SqList L);
//初始条件:线性表已存在；操作结果:若L为空表则返回TRUE否则返回ERROR
Status ListLength_Sq(SqList L);
//初始条件:线性表已存在；操作结果:返回L中元素的个数
Status GetElem_Sq(SqList L, int i, ElemType *e);
//初始条件:线性表已存在,1<=i<=ListLength_Sq(L)；操作结果:用e返回L中第i个元素的值
Status LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
//初始条件:线性表已存在,compare()是数据元素判定函数；
//操作结果:返回L中第1个与e满足compare()关系的数据元素的位序。若这样的数不存在则返回值为0。
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType * pre_e);
//初始条件：线性表L已存在
//操作结果:若cur_e是L的元素，且不是第一个，则用pre_e返回它的前驱。否则操作失败，pre_e无定义
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e);
//初始条件：线性表L已存在
//操作结果:若cur_e是L的数据，且不是最后一个，则用next_e返回它的后继。否则操作失败，next_e无定义
Status ListInsert_Sq(SqList *L, ElemType i, ElemType e);
//初始条件:线性表你已存在，1<=i<=ListLength_Sq(L)+1
//操作结果:在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListDelete_Sq(SqList *L, ElemType i, ElemType *e);
//初始条件:线性表你已存在，1<=i<=ListLength_Sq(L)+1
//操作结果:删除L中第i个数据元素，并用e返回其值，L的长度减1
Status ListTraverse_Sq(SqList L, void (*visit) (void const *));
//初始条件:线性表 L已存在
//操作结果:依次对L的每个数据元素调用visit()函数。一旦visit()失败，则操作失败
void visit_print(void const *e);
//输出地址e所指向内存的值
void Union_Sq(SqList *La, SqList Lb);
//将存在于Lb中而不在La中的数据插入到La中去
Status compare_Elem(ElemType a, ElemType b);
//比较a，b的大小，若相等则返回1，否则返回0
void MergeList_Sq(SqList *La, SqList Lb,SqList *Lc);
//初始条件：已知顺序线性表La和Lb的元素按值非递减排列
//操作结果:归并La和Lb得到新的线性表Lc,Lc的元素也按值非递减排列
#endif // FUNCTION_H_INCLUDED

Status compare_Elem(ElemType a, ElemType b)
{
    if(a == b)
        return 1;//                            若相等返回1
    else
        return 0;
}
void visit_print(void const *e)
{
    printf("%d   ",*(int *)e);
}

Status InitList_Sq(SqList *L)
{
    //构造空线性表L
    L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem)     exit(OVERFLOW);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;     //线性表L的初始容量
    return OK;
}//InitList_Sq
Status DestroyList_Sq(SqList *L)
{
    //销毁线性表L
    free(L->elem);
    L->elem=NULL;
    L->length=0;
    L->listsize=0;
    return OK;
}//DestroyList_Sq()
Status ClearList_Sq(SqList *L)
{
    //将L置为空表
    L->length=0;
    return OK;
}//ClearList_Sq()
Status ListEmpty_Sq(SqList L)
{
    //判断是否为空表
    if(L.length == 0)      return TRUE;
    else    return ERROR;
}//ListEmpty_Sq()
Status ListLength_Sq(SqList L)
{
    //返回线性表的长度
    return L.length;
}//ListLength_Sq()
Status GetElem_Sq(SqList L, int i, ElemType *e)
{
    //用e返回L中第i个元素的值
    *e=*(L.elem+i-1);
    return *e;
}//GetElem_Sq()
Status LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType , ElemType))
{
    //在线性表中找到第1个与e满足compare()关系的元素的位序
    ElemType *p;
    int i=1;
    p=L.elem;
    while(i <= L.length && !(*compare)(*p++, e))   i++;
    if(i < L.length)
        return  i;    //返回位置
    else
        return 0;
}//LocateElem_Sq()
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType * pre_e)
{
    //若cur_e是L的元素，且不是第一个，则用pre_e返回它的前驱。否则操作失败，pre_e无定义
    ElemType *p,i=1;
    p=L.elem;
    if(*(L.elem) == cur_e)
    {
        printf("%d is the first place has no PreElem", cur_e);
        return INFEASIBLE;
    }
    else
    {
        while(*p != cur_e)  p += i++;
        if(i> 0 && i < L.length)
        {
            *pre_e=*(p-1);
            return *pre_e;
        }
        else
        {
            return INFEASIBLE;
        }
    }

}//PriorElem_Sq()
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e)
{
    ElemType *p,i=1;
    p=L.elem;
    while( *p != cur_e) p+= i++;
    if(p == L.elem+L.length-1)
    {
        printf("%d is the last letter has no next_elem\n", cur_e);
        return INFEASIBLE;
    }
    else
        return *next_e=*(p+1);

}//NextElem_Sq()
Status ListInsert_Sq(SqList *L, ElemType i, ElemType e)          //i从1开始
{
    //i的合法值为1<=i<=ListLength_Sq(L)+1
    ElemType *newbase,*q,*p;
    if(i <1 || i>L->length+1)               //L->length初始为0
        return ERROR;
    if(L->length >= L->listsize)
    {
        newbase=(ElemType *) realloc(L->elem, (L->listsize+LISTINCREMENT) *sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        L->elem = newbase;      //新基址
        L->listsize += LISTINCREMENT;  //增加存储容量
    }
    q=L->elem+i-1;    //      q为插入位置
    for(p=(*L).elem+(*L).length-1;p>=q;--p) /* 插入位置及之后的元素右移 */
        *(p+1)=*p;
    *q=e; /* 插入e */
    ++(*L).length; /* 表长增1 */

    return OK;
}//ListInsert_Sq()
Status ListDelete_Sq(SqList *L, ElemType i, ElemType *e)
{
    //删除L中第i个数据元素，并用e返回其值，L的长度减1
    ElemType *q,*p;
    if(i <1 || i>L->length)
        return ERROR;
    p=L->elem+L->length-1;
    q=L->elem+i-1;    //      q为删除位置
    *e=*q;
    for(q; q < p; q++) /* 删除位置及之后的元素左移 */
        *q=*(q+1);
    --(*L).length; /* 表长减1 */
    return OK;
}//ListDelete_Sq()
Status ListTraverse_Sq(SqList L, void (*visit)( void const *))
{
    //操作结果:依次对L的每个数据元素调用visit()函数。一旦visit()失败，则操作失败
    ElemType *ptr;
    ptr=L.elem;
    ElemType i=0;
    for(i=0 ;i < L.length;i++)
        visit(ptr+i);
    printf("\n");
    return OK;
}//ListTraverse_Sq()
void Union_Sq(SqList *La, SqList Lb)
{
    ElemType la_ln,lb_ln,e;
    la_ln=ListLength_Sq(*La);
    lb_ln=ListLength_Sq(Lb);
    ElemType i=1;
    for( i; i <= lb_ln; i++)
    {
        GetElem_Sq(Lb, i, &e);    //用e取得Lb中的数据
        if( !LocateElem_Sq(*La, e, compare_Elem))
            ListInsert_Sq(La, ++la_ln,e);                   //     若不存在这样的数，就在La的结尾添加这个数
    }
}//Union_Sq()
void MergeList_Sq(SqList *La, SqList Lb,SqList *Lc)
{
    //将La和Lb中的元素按递增关系合并到Lc中
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa=La->elem;
    pb=Lb.elem;
    Lc->listsize = Lc->length=La->length+Lb.length;
    pc=Lc->elem=(ElemType *)malloc(Lc->listsize*sizeof(ElemType));
    if(!pc)         exit(OVERFLOW);//存储分配失败
    pa_last=La->elem+La->length-1;
    pb_last=Lb.elem+Lb.length-1;
    while((pa <= pa_last) && (pb <= pb_last))     //La和Lb均非空
    {
        if(*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while(pa <= pa_last)    *pc ++ = *pa ++;                  //插入La剩余的元素
    while(pb <= pb_last)    *pc ++= *pb ++;                   //插入Lb剩余的元素

}//MergeList_Sq()

int main()
{
    SqList La,Lb,Lc;
    Status i,e;
    int j;
    i=InitList_Sq(&La);
    if(i==1) /* 创建空表La成功 */
    {
        printf("La create success\n");
        for(j=1;j<=5;j++) /* 在表La中插入5个元素 */
            ListInsert_Sq(&La,j,j);
    }
    printf("La= "); /* 输出表La的内容 */
    ListTraverse_Sq(La, visit_print);
    InitList_Sq(&Lb); /* 也可不判断是否创建成功 */
    for(j=1;j<=5;j++) /* 在表Lb中插入5个元素 */
        ListInsert_Sq(&Lb,j,2*j);
    printf("Lb= "); /* 输出表Lb的内容 */
    ListTraverse_Sq(Lb,visit_print);
    printf("Lb.length is %d\n",ListLength_Sq(Lb));
    i= LocateElem_Sq(Lb, 2, compare_Elem);
    printf("Lb中与2相等的数在第%d个位置\n",i);
    printf("La表中第%d个位置的数是%d\n", 3, GetElem_Sq(La, 3, &e));
    printf("La表中2前驱是%d\n", PriorElem_Sq(La, 2, &e));
    printf("La表中2的后继是%d\n", NextElem_Sq(La, 2, &e));
    printf("\n\n");

    printf("MergeList function:");
    MergeList_Sq(&La,Lb, &Lc);
    printf("Lc= "); /* 输出新表La的内容 */
    ListTraverse_Sq(Lc,visit_print);
    printf("Union function:");
    Union_Sq(&La,Lb);
    printf("new La= "); /* 输出新表La的内容 */
    ListTraverse_Sq(La,visit_print);
    if(ListDelete_Sq(&La,3, &e) == OK)
    {
        printf("after delete La = ");
        ListTraverse_Sq(La, visit_print);
    }
    return 0;
}


