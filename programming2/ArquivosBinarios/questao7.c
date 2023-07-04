#include <stdio.h>
#include <stdlib.h>
struct data {
     int dia;
     int mes;
     int ano;
};
typedef struct data DATA;

struct funcionario {
     int codigo;
     char nome[50];
     DATA nascimento;
     float valor_hora;
};
typedef struct funcionario FUNCIONARIO;

void escreve_arquivo(char arquivo[50]){
    printf("\n---------------------------------\n");
    FILE *f = fopen(arquivo, "rb");
    if (f == NULL){
        printf("erro");
        exit(0);
    }
    FUNCIONARIO aux;
    while(fread(&aux, sizeof(FUNCIONARIO), 1, f)){
        printf("cod: %d , nome: %s, salario: %.2f\n", aux.codigo,aux.nome,aux.valor_hora);
    }
    fclose(f);
    printf("\n---------------------------------\n");
}

void altera_arquivo(char arquivo[50], int cod, float valor_hora){
    FILE *f = fopen(arquivo, "rb+");
    if (f == NULL){
        printf("erro");
        exit(0);
    }

    FUNCIONARIO aux;
    while (fread(&aux, sizeof(FUNCIONARIO), 1, f)){
        if (aux.codigo == cod){
            printf("%s %.2f", aux.nome, aux.valor_hora);
            aux.valor_hora = valor_hora;
            fseek(f, -sizeof(FUNCIONARIO), SEEK_CUR);
            fwrite(&aux, sizeof(FUNCIONARIO), 1, f);
            break;
        }
    }
    fclose(f);
} 

int main(){
    char arquivo[50] = "questao7.bin";
    escreve_arquivo(arquivo);
    altera_arquivo(arquivo, 65, 15.00);
    escreve_arquivo(arquivo);
}