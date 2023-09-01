#include <stdio.h>
#include <stdlib.h>

#define N 50


int main(){
    FILE *file = NULL;
    file = fopen("questao1.bin", "rb");

    if (file == NULL){
        printf("Erro na leitura");
        exit(0);
    }
    
    float n, sum = 0, avg = 0;
    int r, count = 0;

    while(fread(&n, sizeof(float), 1, file)){
        printf("N %f\n", n);
        sum += n;
        count++;
    }
    avg = sum/count;

    printf("Sum: %f Avg: %f\n", sum, avg);

    rewind(file);
    sum = 0;


    FILE *saida = fopen("saida", "w");
    if (saida == NULL){
        printf("Erro ao abrir arquivo");
        exit(0);
    }
    
    while (fread(&n, sizeof(float), 1, file)){
        if (n >= avg){
            fprintf(saida, "%f\n", n);        
        }
    }

    fclose(saida);
    fclose(file);
}