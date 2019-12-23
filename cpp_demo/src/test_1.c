#include<stdio.h>
int main(void)
{
    int a=10;
    int b[10];
    printf("b:%p,b+1: %p,&b: %p,&b+1: %p\n",b,b+1,&b,&b+1);
    return 0;
}
