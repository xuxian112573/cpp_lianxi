#include<stdio.h>

int main()
{
    int arr[]={1,3,5,7,8,3,12,54,23,56,33,99,7,0};
    int len=sizeof(arr)/sizeof(arr[0]);
    int j,k,temp=0;
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
        
    }
    printf("\n");
    for(j=0;j<len;j++)
    {
        for(k=j+1;k<len;k++)
        {
            if(arr[j]<arr[k])
                {temp=arr[k];
                arr[k]=arr[j];
                arr[j]=temp;}
        }
    }
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
        
    }
    printf("\n");
    return 0;
}
