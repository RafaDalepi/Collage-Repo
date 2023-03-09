#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 5;

void escreveMatriz(int matriz[MAX][MAX]){
    printf("\n");
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            printf("% 2d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int setaMatriz(int matriz[MAX][MAX]){
    srand(time(NULL));
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            matriz[i][j] = rand() % 10;
        }
    }
    return matriz[MAX][MAX];
}

int main(){
    int matriz[MAX][MAX], somaMatrizPrim = 0, somaMatrizSec = 0, somaValoresCima = 0, somaValoresBaixo = 0; 

    setaMatriz(matriz);
   
    for(int i = 0; i < MAX; i++){
        somaMatrizPrim += matriz[i][i];
    }
    
    for(int i = 0, j = MAX-1; i < MAX; i++, j--){
        somaMatrizSec +=  matriz[i][j];
    }
    
    for (int a = 1; a < MAX; a++){
        for(int i=0, j=a;i<MAX && j<MAX; i++, j++){ 
            somaValoresCima += matriz[i][j];
        } 
    }
    
    for (int a = 0; a < MAX; a++){
        for(int i=0, j=a;i>0 && j>0; i--, j--){
            somaValoresBaixo += matriz[i][j];
        } 
    }
    
    escreveMatriz(matriz);

    printf("\nSoma princ: %d", somaMatrizPrim);    
    printf("\nSoma sec: %d", somaMatrizSec);    
    printf("\nSoma dos valores de cima: %d", somaValoresCima);
    printf("\nSoma dos valores de Baixo: %d\n", somaValoresBaixo);
}


// a00 a01 a02 a03 a04
// a10 a11 a12 a13 a14
// a20 a21 a22 a23 a24
// a30 a31 a32 a33 a34
// a40 a41 a42 a43 a44