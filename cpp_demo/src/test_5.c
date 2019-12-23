#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void getFileLen(int *p)
{
    *p=41;
    printf("*P:%d\n",*p);
}

int getFileLen2()
{
    int len=100;
    return len;
}

void getFileLen3(int file_len)
{
    file_len=100;
}

int main(void)
{
    int file_len=10;
    int *p=NULL;
    
    p=&file_len;
    file_len=20;
    *p=30;
    
    {
    
        *p=40;
        printf("file_len:%d\n",file_len);
    }
    getFileLen(&file_len);
    printf("getFileLen后 file_len:%d\n",file_len);
    getFileLen3(file_len);
    printf("getFileLen3后 file_len: %d\n",file_len);
    
    return 0;
}
