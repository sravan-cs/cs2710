#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ** transpose(int mat[100][100],int m,int n){
    int ** a;
      a = (int **)malloc(100*sizeof(int *));
    for (int i = 0; i < 100; ++i)
    {
        a[i] =  (int *)malloc(100*sizeof(int));
    }
    int k=0;
    int l=0;
    for(k=0;k<m;k++){for(l=0;l<n;l++){
        a[l][k]=mat[k][l];
    }}
    return a;    
}/*function is defined to find transpose*/

int symm(int mat[100][100],int** trans,int m,int n ){
    int k=0;
    if(m!=n){printf("Matrix is not symmetric\n");}
    else{
    for(int i=0;i<m;i++){for(int j=0;j<m;j++){
        if(mat[i][j]==trans[i][j]){k++;}}}
    if(k==m*m){printf("Matrix is symmetric\n");}
    else{printf("Matrix is not symmetric\n");}
    }
    return 0;
}/*function is defined to check if the matrix is symmetric*/

int ortho(int mat[100][100],int m,int n){
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            int sum=0;
            for(k=0;k<m;k++){
                sum=sum+mat[k][i]*mat[k][j];
            }
            if (sum!=0){l++;}
        }
    }
        if(l==0){printf("Matrix is orthogonal\n");}
        else{printf("Matrix is not orthogonal\n");}
        return 0;
}/*function is defined to check if the function is ortho*/

    


int main() {
    int m;
    int n;
    scanf("%d%d",&m,&n);
    int mat[100][100];
    int i=0;
    int j=0;
    for(i=0;i<m;i++){for(j=0;j<n;j++){
        scanf("%d",&mat[i][j]);
    }}/*the input matrix is stored in mat*/
    int ** trans=transpose(mat,m,n);
    for(i=0;i<n;i++){for(j=0;j<m;j++){
        printf("%d ",trans[i][j]);
}
        printf("\n");
}/*transpose matrix is printed*/
    symm(mat,trans,m,n);
    ortho(mat,m,m);/*functions are called*/
    return 0;}

