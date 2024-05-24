#include <stdio.h>

int main()
{
   int wt, ht, bmi;
    printf("Enter your weight in Kg:");
    scanf("%d",&wt);
    printf("\n Enter your height in Metres:");
    scanf("%d",&ht);
    bmi=wt/(ht*ht);
    if(bmi<18.5)
    printf(" \nUnderweight.");
    else if(bmi>=18.5 && bmi<=24.9)
    printf("\n Normal Weight. ");
    else if(bmi>=25 && bmi<=29.9)
    printf("\n Overweight.");
    else
    printf("\n Obesity.");
    
}

