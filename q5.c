#include <stdio.h>

int main()
{
    int n1, n2, n3;
    printf(" Enter first number:");
    scanf("%d",&n1);
    printf("\n Enter second number:");
    scanf("%d",&n2);
    printf("\n Enter third number: ");
    scanf("%d",&n3);
    if((n1>n2) && (n1>n3))
    printf("\n The first number is the largest.");
    else if((n2>n3) && (n2>n1))
    printf("\n The second number is the largest.");
    else
    printf("\n The third number is the largest.");
}
