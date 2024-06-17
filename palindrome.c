#include <stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int len,temp,j,i;
    printf("Input string:");
    scanf("%c",&str);
    len=strlen(str);
    for(j=0;j<len;j++);
    for(i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1]){
        temp=1;
        break;
        }
    }
    if(temp==0)
    printf("The given string is a palindrome string.");
    else
    printf("The given string is not a palindrome string.");
    
}

