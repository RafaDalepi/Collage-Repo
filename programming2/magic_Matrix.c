#include <stdio.h>

#define N 5

int diagPrinci(int Mat[N][N]){
    int SumPrim = 0, sumSec = 0,coluna = 0, linha = 0;
    for(int i = 0, j = N-1; i < N; i++, j--){
        SumPrim += Mat[i][i];
        sumSec += Mat[i][j];
    }
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            coluna += Mat[i][j];
            linha += Mat[j][i];
        }
    }
    if (SumPrim == sumSec == (coluna / N) ){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int matriz[N][N] = {{11, 24, 7, 20, 3},
                        {4, 12, 25, 8, 16},
                        {17, 15, 13, 21, 9},
                        {10, 18, 1, 14, 22},
                        {23, 6, 19, 2, 15}};
    if(!diagPrinci(matriz)){
        printf("Nao e matriz magica\n");
    }else{
        printf("E matriz magica\n");
    }
}
