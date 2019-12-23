#include<stdio.h>
#include<string.h>
struct People
{
    char name[64];
    int age;
};
typedef struct People1
{
    char name[64];
    int age;
}people_t;//给结构体类型起别名

typedef unsigned int u32;
int main()
{
    double b;
    char c;
    float f;
    //string s;
    
    struct  People p1;
    people_t p2;
    u32 a;
    p1.age=10;
    p2.age=13;
    a=10;
    printf("sizeof(a):%d\n",sizeof(a));
    printf("sizeof(b):%d\n",sizeof(b));
    printf("sizeof(c):%d\n",sizeof(c));
    printf("sizeof(f):%d\n",sizeof(f));
    printf("sizeof(p1):%d\n",sizeof(p1));
    printf("sizeof(p2):%d\n",sizeof(p2));
    printf("sizeof(int *):%d\n",sizeof(int *));
    printf("sizeof(char **):%d\n",sizeof(char **));
    printf("sizeof(char):%d\n",sizeof(char));
    printf("sizeof(double ):%d\n",sizeof(double ));
    
    
    
    
    return 0;
}
