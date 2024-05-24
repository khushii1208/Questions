#include <stdio.h>

int main()
{
    float celcius, fah;
    printf(" Enter the Temperature in Celcius: ");
    scanf("%f",&celcius);
    fah=((celcius*9)/5)+32;
    printf(" The Temperature in Fahrenhiet is: %f",fah);
}
