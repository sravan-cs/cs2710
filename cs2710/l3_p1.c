#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
    struct complexnum{
        double real;
        double imaginary;
    };
int main() {
    int n=0;
    scanf("%d",&n);
    struct complexnum* num1;
    struct complexnum* num2;
    struct complexnum* num3;
    num1=(struct complexnum*)malloc(sizeof(struct complexnum));
    num2=(struct complexnum*)malloc(sizeof(struct complexnum));    
    num3=(struct complexnum*)malloc(sizeof(struct complexnum));   
    int i=0;
    char c;
    struct complexnum* sum(num1,num2);
    struct complexnum* dif(num1,num2);
    struct complexnum* prod(num1,num2);
    struct complexnum* divi(num1,num2);
    for(i=0;i<n;i++){
        scanf("%c",&c);
         scanf("%c",&c);
        scanf("%lf",&num1->real);
        scanf("%lf",&num1->imaginary);
        scanf("%lf",&num2->real);
        scanf("%lf",&num2->imaginary);
        if(c=='+'){num3=sum(num1,num2);}
        if(c=='-'){num3=dif(num1,num2);}        
        if(c=='*'){num3=prod(num1,num2);}
        if(c=='/'){num3=divi(num1,num2);}
        printf("%.2f + %.2fi\n",num3->real,num3->imaginary);
         scanf("%c",&c);
        
    }
   return 0;
}
struct complexnum* sum(struct complexnum* num1,struct complexnum* num2)
{
    struct complexnum* res1;
    res1=(struct complexnum*)malloc(sizeof(struct complexnum));
    res1->real=num1->real+num2->real;
    res1->imaginary=num1->imaginary+num2->imaginary;
    return res1;
}
struct complexnum* dif(struct complexnum* num1,struct complexnum* num2)
{
    struct complexnum* res2;
   res2=(struct complexnum*)malloc(sizeof(struct complexnum));
    res2->real=num1->real-num2->real;
    res2->imaginary=num1->imaginary-num2->imaginary;
    return res2;
}
struct complexnum* prod(struct complexnum* num1,struct complexnum* num2)  
{
    struct complexnum* res3;
    res3=(struct complexnum*)malloc(sizeof(struct complexnum));
    res3->real=(num1->real*num2->real)-(num1->imaginary*num2->imaginary);
    res3->imaginary=(num1->imaginary*num2->real)+(num1->real*num2->imaginary);
    return res3;
}    
struct complexnum* divi(struct complexnum* num1,struct complexnum* num2)
{
    struct complexnum* res4;
    res4=(struct complexnum*)malloc(sizeof(struct complexnum));
                  res4->real=((num1->real*num2->real)+(num1->imaginary*num2->imaginary))/(num2->real*num2->real+num2->imaginary*num2->imaginary);
                  res4->imaginary=((num1->imaginary*num2->real)-(num1->real*num2->imaginary))/(num2->real*num2->real+num2->imaginary*num2->imaginary);    
    return res4;
}

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */      

