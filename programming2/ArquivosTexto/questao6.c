#include <stdio.h>
#include <stdlib.h>

typedef struct Paises{
    char Nome[20];
    float Ouro;
    float Prata;
    float Bronze;
} PAISES;

void TrataArquivo(char Arquivo[50]){

    FILE *file = fopen("questao6.txt", "r");
    if (file == NULL){
        printf("erro na leitura do arquivo");
        exit(0);
    }
    int QtdePaises = 0, i = 0, j, AuxPaises[QtdePaises];

    fscanf(file, "%d", &QtdePaises);
    PAISES Paises[QtdePaises];

    while(fscanf(file, "%s %f %f %f", Paises[i].Nome, &Paises[i].Ouro, &Paises[i].Prata, &Paises[i].Bronze) == 4) {
        for (j = 0; j < QtdePaises; j++){
            AuxPaises[j] = 0;
        }
            
        printf("Pais:%s - ", Paises[i].Nome);
        printf("Ouro:%f - ", Paises[i].Ouro);
        printf("Prata:%f - ", Paises[i].Prata);
        printf("Bronze:%f\n", Paises[i].Bronze);
    }
}


int main(){
    char NomeArquivo[50] = "questao6.txt";

    TrataArquivo(NomeArquivo);
    
}