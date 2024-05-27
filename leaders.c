#include <stdio.h>

int main()
{
  int size,i;
  printf("Input size of array:");
  scanf("%d",&size);
  int a[size];
  printf("Input elements of array:");
  for( i=0; i<size;i++)
  {
      scanf("%d",&a[i]);
  }
  int right=a[size-1];
  printf("Leaders in the array are: %d",right);
  for(i=size-2;i>=0;i--)
  {
      if(a[i]>right)
      {
          right=a[i];
          printf("%d",right);
          
      }
  }
}
  
