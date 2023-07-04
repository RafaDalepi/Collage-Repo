#include <stdio.h>
#include <stdlib.h>

typedef struct alunos
{
    char Nome[50];
    float Nota1;
    float Nota2;
    float Nota3;
} ALUNOS;

void leArquivo(char NomeArquivo[20]){

    FILE *file  = fopen(NomeArquivo, "rb");
    if (file == NULL){
        printf("Error opening the file");
        return(0);
    }

    ALUNOS aluno[50];

    while(fread(&aluno, sizeof(ALUNOS), 1, file)){
    }
    

}   

int main(){
    char NomeArquivo[20] = "questao5.bin";

    leArquivo(NomeArquivo);

}