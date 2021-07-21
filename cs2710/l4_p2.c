#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int minoftwo(long long int a,long long int b){
    if(a-b<=0){return a;}
    else{return b;}
}/*function defined to calculate the minmum element among two elements*/
long long int minofthree(long long int a,long long int b,long long int c){
    if(a-b<=0 && a-c<=0){ return a;}
    if(b-a<0 && b-c<=0){return b;}
    else{return c;}
}/*function defined to calculate the minmum element among three elements*/
    
long long int * merge(long long int a[100000],long long int b[100000],long long int c[100000],int i,int j,int k){
   
    long long int * d;
    d =  (long long int *)malloc((i+j+k)*sizeof(long long int));
    int l=0;
    int m=0;
    int n=0;
    int o=0;
   for(o=2;o<i+j+k+2;o++){o=o-2;
        if(l<i && m<j && n<k){d[o]=minofthree(a[l],b[m],c[n]);
                                   if(minofthree(a[l],b[m],c[n])==a[l]){l++;}
                                   else if(minofthree(a[l],b[m],c[n])==b[m]){m++;}
                                   else{n++;}
                             }/*done until one array reaches its end*/
        
                            
        o++;
     
           if(l==i && m!=j && n!=k){d[o]=minoftwo(b[m],c[n]);
                                    if(d[o]==b[m]){m++;}
                                    else{n++;}}
                                    
            if(l!=i && m==j && n!=k){d[o]=minoftwo(a[l],c[n]);
                                    if(d[o]==a[l]){l++;}
                                    else{n++;}}
                                     
             if(l!=i && m!=j && n==k){d[o]=minoftwo(b[m],a[l]);
                                    if(d[o]==b[m]){m++;}
                                    else{l++;}}/*done until two arrays reach their end*/
       o++;
        
     
        
      
         if(l==i && m==j && n!=k){d[o]=c[n];
                                    n++;}
         if(l==i && m!=j && n==k){d[o]=b[m];
                                    m++;}
         if (l!=i && m==j && n==k){d[o]=a[l];
                l++;}
         
   }
    return d;

}/*function defined to return sorted merged array of three input arrays */

int main() {
    long long int siiitm[100000];
    long long int siiitb[100000];
    long long int siiitd[100000];
    char c;
    int i=0;
    int j=0;
    int k=0;
    c='a';
    while (c!='\n'){
        scanf("%lld%c",&siiitm[i],&c);
        i++;
    }
    c='a';
    while (c!='\n'){
        scanf("%lld%c",&siiitb[j],&c);
        j++;
    }
    c='a';
    while (c!='\n'){
        scanf("%lld%c",&siiitd[k],&c);
        k++;
    }/*storing the three input arrays*/
    long long int* mergedsi=merge(siiitm,siiitb,siiitd,i,j,k);
    for(int e=0;e<i+j+k;e++){
        printf("%lld ",mergedsi[e]);
    }/*printing the sorted merged array*/
   return 0;
    
}

/*as per the code number of comparisions depends on the input.
number of comparisions = size of three lists*(7+k)
where k is a positive number.
let the size of three lists be L.
then T = Theta(L) */