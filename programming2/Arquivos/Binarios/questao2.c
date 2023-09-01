#include <stdio.h>
#include <stdlib.h>

#define N 50

int main(){

    FILE *file;

    file = fopen("questao2.bin", "rb");
    if (file == NULL){
        printf("Erro na leitura");
        exit(0);
    }
    
    int vet[6] = {0};
    int n;

    while (fread(&n, sizeof(int), 1, file)){
        vet[n]++;
    }
    // while (fscanf(file, "%d", &n) == 1){
    //     vet[n]++;
    // }

    FILE *saida = fopen("saida.bin", "w");
    if (saida == NULL){
        printf("Erro na escrita");
        exit(0);
    }

    int i, j;
    for (i = 1; i < 6; i++){
        printf("%d ",i);
        for (j = 0; j < vet[i] ; j++){
            printf("*");
        }
        printf("\n");
        
    }

    fclose(file);
    fclose(saida);
}