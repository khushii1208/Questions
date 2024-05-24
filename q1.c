#include <stdio.h>
#define PI 3.14
int main()
{
    float radius;
    float area;
    float cf;
    printf("Input radius of the circle:");
    scanf("%f", &radius);
    area=PI*radius*radius;
    cf=2*PI*radius;
    printf("\nThe area of circle is: %f",area);
    printf("\nThe circumference of circle is: %f",cf);
}

