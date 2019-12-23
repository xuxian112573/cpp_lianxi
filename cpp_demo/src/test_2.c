#include<stdio.h>
int main(void)
{
    int a=10;
    int b[10];
    printf("sizeof(a):%d\n",sizeof(a));
    printf("sizeof(int *):%d\n",sizeof(int *));
    printf("sizeof(b):%d\n",sizeof(b));
    printf("sizeof(b[0]):%d\n",sizeof(b[0]));
    printf("sizeof(*b):%d\n",sizeof(*b));
    
    return 0;
}
