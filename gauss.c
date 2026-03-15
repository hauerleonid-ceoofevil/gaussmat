#include <stdio.h>
#include <stdlib.h>

double* gauss(double**arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i][i]==0){
            int found=0;
            for(int k=i+1;k<n;k++){
                if(arr[k][i]){
                    double *tmp=arr[i];
                    arr[i]=arr[k];
                    arr[k]=tmp;
                    found=1;
                }
            }
        }
    }
}