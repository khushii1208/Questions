#include <stdio.h>

int main()
{
    int n,temp,a,final=0;
    printf("Enter a number:");
    scanf("%d",&n);
    temp=n;
    while(n>0)
    {
        a=n%10;
        final=final+(a*a*a);
        n=n/10;
        
    }
    if(temp==final)
    printf("It is an Armstrong number.");
    else
    
    printf("It is not an Armstrong number.");
    
}

