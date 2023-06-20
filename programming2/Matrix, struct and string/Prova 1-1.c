// QUESTÃO 1) (3,5 PONTOS) Uma imagem preto e branco pode ser armazenada em uma matriz
// binarizada (cada elemento pode ser 0 ou 1), conforme pode ser visto abaixo. Pode-se compactar essa
// matriz armazenando nas posições pares de um vetor a quantidade de zeros consecutivos e nas posições
// ímpares a quantidade de uns consecutivos (veja que cada linha da matriz, para efeito de compactação é
// concatenada com a seguinte). Faça uma função na linguagem de programação C que preencha um vetor
// que represente uma matriz binarizada de N linhas por M colunas. Considerar que N e M já estão definidos
// no programa pela cláusula #define. A função deverá colocar na posição 0 (zero) do vetor o número de
// linhas, na posição 1 (um) o número de colunas da matriz, na posição 2 (dois) a quantidade de zeros
// consecutivos a partir do primeiro elemento da matriz, na posição 3 (três) do vetor a quantidade de uns
// consecutivos subsequentes aos primeiros zeros, e assim sucessivamente até representar todos os
// elementos da matriz no vetor.
// Protótipo: void compactaMatBin(char mat[N][M],int vet[])
// Imagem binarizada:
// 0 0 0 0 0 0 0
// 0 1 1 0 1 1 0
// 0 1 1 0 1 1 0
// 0 0 0 0 0 0 0
// 0 1 1 1 1 1 0
// 0 0 0 0 0 0 0
// Imagem compactada:
// 6 7 8 2 1 2 2 2 1 2 9 5 8

#include <stdio.h>
#include <stdlib.h>
void escreveVet(int vet[6+7]){
    int i;
    for(i = 0; i < 6+7; i++){
       printf("%d ", vet[i]);
    }
}
void compactaMatrizBin(int mat[6][7], int vet[6+7]){
    int i, j, k = 1; 
    vet[0] = 6;
    vet[1] = 2;
    k++;

    for (i = 0; i < 6; i++){
        for (j = 0; j < 7; j++){
            if(!mat[i][j]){
                vet[k]++;
            }
            if(mat[i][j] == 1){
                vet[k]++;
            }       
        }
    }   // 6 7 8 2 1 2 2 2 1 2 9 5 8
}    

int main(){
    int mat[6][7] ={{0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 1, 0, 1, 1, 0},
                    {0, 1, 1, 0, 1, 1, 0},
                    {0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 1, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0, 0, 0}};
    int vet[6+7] = {0};

    compactaMatrizBin(mat, vet);

    escreveVet(vet);

}