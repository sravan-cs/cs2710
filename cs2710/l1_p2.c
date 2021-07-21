#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int k=0;//variable to store the number of inputs
    int n=0;//variale to check if the input is non zero
    scanf("%d",&k);
    int i=0;//temporary variable for for loop
    int zero_count=0;
    for(i=0;i<k;i++){scanf("%d",&n);
                     if(n!=0)
                     {printf("%d ",n);}//if it is non zero then print it
                    else{zero_count++;}}
    i=0;
    for(i=0;i<zero_count;i++){printf("0 ");}//printing all the zeroes at the end

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}