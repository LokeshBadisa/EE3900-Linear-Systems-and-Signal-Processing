#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#include "header.h"

#define pi 3.14159

int main(){
int N=14;
double *Yr = (double *)malloc(N*sizeof(double));
double *Yi = (double *)malloc(N*sizeof(double));
double *ynr = (double *)malloc(N*sizeof(double));
double *yni = (double *)malloc(N*sizeof(double));
Yr = readData("ykrealthroughmult.dat",N);
Yi = readData("ykimagthroughmult.dat",N);

for(int k=0;k<N;k++){
    for(int n=0;n<N;n++){
    	ynr[k]+=Yr[n]*cos(2*pi*n*k/N)+Yi[n]*sin(-2*pi*n*k/N);
}
ynr[k]/=N;
printf("%lf ",ynr[k]);
}

createDat("ynreal.dat",N,ynr);

free(ynr);
free(yni);
free(Yi);
free(Yr);
    return 0;
}