#include <stdio.h>
#define MAX 100
int main()
{
    char str[MAX];
    int i=0,j,k,a=0,b=0,c=0;
    printf("Input a string: ");
    gets(str);
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        for(j=i;j<=i;j++)
        {
           if(str[j]!='a' || str[j]!='e' || str[j]!='i' || str[j]!='o' || str[j]!='u' )
           {
               a++;
               break;
           }
        }
        for(k=i+1;k<len;k++)
        {
            if(str[k]!='a' || str[k]!='e' || str[k]!='i' || str[k]!='o' || str[k]!='u' )
           {
               b++;
               break;
           }
        }
        if(a>b)
        {
            c++;
        }
    }
   
    printf("Num of possible partitions= %d",c);
    return 0;
}

