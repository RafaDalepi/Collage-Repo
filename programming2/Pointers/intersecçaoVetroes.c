#include <stdio.h>
#include <stdlib.h>

#define N1 5
#define N2 6

void escreve(int *v, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int * interseccao(int *v1, int *v2, int n1, int n2, int *t){
    int i, j, k=0;
    int *v3 = NULL;
    *t = 0;
    for(i = 0; i < N1; i++){
        for (j = 0; j < N2; j++){
        if (v1[i] == v2[i]){
                (*t)++;
                break;
            }
        } 
    } 
    v3 = (int *) malloc((*t) * sizeof(int));
    if (v3 == NULL){
        printf("Erro na alocação de memória\n");
        exit(1);
    }    
    for(i = 0; i < N2; i++){
        for(j = 0; j < N2; j++){
            if (v1[i] == v2[i]){
                v3[k] = v1[i];
                k++;
            }
        }
    }
    return v3;
}

int main(){
    int v1[N1] = {8,3,1,9,4};
    int v2[N2] = {7,3,1,2,6,1};
    int t;

    escreve(v1, N1);
    escreve(v2, N2);

    int *v3 = interseccao(v1, v2, N1, N2, &t);
    
    escreve(v3, t);
    free(v3);
}