#include <stdio.h>
#define MAX 100

int main()
{
    char str[MAX];
    char sub[MAX];
    char c;
    int a=-1,b=-1,i,j;
    printf("Input string: ");
    gets(str);
    int len=strlen(str);
    printf(" Input character to search: ");
    scanf("%c",&c);
    getchar();
    printf(" Input a substring to search: ");
    gets(sub);
    int len_Sub=strlen(sub);
    for(i=0;i<len;i++)
    {
        if(str[i]==c)
        {
            a=i;
            break;
        }
    }
    for(i=0;i<len;i++)
    {
        for (j = 0; j < len_Sub; j++) 
        {
            if (str[i + j] != sub[j]) 
            {
                break;
            }
        }
        if (j == len_Sub)
        {
            b=i;
        }
    }
    int sum=a+b;
    printf("Sum  of substrings: %d",sum);
    }

