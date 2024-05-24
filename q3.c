#include <stdio.h>

int main()
{
    float celcius, fah;
    printf(" Enter the Temperature in Fahrenhiet: ");
    scanf("%f",&fah);
    celcius=((9*fah)/5)+32;
    printf(" The Temperature in Celcius is: %f",celcius);
}
