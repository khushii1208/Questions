#include <stdio.h>
#include<math.h>
int main()
{

int num, sq, temp, last;
    int n =0;
 
    printf("Enter a number ");
    scanf("%d",&num);
 
    sq = num*num;  //calculating square of num
    temp = num;
 
    //Counting number of digits
    while(temp>0){
        n++;
        temp = temp/10;
    }
 
    //Extracting last n digits
    int den = floor(pow(10,n));
    last = sq % den;
 
    if(last == num)
        printf("Automorphic number ");
    else
        printf("Not Automorphic ");
 
    return 0;
}

