#include <stdio.h>

int main()
{
    int score;
    printf("Input Score between 0-100:");
    scanf("%d",&score);
    if(score>100)
    printf(" \nPlease input score between 0-100 only.");
    if(score>=90 && score<=100)
    printf(" \nGrade A");
    if(score>=80 && score<90)
    printf(" \nGrade B");
    if(score>=70 && score<80)
    printf(" \nGrade C");
    if(score>=60 && score<70)
    printf(" \nGrade D");
    if(score<60)
    printf(" \nGrade F");
    
}


