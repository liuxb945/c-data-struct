//
// Created by 008 on 2020/9/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSTRLEN 40
#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
#define OVERFLOW -2

typedef int Status;
typedef char SString[MAXSTRLEN+1];

Status StrEmpty(SString S);
Status StrAssign(SString T,char *chars);
Status StrCopy(SString T,SString S);
Status StrLength(SString T);
Status StrPrint(SString T);
Status StrClear(SString S);
Status StrConcat(SString T,SString S1,SString S2);
Status StrIndex(SString T,SString S,int *pos);
Status StrInsert(SString T,SString S,int pos);
Status StrDelete(SString T,int pos,int len);

int Index_BF(SString S, SString T, int pos)
//TΪģʽ���� SΪ������   ����ģʽT������S�е�pos
//���ַ���ʼ��һ�γ��ֵ�λ�á����������򷵻�0��
{
    int i = pos, j = 1;
    while(i <= S[0] && j <= T[0]){  //��֤��������Ϊ����������
        if(S[i] == T[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 2;
            // �������к��ˣ��˵���n�αȽϵ�λ�õĺ�һλ��
            //���е�n+1�δ�ͷ���� j == 0 ��λ�ã�Ҳ����
            //ģʽ���ĵ�һ����ĸ���Ƚϡ�
            j = 1;  //��ģʽ���ĵ�һ����ʼ�����±Ƚϣ�
        }
    }
    if(j > T[0]) return (i - T[0]);
    else return 0;
}
int main()
{
    SString S;
    char cs[]="abcde";
    StrAssign(S,cs);
    SString T;
    char ct[]="bcd";
    StrAssign(T,ct);
    int i, pos = 1;
    i = Index_BF(S, T, pos);
    if(i == 0)
        printf("match fault");
    else
        printf("match success loc = %d", i);
    return 0;
}

/* �ַ�����ֵ,����ֵ�ַ������ȳ�������ֵ�ַ���ʱ��ض�,δ����ʱ�Ƚ����ȴ���T[0],����λ��ֵ */
Status StrAssign(SString T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSTRLEN)
    {
        for(i = 1;i <= MAXSTRLEN;i++)
        {
            T[i] = *(chars + i - 1);
        }
        T[0] = MAXSTRLEN;  //T[0]����int �����ݣ�%s�޷���ӡ
    }
    else
    {
        T[0] = strlen(chars);  //T[0]�������chars���ַ�����
        for(i = 1;i <= strlen(chars);i++)
        {
            T[i] = *(chars + i - 1);
        }
    }
    return OK;
}

/* �ַ�������,����ַ�����(���������ȷ�Χ�ڵ�) */
Status StrCopy(SString T,SString S)
{
    int i;
    for(i = 1;i <= S[0];i++)
    {
        T[i] = S[i];
    }
    T[0] = S[0];
    return OK;
}

/*  �ַ����пգ�S[0] == 0ʱΪ��  */
Status StrEmpty(SString T)
{
    if(T[0] == 0)
    {
        printf("The string is empty!\n");
        return TURE;
    }
    else
    {
        printf("The string is NOT empty!\n");
        return FALSE;
    }
}

/*  ���ظ��ַ����ĳ���  */
Status StrLength(SString T)
{
    return T[0];
}

/*  ��ӡ�ַ���  */
Status StrPrint(SString T)
{
    int i;
    for(i = 1;i <= T[0];i++)
        printf("%c",T[i]);
    printf("\n");
    return OK;
}
/*  ����ַ�������������� */
Status StrClear(SString S)
{
    S[0] = 0;
    return OK;
}

/*  �ַ�������,ͨ��T���洢���,S2���Ӷ��ɵ��´�,��δ�ض��򷵻�TRUE,�ضϷ���FAlSE,ע���ַ�������Խ������  */
Status StrConcat(SString T,SString S1,SString S2)
{
    int i;
    if(S1[0]+S2[0] <= MAXSTRLEN)
    {
        for(i = 1;i <= S1[0];i++)
        {
            T[i] = S1[i];
        }
        for(i = 1;i <= S2[0];i++)
        {
            T[S1[0]+i] = S2[i];
        }
        T[0] = S1[0] + S2[0];
        return TURE;
    }
    else
    {
        for(i = 1;i <= S1[0];i++)
        {
            T[i] = S1[i];
        }
        for(i = 1;i <= (MAXSTRLEN-S1[0]);i++)
        {
            T[S1[0]+i] = S2[i];
        }
        T[0] = MAXSTRLEN;
        return FALSE;
    }
}

/*  �����Ӵ�,���ش�T�е�һ���������봮S��ͬ���Ӵ���λ��  */
Status StrIndex(SString T,SString S,int *pos)
{
    int i=1,j=1;
    while((i <= T[0]) && (j <= S[0]))
    {
        if(T[i] == S[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > S[0])
    {
        *pos = i - j + 1;
        printf("Found,position is %d\n",*pos);
        return OK;
    }
    else
    {
        printf("NOT find child string yet.\n");
        return ERROR;
    }
}

/*  �ڴ�T�ĵ�pos��λ�ú�����Ӵ�S  */
Status StrInsert(SString T,SString S,int pos)
{
    int i;
    if(pos > T[0])
    {
        pos = T[0] +1;
    }
    if(T[0] + S[0] <= MAXSTRLEN)
    {
        for(i = 1; i <= pos;i++)
            T[T[0] + S[0] - i +1] = T[T[0] + S[0] - i -pos];
        for(i = 1;i <= S[0];i++)
            T[pos + i] = S[i];
        T[0] = T[0] + S[0];
        return OK;
    }
    if(T[0] + S[0] > MAXSTRLEN)
    {
        for(i = 1;i <= (MAXSTRLEN - pos);i++)
            T[i + pos] = S[i];  //�������ֱ�ɾ��
        T[0] = MAXSTRLEN;
        return ERROR;
    }
}

/*  ɾ����T�ĵ�pos��λ���𣬳�Ϊlen���Ӵ�  */
Status StrDelete(SString T,int pos,int len)
{
    int i;
    if(pos > T[0])
        return ERROR;
    if(len > T[0])
        len = T[0] - pos + 1;
    for(i = len + pos;i <= T[0];i++)
        T[i - len] =T[i];
    T[0] = T[0] - len;
    return OK;
}
