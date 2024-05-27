#include <stdio.h>
int main()
{
    int n, b;
    int sum=0;
    printf("Enter a number:");
    scanf("%d", &n);
    while(n>0)
    {
        b=n%10;
        sum=sum+b;
        n=n/10;
    }
    printf("The sume of digits of the above number is: %d", sum);
}

