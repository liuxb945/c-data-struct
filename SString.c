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
//T为模式串， S为主串，   返回模式T在主串S中第pos
//个字符开始第一次出现的位置。若不存在则返回0；
{
    int i = pos, j = 1;
    while(i <= S[0] && j <= T[0]){  //保证两个串都为超过自身长度
        if(S[i] == T[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 2;
            // 在主串中后退，退到第n次比较的位置的后一位，
            //进行第n+1次从头（当 j == 0 的位置，也就是
            //模式串的第一个字母）比较。
            j = 1;  //从模式串的第一个开始再重新比较；
        }
    }
    if(j > T[0]) return (i - T[0]);
    else return 0;
}
void get_next(SString T,int next[]){
    int i,j;
    i=1;
    next[1]=0;
    j=0;
    while (i<T[0]){
        if(j==0||T[i]==T[j]){
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
}

int Index_KMP(SString S,SString T,int pos){
    int i = pos, j = 1;
    int next[T[0]+1];
    get_next(T,next);
    while(i <= S[0] && j <= T[0]){  //保证两个串都为超过自身长度
        if(j==0||S[i] == T[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if(j > T[0]) return (i - T[0]);
    else return 0;
}

void print_nextj(char* ct,int pattern_length){
    SString T;
    StrAssign(T,ct);
    int next[pattern_length+1];
    get_next(T,next);
    for(int i=1;i<pattern_length+1;i++){
        printf("%d\t",next[i]);
    }
}

int main()
{
    /*SString S;
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
        printf("match success loc = %d", i);*/

    /*SString S;
    char cs[]="abcabaabcacde";
    StrAssign(S,cs);
    char ct[]="abaabcac";
    SString T;
    StrAssign(T,ct);
    int pattern_length=8;
    int next[pattern_length+1];
    get_next(T,next);
    for(int i=1;i<pattern_length+1;i++){
        printf("%d\t",next[i]);
    }
    int kmp_index=Index_KMP(S,T,1);
    printf("match success loc = %d", kmp_index);*/
    print_nextj("aaaab",5);
    return 0;
}



/* 字符串赋值,当赋值字符串长度超过被赋值字符串时候截断,未超过时先将长度存入T[0],再逐位赋值 */
Status StrAssign(SString T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSTRLEN)
    {
        for(i = 1;i <= MAXSTRLEN;i++)
        {
            T[i] = *(chars + i - 1);
        }
        T[0] = MAXSTRLEN;  //T[0]存入int 型数据，%s无法打印
    }
    else
    {
        T[0] = strlen(chars);  //T[0]存入的是chars的字符长度
        for(i = 1;i <= strlen(chars);i++)
        {
            T[i] = *(chars + i - 1);
        }
    }
    return OK;
}

/* 字符串拷贝,逐个字符拷贝(仅拷贝长度范围内的) */
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

/*  字符串判空，S[0] == 0时为空  */
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

/*  返回该字符串的长度  */
Status StrLength(SString T)
{
    return T[0];
}

/*  打印字符串  */
Status StrPrint(SString T)
{
    int i;
    for(i = 1;i <= T[0];i++)
        printf("%c",T[i]);
    printf("\n");
    return OK;
}
/*  清除字符串，即长度清空 */
Status StrClear(SString S)
{
    S[0] = 0;
    return OK;
}

/*  字符串联接,通过T来存储结果,S2连接而成的新串,若未截断则返回TRUE,截断返回FAlSE,注意字符串数组越界问题  */
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

/*  索引子串,返回串T中第一个索引到与串S相同的子串的位置  */
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

/*  在串T的第pos个位置后插入子串S  */
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
            T[i + pos] = S[i];  //超出部分被删除
        T[0] = MAXSTRLEN;
        return ERROR;
    }
}

/*  删除串T的第pos个位置起，长为len的子串  */
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
