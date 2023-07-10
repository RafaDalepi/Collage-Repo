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
    int i, j, aux[N][N], lastPos =0;

    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if (matriz[i][j] > matriz[j][j+1]){
                aux[i][j] = matriz[i][j+1];
                aux[i][j+1] = matriz[i][j];
            }else{
                aux[i][j] = matriz[i][j];
            }                        
        }
    }
    
    PrintMatriz(matriz);
    printf("\n");    
    PrintMatriz(aux);    
}

int main(){
    int matriz[N][N] = {{6,1,9,1,5},
                        {9,15,32,95,84},
                        {91,125,342,955,864},
                        {9312,1315,332,952,8412},
                        {13129,13125,32,95,84}};
    OrdenaMatriz(matriz);                 
}