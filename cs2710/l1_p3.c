#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long int n=0;
    long int k=0;
    scanf("%ld",&n);
    if(n/500!=0){k=n/500;
                printf("Denomination is : 500 and count is : %ld\n",k);
                n=n%500;
                }
    else{ printf("Denomination is : 500 and count is : 0\n");}
    if(n/100!=0){k=n/100;
                printf("Denomination is : 100 and count is : %ld\n",k);
                n=n%100;}
    else{ printf("Denomination is : 100 and count is : 0\n");}
    if(n/50!=0){k=n/50;
                printf("Denomination is : 50 and count is : %ld\n",k);
                n=n%50;}
    else{ printf("Denomination is : 50 and count is : 0\n");}
    if(n/20!=0){k=n/20;
                printf("Denomination is : 20 and count is : %ld\n",k);
                n=n%20;}
    else{ printf("Denomination is : 20 and count is : 0\n");}
    if(n/10!=0){k=n/10;
                printf("Denomination is : 10 and count is : %ld\n",k);
                n=n%10;}
     else{ printf("Denomination is : 10 and count is : 0\n");}
    if(n/5!=0){k=n/5;
                printf("Denomination is : 5 and count is : %ld\n",k);
                n=n%5;}
     else{ printf("Denomination is : 5 and count is : 0\n");}
    if(n/2!=0){k=n/2;
                printf("Denomination is : 2 and count is : %ld\n",k);
               n=n%2;}
     else{ printf("Denomination is : 2 and count is : 0\n");}
    printf("Denomination is : 1 and count is : %ld\n",n);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}