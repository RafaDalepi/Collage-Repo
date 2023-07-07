#include <stdio.h>

#define LINHAS 6
#define COLUNAS 7

int CompactaMatriz(int matriz[LINHAS][COLUNAS], int vetor[LINHAS + COLUNAS]){
    int i, j, count = 2, lastPos = matriz[0][0];

    vetor[0] = LINHAS;
    vetor[1] = COLUNAS;

    for (i = 0; i < LINHAS; i++){
        for (j = 0; j < COLUNAS; j++){
            if(!matriz[i][j] && matriz[i][j] != lastPos){
                count++;
                vetor[count]++;
                lastPos = matriz[i][j];
            }else if(!matriz[i][j]){
                vetor[count]++;
                lastPos = matriz[i][j];
            }else if(matriz[i][j] && matriz[i][j] != lastPos){
                count++; 
                vetor[count]++;
                lastPos = matriz[i][j];
            }else if(matriz[i][j]){
                vetor[count]++;
                lastPos = matriz[i][j];
            } 
        }        
    }
    for (i = 0; i < LINHAS + COLUNAS; i++){
        printf("%d ", vetor[i]);
    }
    
}

int main(){
    int matriz[LINHAS][COLUNAS] = {{0,0,0,0,0,0,0},
                                   {0,1,1,0,1,1,0},
                                   {0,1,1,0,1,1,0},
                                   {0,0,0,0,0,0,0},
                                   {0,1,1,1,1,1,0},
                                   {0,0,0,0,0,0,0}};
    int vetor[LINHAS + COLUNAS] = {0};

    CompactaMatriz(matriz, vetor);
    
}