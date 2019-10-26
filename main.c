#include <stdio.h>
#include <stdlib.h>

//  ======== INITILALIZATION OPERATIONS ========

int veczeros(int *name, int length){
    name = (int *)malloc(length* sizeof(int));
    int i;
    for (i  = 0;  i<length ; i++) {
        name[i] =0;
        printf("%d", name[i]);
    }

    return 0;
}
int matzeros(int **name, int x, int y){

    return 0;
}
int vecread(char *filename){
    return 0;
}
int matread(char *filename){
    return 0;
}
//  ================================================


//  ======== CONCATENATIONS ========
//  ================================================


//  ======== PADDINGS ========
//  ================================================


//  ======== SLICINGS ========
//  ================================================


int main(){
    char *m1 = "inputs/m1.mat";
    char *m2 = "inputs/m2.mat";
    char *m3 = "inputs/m3.mat";
    char *m4 = "inputs/m4.mat";
    char *m5 = "inputs/m5.mat";
    char *v1 = "inputs/v1.vec";
    char *v2 = "inputs/v2.vec";
    char *v3 = "inputs/v3.vec";
    char *v4 = "inputs/v4.vec";
    char *v5 = "inputs/v5.vec";

    int vector;
    veczeros(vector, 10);



}