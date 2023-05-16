#include <stdio.h>

#define N 6
#define M 7

void compacta(int matriz[N][M], int vetor[N + M]){
    vetor[0] = N;
    vetor[1] = M;

    int i,j, k = 2;
    for (i=0; i< N; i++){
        for (j=0; j<M; j++){
            if (matriz[i][j] == 0){
                vetor[k] += 1;
            }else{
                vetor[++k] += 1;
            }
        }
    }
}

int compactaMatBin(char mat[N][M], int vet[]){
    int valor, cont, i, j, k;

    k = 0;
    vet[k++] = N;
    vet[k++] = M;

    cont = 0;
    valor = 0;

    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            if ( valor == mat[i][j]){
                cont++;
            } 
            else{
                vet[k++] = cont;
                cont = 1;
                valor = ! valor;
            }
        }
    } 
    vet[k++] = cont;

    return k;
}

int main(){
    int matriz[N][M] = {{0,0,0,0,0,0,0},
                        {0,1,1,0,1,1,0},    
                        {0,1,1,0,1,1,0},
                        {0,0,0,0,0,0,0},
                        {0,1,1,1,1,1,0},
                        {0,0,0,0,0,0,0}    
                        };
    int vetor[13];
    compacta(matriz, vetor);
    for (int i = 0; i < N+M; i++){
        printf(" %d ", vetor[i]);
    }
}