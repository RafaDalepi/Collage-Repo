#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 5;

void escreve_matriz(int mat[MAX][MAX]){
    printf(" ---------------\n");
    for(int i = 0; i < MAX; i++){
        printf("|");
        for(int j = 0; j < MAX; j++){
            printf("% 2d ", mat[i][j]);
        }
        printf("|\n");
    }
    printf(" ---------------\n");
}

int seta_matriz(int mat[MAX][MAX]){
    srand(time(NULL));
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            mat[i][j] = rand() % 10;
        }
    }
    return mat[MAX][MAX];
}

int soma_diagonal_primaria(int mat[MAX][MAX]){
    int soma_Matriz_Prim = 0; 
    for(int i = 0; i < MAX; i++){
        soma_Matriz_Prim += mat[i][i];
    }
    return(soma_Matriz_Prim);
}

int soma_diagonal_secundaria(int mat[MAX][MAX]){
    int soma_Matriz_Sec = 0;
    for(int i = 0, j = MAX-1; i < MAX; i++, j--){
        soma_Matriz_Sec +=  mat[i][j];
    }
    return(soma_Matriz_Sec);
}

int soma_acima_diagonal(int mat[MAX][MAX]){
    int soma_Val_Cima = 0;
    for (int a = 1; a < MAX; a++){
        for(int i=0, j=a;i<MAX && j<MAX; i++, j++){ 
            soma_Val_Cima += mat[i][j];
        } 
    }
    return(soma_Val_Cima);
}

void troca_linhas(int mat[MAX][MAX], int l1, int l2){
    int aux, j;
    for(j = 0; j < MAX; j++){
        aux = mat [l1][j];
        mat[l1][j] = mat[l2][j]; 
        mat[l2][j] = aux; 
    }
} 

int soma_transposta(int mat[MAX][MAX]){
    int aux, i , j;
}
int indentidade(int mat[MAX][MAX]){
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            if (i==j && mat[i][j] != 1){
                return 0;
            }else if(i!=j && mat[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

void escreve_vetor(int vet[MAX]){
    for (int i = 0; i < MAX; i++){
        printf("%d ",vet[i]);
    }
}

void soma_linhaEcoluna(int mat[MAX][MAX], int linha[MAX], int coluna[MAX]){
    for (int i = 0; i < MAX; i++){
        linha[i] = coluna[i] = 0;
        for (int j = 0; j < MAX; j++){
            linha[i] += mat[i][j];
            coluna[i] += mat[j][i];    
        }
    }
}

//calcular transposta de uma mat(parte de baixo)
//fazer m800
void soma_linha(int mat[MAX][MAX], int linha[MAX]){
    for (int i = 0; i < MAX; i++){
        linha[i] = 0;
        for (int j = 0; j < MAX; j++){
            linha[i] += mat[i][j];
        }
        printf("%d\n", linha[i]);
    }
}

//fazer m1200
void soma_coluna(int mat[MAX][MAX], int coluna[MAX]){
    int aux, aux2[MAX],num, soma_mat;

    for (int j = 0; j < MAX; j++){
        coluna[j] =  0; 
        for (int i = 0; i < MAX; i++){
            coluna[j] += mat[i][j];
        } 

        num = coluna[j] % 10;
        aux = coluna[j] / 10;
        coluna[j] = num + aux;

        escreve_vetor(coluna);
        printf("\n");
    }
}

int main(){
    int mat[MAX][MAX], linha [MAX], coluna[MAX];

    seta_matriz(mat);
    
    escreve_matriz(mat);
    
    soma_coluna(mat, coluna);
}

// 1 1 1
// 1 1 1 
// 1 1 1 
