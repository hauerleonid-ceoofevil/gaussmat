#include <stdio.h>
#include <stdlib.h>

double gauss(double**arr,int n){
    double det=1.0;
    int sign=1;
    double**tmp=(double**)malloc(n*sizeof(double*));
    for(int i=0;i<n;i++){
        tmp[i]=(double*)malloc(n*sizeof(double));
        for(int j=0; j<n;j++){
            tmp[i][j]=arr[i][j];
        }
    }
    for(int i=0; i<n;i++){
        if(tmp[i][i]==0){
            int found=0;
            for(int k=i+1;k<n;k++){
                if(tmp[k][i]!=0){
                    double *tmp1=tmp[i];
                    tmp[i]=tmp[k];
                    tmp[k]=tmp1;
                    found=1;
                    sign=-sign;
                }
            }
            if(!found){
                for(int i=0;i<n;i++){
                    free(tmp[i]);
                }
                free(tmp);
                return 0.0;
            }
        }
        det*=tmp[i][i];
        for(int k=i+1;k<n;k++){
            double tmp2= tmp[k][i]/tmp[i][i];
            for(int j=i;j<n;j++){
                tmp[k][j]=tmp[k][j]-tmp2*tmp[i][j];
            }
        }
    }
    det*=sign;
    for(int i=0;i<n;i++){
        free(tmp[i]);
    }
    free(tmp);
    return det;
}
int main(){
    int n;
    scanf("%d",&n);
    double**arr=(double**)malloc(n*sizeof(double*));
    for (int i=0;i<n;i++){
        arr[i]=(double*)malloc(n*sizeof(double));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lf",&arr[i][j]);
        }
    }
    double det=gauss(arr,n);
    printf("%lf",det);
    for(int i=0;i<n;i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}