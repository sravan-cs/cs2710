#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int count = 0;
long int integer(char a[5000],int i,int j)            
                                                
{
    int n = j-i;
    long int l = 0;
    int k = 0;
    while(n>-1)
    {
        l=l+(a[i+n]-48)*pow(10,k);
        k++;
        n--;
    }
    return l;
}/*function defined to convert string into integer*/


long int solve (char string[5000], int n)        
{                                                   
    if(n==-1){return 0;}                                    
    int i=n;     
    long int k=0;
    count++;
    while(i>-1 && string[i] != '+' && string[i] != '-'){
    i--;
    k = integer(string,i+1,n);    
    }/*to find out the integer between two signs*/
    if(i==-1)
    {
        printf("count=%d\n",count); 
        printf("%ld\n",k);                                           
        return k;
    }
    long int l = solve(string,i-1);/*now all the input integers are being taken*/         
    if(string[i] == '+')
    {
        printf("%ld+%ld\n",l,k);                              
        return (k+l);
    }
     else
    {
        if(i!=0)
        {
           printf("%ld-%ld\n",l,k); 
        }
        if(i==0)
        {
            printf("count=%d\n",count);
            printf("-%ld\n",k);                                
        }
        return (l - k);
    }

}/*the sum is calculated recursively*/


int main()
{
    int n =0;
    char string[5000];
    scanf("%s",string);                                         
    n=strlen(string);
    long int sum =0;
    sum=solve(string,n-1);
    printf("answer=%ld\n",sum);/*the value of sum being calculated recursively is printed*/
    return 0;
}


