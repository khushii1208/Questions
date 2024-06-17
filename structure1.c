#include <stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define MAX 3
 
typedef struct sales{
    char empID[5];
    int total_sales_amount;
}sales;
 
int main()
{
    //printf("Hello World");
    sales *s;
     s=(sales*)malloc(MAX*sizeof(sales));
     for(int i=0;i<MAX;i++){
         printf("Enter the EmpID:\t");
         scanf("%s",(s+i)->empID);
         printf("Enter the Sales_amount:\t");
         scanf("%d",&(s+i)->total_sales_amount);
     }
    //  for(int i=0;i<MAX;i++){
    //      printf("Enter the EmpID:\t");
    //      printf("%s\t",(s+i)->empID);
    //      printf("Enter the Sales_amount:\t");
    //      printf("%d\n", (s+i)->total_sales_amount);
    //  }
    for(int i=0;i<MAX;i++){
        for(int j=0;j<=i;j++){
            if(strcmp((s+i)->empID,(s+j)->empID)==0&&((s+i)->total_sales_amount>(s+j)->total_sales_amount)){
               (s+j)->total_sales_amount= (s+i)->total_sales_amount;
            }
            if(strcmp((s+i)->empID,(s+j)->empID)==0&&((s+i)->total_sales_amount<(s+j)->total_sales_amount)){
               (s+i)->total_sales_amount= (s+j)->total_sales_amount;
            }
        }
    }
    // for(int i=0;i<MAX;i++){
    //      printf("Enter the EmpID:\t");
    //      printf("%s\t",(s+i)->empID);
    //      printf("Enter the Sales_amount:\t");
    //      printf("%d\n", (s+i)->total_sales_amount);
    //  }
    int flag=0;
     for(int i=0;i<MAX;i++){
        for(int j=0;j<i;j++){
            if(strcmp((s+i)->empID,(s+j)->empID)==0){
                flag=1;
               break;
            }
        }
        if(flag==1){
            flag=0;
            continue;
        }
        else{
            printf("%s-%d\n",(s+i)->empID, (s+i)->total_sales_amount);
        }
    }
    return 0;
}

