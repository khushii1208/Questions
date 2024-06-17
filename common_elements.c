#include <stdio.h>

int main()
{
    int s1,s2,i,j,f;
    printf("Input size of first array:\n");
    scanf("%d",&s1);
    printf("Input size of second array:\n");
    scanf("%d",&s2);
    int arr1[s1];
    int arr2[s2];
    printf("Input elements of First array:\n");
    for(i=0;i<s1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Input elements of Second array:\n");
    for(i=0;i<s2;i++)
    {
        scanf("%d",&arr2[i]);
    }
    printf("Common elements are:\n");
    for(i=0;i<s1;i++)
    {
        f=0;
        for(j=0;j<i;j++)
        {
            if(arr1[i]==arr1[j])
            {
                f=1;
                break;
                
            }
        }
                
        if(f){
        continue;
        }
        for(int k=0;k<s2;k++)
        {
            if(arr1[i]==arr2[k])
            {
                printf("%d ",arr1[i]);
                break;
            }
        }
    }
    printf("\n");
}

