#include <stdio.h>

int main()
{
   int num;
   printf("Enter a Number: ");
   scanf("%d",&num);
   if(num%2==0)
   printf("\nThe given number is even.");
   else
   printf("\nThe given number is odd. ");
}
