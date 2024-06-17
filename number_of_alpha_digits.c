#include <stdio.h>
#define MAX 100
int main()
{
    char str[MAX];
    int i,len;
    printf("Input string:");
    gets(str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i]-=32;
        }
        else
        str[i]+=32;
    }
    printf("%s",str);
    return 0;
}

