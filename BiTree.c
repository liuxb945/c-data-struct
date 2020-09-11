#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TElemType int
int max(int x,int y);
struct Date{
    int month;
    int day;
    int year;
};
struct Student{
    int num;
    char name[20];
    struct Date birthday;
};
int main() {
    struct Student s1={101,"zhang san",{12,14,1990}};
    printf("%d",s1.birthday.year);
    return 0;

}



int max(int x,int y){
    int z;
    z=x>y?x:y;
    return z;
}

void swap(int* pa,int* pb){
    int temp;
    temp=*pa;
    *pa=*pb;
    *pb=temp;
}

void check(int *p){
    int i;
    printf("they are fail:");
    for(int i=0;i<5;i++){
        if(p[i]<60)
            printf("%d\n",p[i]);
    }
}
