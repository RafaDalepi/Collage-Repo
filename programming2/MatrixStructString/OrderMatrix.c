#include <stdio.h>

#define N 5  

void PrintMatriz(int matriz[N][N]){
    int i, j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", matriz[i][j]);
        }        
        printf("\n");
    }   
}

void OrdenaMatriz(int matriz[N][N]){
    int i, j, aux[N][N], lastPos = matriz[0][0];

    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            
        }
    }
    
    PrintMatriz(matriz);
    printf("\n");    
    PrintMatriz(aux);    
}

int main(){
    int matriz[N][N] = {{6,1,9,1,5},
                        {9,15,32,95,84},
                        {10,5,8,12,6},
                        {8,6,2,3,1},
                        {25,6,32,95,84}};
    OrdenaMatriz(matriz);                 
}