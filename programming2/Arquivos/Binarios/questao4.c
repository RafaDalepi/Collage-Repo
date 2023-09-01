// to run this archive in linux compilers: gcc -o questao4 questao4.c -lm
// the math.h library doesn't run in the linux compiler with native 
// configurations so add the -lm in the end of the compiling sentece to compile

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct ponto {
  float x;
  float y;
} PONTO;

PONTO mais_distante_ponto_medio (char nomearquivo[50]){
    FILE *file = fopen(nomearquivo, "rb");
    if (file == NULL){
        printf("Erro na leitura");
        exit(0);
    }

    PONTO Pontos[50];

    float num, DistanciaEntrePontos;
    int count = 0, i;

    while(fread(&num, sizeof(float), 1, file)){
        Pontos[count].x = num;
        if(fread(&num, sizeof(float), 1, file))
            Pontos[count].y = num;
        count++;
    }

    float CentroMedio[2] = {0};

    for (i = 0; i < count; i++){
        CentroMedio[0] += Pontos[i].x;
        CentroMedio[1] += Pontos[i].y;
    }

    CentroMedio[0] /= count;
    CentroMedio[1] /= count;
    
    int PontosMaisDistantes;
    float aux;

    for (i = 0; i < count; i++){
        if(sqrt(pow(Pontos[i].x - CentroMedio[0], 2) + pow(Pontos[i].y - CentroMedio[1], 2)) > aux){
            aux = sqrt(pow(Pontos[i].x - CentroMedio[0], 2) + pow(Pontos[i].y - CentroMedio[1], 2));
            PontosMaisDistantes = i;
        }
    }
    
    printf("%f %f\n", Pontos[PontosMaisDistantes].x, Pontos[PontosMaisDistantes].y);

    fclose(file);
}


int main(){
    char arquivo[50] = "questao4.bin";
    char saida[50] = "saida.txt";

    mais_distante_ponto_medio(arquivo);
}