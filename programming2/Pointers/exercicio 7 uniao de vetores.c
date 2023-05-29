#include <stdio.h>
#include <stdlib.h>

#define N1 5
#define N2 6

void escreve_vet(int *vet, int tamanho_vet){
    int i;
    for (i = 0; i < tamanho_vet; i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int *vet_union(int *vet1, int *vet2, int tamanho_vet1, int tamanho_vet2, int *t){
    int i, j = 0, *vet_auxiliar;
    *t = 0;
    vet_auxiliar == NULL;
    vet_auxiliar = (int *) malloc((tamanho_vet1 + tamanho_vet2) * sizeof(int));
    
    for (i = 0; i < tamanho_vet1; i++){
        vet_auxiliar[i] = vet1[i];
        (*t)++;
    }
    for (i = 0; i < tamanho_vet2; i++){
        vet_auxiliar[(*t)++] = vet2[i];
    }
    return vet_auxiliar;
}


int main(){
    int v1[N1] = {8,3,1,9,4};
    int v2[N2] = {7,3,1,2,6,1};
    int t;
    

    escreve_vet(v1, N1);
    escreve_vet(v2, N2);

    int *vetAux = vet_union(v1, v2, N1, N2, &t);
    
    escreve_vet(vetAux, t);
    free(vetAux);
}