#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int * bidirectionalbubblesort(int * r,int n){
    int i =0;//index for bubble sort
    int j=0;//index for reverse bubble sort
    int k=1;//variable used to stop while loop
    int l=0;
    int m=1;// variables for bindex and eindex
    int temp=0;//variable used in exchanging values
    int o=0;//variable declared to keep count of number of exchanges
    int* sortedarr=(int*)malloc(n*sizeof(int));//to store sorted array
    while(k!=0){
        k=0;
        for(i=l;i<n-1;i++){
            if(r[i]>r[i+1]){temp=r[i];
                            r[i]=r[i+1];
                            r[i+1]=temp;
                           k++;
                           o++;}
        }
        for(j=n-m;j>0;j--){
            if(r[j]<r[j-1]){temp=r[j];
                            r[j]=r[j-1];
                            r[j-1]=temp;
                           k++;
                           o++;}
        }
        printf("bIndex = %d eIndex = %d first elem = %d last elem %d\n",l,n-m,r[l],r[n-m]);
        l++;
        m++;}//the array is now sorted
    printf("numExchanges=%d\n",o);
    for(i=0;i<n;i++){sortedarr[i]=r[i];}
    return sortedarr;
    
}
int main() {
    int n=0;
    int* r;
    int i=0;
    scanf("%d",&n);
    r=(int*)malloc(n*sizeof(int));
    int * sortedarray=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }//input rating array is stored
    sortedarray=bidirectionalbubblesort(r,n);
   for(i=0;i<n;i++){
       printf("%d ",sortedarray[i]);
   }//printing the sortedd array
    return 0;
}
