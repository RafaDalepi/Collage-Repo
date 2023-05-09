#include <stdio.h>
#define N 4

typedef struct candidatos
{
    char nome[50];
    int score;
} candidatos;

void le_candidatos(candidatos vetor[N]){
    int i;
    for(i = 0; i < N; i++){
        printf("candidato: ");
        gets(vetor[i].nome);

        printf("Score: ");
        scanf("%d", &vetor[i].score);
        getchar();
    }
}

void escreve_candidatos(candidatos vetor[N]){
    int i;
    printf("\n"); 
    for(i = 0; i < N; i++){
        printf("candidato: %s\n", vetor[i].nome);
        printf("Score: %d\n", vetor[i].score);
    }
}

void maiores_pontuadores(candidatos vetor[N], candidatos *candidato1, candidatos *candidato2){
    candidato1->score = 0;
    candidato2->score = 0;
    int i;
    for(i = 0; i < N; i++){
        if (vetor[i].score > candidato1->score){
            *candidato2 = *candidato1;
            *candidato1 = vetor[i];
        }else if ( vetor[i].score > candidato2->score){
            *candidato2 = vetor[i];
        }
        
    }
    
}    

int main(){
    candidatos vetor[N], candidato1, candidato2;
    le_candidatos(vetor);
    escreve_candidatos(vetor);

    maiores_pontuadores(vetor, &candidato1, &candidato2);

    printf("\nPrimeiro: %s Score: %d \n", candidato1.nome, candidato1.score);
    printf("Segundo: %s Score: %d \n", candidato2.nome, candidato2.score);
}