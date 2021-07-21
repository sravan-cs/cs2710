#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
     char str[13];
    gets(str);//taking the input digit sequence as a sting
    int k=0;
    k=strlen(str);//k is declared to store the length of the string
    long int n=0;//n is the input digit sequence converted into inteer
    for(int i=k-1;i>=0;i--){n=n+(str[k-i-1]-'0')*pow(10,i);}//convrting into integer based on the place value
    printf("%ld",n);
    
    
    /* enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}