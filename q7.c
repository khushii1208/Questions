#include <stdio.h>

int main()
{
    int temp;
    printf(" Input the Temperature:");
    scanf("%d", &temp);
    if (temp>30)
    printf("\n It's hot outside, stay hydrated!");
    else if(temp>=20 && temp<=30)
    printf("\n The weather is nice and warm ");
    else if(temp>=10 && temp<=19)
    printf("\n It's a bit chilly, wear a jacket.");
    else if(temp<10)
    printf("\n It's cold outside, stay warm!");
    else
    printf("\n Wrong input");
    
}
