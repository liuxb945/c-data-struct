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
#define LIST_INIT_SIZE 100      //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10          //���Ա�洢�ռ�ķ�������
typedef struct
{
    ElemType *elem;         //�洢�ռ��ַ
    int length;                     //��ǰ����
    int listsize;                   //��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;
#endif // DECLARATION_H_INCLUDED

#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
Status InitList_Sq(SqList *L);
//����һ���յ����Ա�L
Status DestroyList_Sq(SqList *L);
//��ʼ����:���Ա��Ѵ��ڣ��������:�������Ա�L
Status ClearList_Sq(SqList *L);
//��ʼ����:���Ա��Ѵ��ڣ��������:�����Ա�L��Ϊ�ձ�
Status ListEmpty_Sq(SqList L);
//��ʼ����:���Ա��Ѵ��ڣ��������:��LΪ�ձ��򷵻�TRUE���򷵻�ERROR
Status ListLength_Sq(SqList L);
//��ʼ����:���Ա��Ѵ��ڣ��������:����L��Ԫ�صĸ���
Status GetElem_Sq(SqList L, int i, ElemType *e);
//��ʼ����:���Ա��Ѵ���,1<=i<=ListLength_Sq(L)���������:��e����L�е�i��Ԫ�ص�ֵ
Status LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
//��ʼ����:���Ա��Ѵ���,compare()������Ԫ���ж�������
//�������:����L�е�1����e����compare()��ϵ������Ԫ�ص�λ�������������������򷵻�ֵΪ0��
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType * pre_e);
//��ʼ���������Ա�L�Ѵ���
//�������:��cur_e��L��Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e);
//��ʼ���������Ա�L�Ѵ���
//�������:��cur_e��L�����ݣ��Ҳ������һ��������next_e�������ĺ�̡��������ʧ�ܣ�next_e�޶���
Status ListInsert_Sq(SqList *L, ElemType i, ElemType e);
//��ʼ����:���Ա����Ѵ��ڣ�1<=i<=ListLength_Sq(L)+1
//�������:��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
Status ListDelete_Sq(SqList *L, ElemType i, ElemType *e);
//��ʼ����:���Ա����Ѵ��ڣ�1<=i<=ListLength_Sq(L)+1
//�������:ɾ��L�е�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
Status ListTraverse_Sq(SqList L, void (*visit) (void const *));
//��ʼ����:���Ա� L�Ѵ���
//�������:���ζ�L��ÿ������Ԫ�ص���visit()������һ��visit()ʧ�ܣ������ʧ��
void visit_print(void const *e);
//�����ַe��ָ���ڴ��ֵ
void Union_Sq(SqList *La, SqList Lb);
//��������Lb�ж�����La�е����ݲ��뵽La��ȥ
Status compare_Elem(ElemType a, ElemType b);
//�Ƚ�a��b�Ĵ�С��������򷵻�1�����򷵻�0
void MergeList_Sq(SqList *La, SqList Lb,SqList *Lc);
//��ʼ��������֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
//�������:�鲢La��Lb�õ��µ����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
#endif // FUNCTION_H_INCLUDED

Status compare_Elem(ElemType a, ElemType b)
{
    if(a == b)
        return 1;//                            ����ȷ���1
    else
        return 0;
}
void visit_print(void const *e)
{
    printf("%d   ",*(int *)e);
}

