#include <stdio.h>

int main()
{
    int s,i,j;
    printf("Input size of array:");
    scanf("%d", &s);
    int arr[s];
    printf("Input elements of array:");
    for(i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Duplicate Elements are:");
    for(i=0;i<s;i++)
    {
        for(j=i+1;j<s;j++)
        {
            if(arr[i]==arr[j]){
            printf("%d",arr[i]);
            break;
                
            }
    }
    }
}

