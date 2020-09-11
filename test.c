#include <stdio.h>
int get2(int a[]){
    return a[1];
}
void main(){
    int b[2]={1,3};
    printf("%d",get2(b));
}