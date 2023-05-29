#include <stdio.h>
#include <stdlib.h>

#define N 10

int * criaVetor(int n){
    int i, *v = NULL;

    v = (int *)malloc(n*sizeof(int));
    if (v == NULL){
        printf("Erro na Alocacao\n");
        exit(0);
    }

    for (i = 0; i < n; i++){
        v[i] = 0;
    }
    return v;
}

int main(){
    int *v = criaVetor(10), i, n;

    for (i = 0; i < n; i++){
        printf("%d\n", *(v+i));
    }
    
    free(v);
}
