#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char buf[128];
    int i;
    
    char *p2=NULL;
    char *p1=NULL;
    
    p1=&buf[0];
    p1=&buf[1];
    p1=&buf[2];
    
    for(i=0;i<10;i++)
    {
        *p1=buf[i];
    }
    
    for(i=0;i<10;i++)
    {
        p1=&buf[i];
    }
    
    p2=(char *)malloc(100);
    strcpy(p2,"abcdefg123987654");
    for(i=0;i<10;i++)
    {
        p1=p2;
        printf("-----------1---------------\n");
        printf("%c\n",*p1);
        p1=p2+2;
        printf("------------2--------------\n");
        printf("%c\n",*p1);
        printf("-------------3-------------\n");
    }
    return 0;
    
}
