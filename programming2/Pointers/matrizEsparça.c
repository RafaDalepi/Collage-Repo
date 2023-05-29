#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct {
    int v;
    int c;
    int l;
} NaoNulos;

NaoNulos *cria_vetor(int mat[N][N], int *t){
    int c=0, i, j, k = 0;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (mat[i][j] != 0){
                c++;
            }
        }
    }
    NaoNulos *v = (NaoNulos *)malloc(c * sizeof(NaoNulos));
    if (v == NULL){
        printf("Erro na alocação");
        exit(0);
    } 
    for (i = 0; i < N; i++){
        for(i = 0; i < N; i++){
            if (mat[i][j] != 0){
                v[k].v = mat[i][j];
                v[k].l = i;
                v[k].c = j;
                k++;
            }
        }
    }     
    *t = c;
    return v;
}

void escreve(NaoNulos *v, int n){
    int i;
    for (i = 0; i < N; i++){
        printf("%d %d %d \n", v[i].v, v[i].l, v[i].c);

    }
    
}

int main(){
    int mat[N][N] = {{0,0,0,4,0},
                     {0,0,0,0,0},
                     {3,0,0,0,0},
                     {0,0,2,0,0},
                     {0,0,0,0,1}};
    int t;
    NaoNulos *v = cria_vetor(mat, &t);
    escreve(v, t);
    free(v);
}