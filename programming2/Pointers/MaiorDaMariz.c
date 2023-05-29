#include <stdio.h>
#include <stdlib.h>


#define N 5

void geraMat(int matriz[N][N]){
    int i;
    for(i = 0; i < N; i++){
        int j = 0;
        for ( j = 0; j < N; j++){
            matriz[i][j] = rand() % 100;
        }
    } 
}

void escreveMat(int matriz[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
           printf("%4d", matriz[i][j]); 
        }
        printf("\n");
    }
}

void maiorVal(int matriz[N][N], int *maior, int *linha, int *coluna){
    int i,j;
    *linha = 0;
    *coluna = 0;
    *maior = matriz[0][0];
    for ( i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (matriz[i][j] > *maior){
                *maior = matriz[i][j];
                *linha = i;
                *coluna = j;
            }                   
        }
    }    
}

int main(){
    int matriz[N][N], linha, coluna, maior;

    geraMat(matriz);
    escreveMat(matriz);
    maiorVal(matriz, &maior, &linha, &coluna);
    printf("Maior: %d Linha: %d Coluna: %d", maior, linha, coluna);
}