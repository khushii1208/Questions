#include <stdio.h>

int main()
{
   int s,i;
   printf("Input size of array:");
   scanf("%d",&s);
   int arr[s];
   printf("Input distinct numbers from 0 to %d: ",s);
   for(i=0;i<s;i++)
   {
       scanf("%d",&arr[i]);
   }
   //finding the missing element
   printf("The missing element is:");
   for(i=0;i<s;i++)
   {
       int s=arr[i]+1;
       if(s!=arr[i+1])
       {
       printf("%d",s);
           break;
       }
       
   }
}

