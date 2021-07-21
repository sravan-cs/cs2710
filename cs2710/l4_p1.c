#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int median(int class1[10000],int class2[10000],int n1,int n2){
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int m=0;
    while(k!=(n1+n2+1)/2){if(class1[i]<=class2[j]){i++;
                                                  k++;
                                                  if(k==(n1+n2+1)/2){l++;}}
                         else{j++;
                              k++;
                              if(k==(n1+n2+1)/2){m++;}}}//travelling in ascending order of numbers and stopping at median
                         
    if(l==1){return class1[i-1];}
    else{return class2[j-1];}
}// function defined to calculate the median
int kthsmall(int class1[10000],int class2[10000],int n1,int n2,int k){
    int i=0;
    int j=0;
    int l=0;
    int m=0;
    int n=0;
    while(n!=k){if(class1[i]<=class2[j]){i++;
                                         n++;
                                         if(n==k){l++;}}
                else{j++;
                     n++;
                     if(n==k){m++;}}}//travelling in ascending order of numbers and stopping at kth smallest number
    if(l==1){return class1[i-1];}
    else{return class2[j-1];}  
}//function calculating the kth smallest marks 

int main() {
    int n1=0;
    int n2=0;
    int k=0;
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&k);//taking inputs of fist line
    int i=0;
    int j=0;
    int class1[10000];
    int class2[10000];
    for(i=0;i<n1;i++) {
        scanf("%d",&class1[i]);
    }
     for(j=0;j<n2;j++) {
        scanf("%d",&class2[j]);
    }//storing the marks of both classes
    int med=median(class1,class2,n1,n2);
    printf("Median is %d\n",med);
    int kthnum=kthsmall(class1,class2,n1,n2,k);
    printf("Kth Smallest is %d\n",kthnum);//printing the values of median and kth smallest number
}
   