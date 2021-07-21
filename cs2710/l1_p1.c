#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int CheckPalindrome(char* str,int k){
    if(k==1){
        printf("YES\n");
        return 1;
    }//one letter words are always palindromes
    int unmatchcount=0;
    int front=0;
    int rear=k-1;
    while(front<k/2){
        if(str[front]!=str[rear]){
            unmatchcount++;
            break;
        }//even if one letter is unmatched the string is not a palindrome
        front++;
        rear--;
    }
    if(unmatchcount==0){
        printf("YES\n");
        return 1;
    }
    else{
        printf("NO\n");
        return 0;
    }//printind the desired output and returining the suitable value
}


int main() {
    int n=0;
    scanf("%d",&n);//taking the input
    char str[1000];//input string is stored
    int count=0;//variable to store the number of palindromes
    for(int i=0;i<n;i++){
        scanf("%s",&str);
        count=count+CheckPalindrome(str,strlen(str));//count is increased by 1 if the string is a palindrom
    }
    printf("Number of Palindromes: %d",count);

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}