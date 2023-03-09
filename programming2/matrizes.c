#include <stdio.h>

const int maxRows = 3, maxColumns = 3;

void lematriz(int matriz[maxRows][maxColumns]){
    for(int i = 0; i < maxRows; i++){
        for(int j = 0; j < maxColumns; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void escrevematriz(int matriz[maxRows][maxColumns]){
    for(int i = 0; i < maxRows; i++){
        for(int j = 0; j < maxColumns; j++){
            printf("% 5d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matriz[maxRows][maxColumns];
    lematriz(matriz);
    escrevematriz(matriz);
    
    int somaprincipal = 0, somasecundaria = 0, row = 0, column = 0, totRows = maxRows, totcolumns = maxColumns; 

    while(row < maxRows && column < maxColumns){
        somaprincipal += matriz[row][column];
        row++;
        column++;
    }

    for (int i = 0; i < maxRows; i++){
        for (int j = 0; j < maxColumns; j++){
            if (matriz[i][j] == matriz[totRows][totcolumns]){
                somaprincipal += matriz[i][j];
            }
        }
    }
    
    // printf("Soma da diagonal principal: %d\n", somaprincipal);
    printf("Soma da diagonal secundaria: %d\n", somasecundaria);
}