Status InitList_Sq(SqList *L)
{
    //��������Ա�L
    L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L->elem)     exit(OVERFLOW);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;     //���Ա�L�ĳ�ʼ����
    return OK;
}//InitList_Sq
Status DestroyList_Sq(SqList *L)
{
    //�������Ա�L
    free(L->elem);
    L->elem=NULL;
    L->length=0;
    L->listsize=0;
    return OK;
}//DestroyList_Sq()
Status ClearList_Sq(SqList *L)
{
    //��L��Ϊ�ձ�
    L->length=0;
    return OK;
}//ClearList_Sq()
Status ListEmpty_Sq(SqList L)
{
    //�ж��Ƿ�Ϊ�ձ�
    if(L.length == 0)      return TRUE;
    else    return ERROR;
}//ListEmpty_Sq()
Status ListLength_Sq(SqList L)
{
    //�������Ա�ĳ���
    return L.length;
}//ListLength_Sq()
Status GetElem_Sq(SqList L, int i, ElemType *e)
{
    //��e����L�е�i��Ԫ�ص�ֵ
    *e=*(L.elem+i-1);
    return *e;
}//GetElem_Sq()
Status LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType , ElemType))
{
    //�����Ա����ҵ���1����e����compare()��ϵ��Ԫ�ص�λ��
    ElemType *p;
    int i=1;
    p=L.elem;
    while(i <= L.length && !(*compare)(*p++, e))   i++;
    if(i < L.length)
        return  i;    //����λ��
    else
        return 0;
}//LocateElem_Sq()
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType * pre_e)
{
    //��cur_e��L��Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
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
Status ListInsert_Sq(SqList *L, ElemType i, ElemType e)          //i��1��ʼ
{
    //i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)+1
    ElemType *newbase,*q,*p;
    if(i <1 || i>L->length+1)               //L->length��ʼΪ0
        return ERROR;
    if(L->length >= L->listsize)
    {
        newbase=(ElemType *) realloc(L->elem, (L->listsize+LISTINCREMENT) *sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        L->elem = newbase;      //�»�ַ
        L->listsize += LISTINCREMENT;  //���Ӵ洢����
    }
    q=L->elem+i-1;    //      qΪ����λ��
    for(p=(*L).elem+(*L).length-1;p>=q;--p) /* ����λ�ü�֮���Ԫ������ */
        *(p+1)=*p;
    *q=e; /* ����e */
    ++(*L).length; /* ����1 */

    return OK;
}//ListInsert_Sq()
Status ListDelete_Sq(SqList *L, ElemType i, ElemType *e)
{
    //ɾ��L�е�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
    ElemType *q,*p;
    if(i <1 || i>L->length)
        return ERROR;
    p=L->elem+L->length-1;
    q=L->elem+i-1;    //      qΪɾ��λ��
    *e=*q;
    for(q; q < p; q++) /* ɾ��λ�ü�֮���Ԫ������ */
        *q=*(q+1);
    --(*L).length; /* ����1 */
    return OK;
}//ListDelete_Sq()
Status ListTraverse_Sq(SqList L, void (*visit)( void const *))
{
    //�������:���ζ�L��ÿ������Ԫ�ص���visit()������һ��visit()ʧ�ܣ������ʧ��
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
        GetElem_Sq(Lb, i, &e);    //��eȡ��Lb�е�����
        if( !LocateElem_Sq(*La, e, compare_Elem))
            ListInsert_Sq(La, ++la_ln,e);                   //     ����������������������La�Ľ�β��������
    }
}//Union_Sq()
void MergeList_Sq(SqList *La, SqList Lb,SqList *Lc)
{
    //��La��Lb�е�Ԫ�ذ�������ϵ�ϲ���Lc��
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa=La->elem;
    pb=Lb.elem;
    Lc->listsize = Lc->length=La->length+Lb.length;
    pc=Lc->elem=(ElemType *)malloc(Lc->listsize*sizeof(ElemType));
    if(!pc)         exit(OVERFLOW);//�洢����ʧ��
    pa_last=La->elem+La->length-1;
    pb_last=Lb.elem+Lb.length-1;
    while((pa <= pa_last) && (pb <= pb_last))     //La��Lb���ǿ�
    {
        if(*pa <= *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }
    while(pa <= pa_last)    *pc ++ = *pa ++;                  //����Laʣ���Ԫ��
    while(pb <= pb_last)    *pc ++= *pb ++;                   //����Lbʣ���Ԫ��

}//MergeList_Sq()

int main()
{
    SqList La,Lb,Lc;
    Status i,e;
    int j;
    i=InitList_Sq(&La);
    if(i==1) /* �����ձ�La�ɹ� */
    {
        printf("La create success\n");
        for(j=1;j<=5;j++) /* �ڱ�La�в���5��Ԫ�� */
            ListInsert_Sq(&La,j,j);
    }
    printf("La= "); /* �����La������ */
    ListTraverse_Sq(La, visit_print);
    InitList_Sq(&Lb); /* Ҳ�ɲ��ж��Ƿ񴴽��ɹ� */
    for(j=1;j<=5;j++) /* �ڱ�Lb�в���5��Ԫ�� */
        ListInsert_Sq(&Lb,j,2*j);
    printf("Lb= "); /* �����Lb������ */
    ListTraverse_Sq(Lb,visit_print);
    printf("Lb.length is %d\n",ListLength_Sq(Lb));
    i= LocateElem_Sq(Lb, 2, compare_Elem);
    printf("Lb����2��ȵ����ڵ�%d��λ��\n",i);
    printf("La���е�%d��λ�õ�����%d\n", 3, GetElem_Sq(La, 3, &e));
    printf("La����2ǰ����%d\n", PriorElem_Sq(La, 2, &e));
    printf("La����2�ĺ����%d\n", NextElem_Sq(La, 2, &e));
    printf("\n\n");

    printf("MergeList function:");
    MergeList_Sq(&La,Lb, &Lc);
    printf("Lc= "); /* ����±�La������ */
    ListTraverse_Sq(Lc,visit_print);
    printf("Union function:");
    Union_Sq(&La,Lb);
    printf("new La= "); /* ����±�La������ */
    ListTraverse_Sq(La,visit_print);
    if(ListDelete_Sq(&La,3, &e) == OK)
    {
        printf("after delete La = ");
        ListTraverse_Sq(La, visit_print);
    }
    return 0;
}


