#include <stdio.h>
#include <stdlib.h>
#define N 3
#define P 3


struct piloto{
    char nome[50];
    char equipe[50];
    int pontuacao[P];
};
typedef struct piloto PILOTO;

void calcularPontuacao(PILOTO v[N], PILOTO*  primeiro, PILOTO* segundo) {
    *primeiro = v[0];
    *segundo = v[0];

    for (int i = 1; i < N; i++) {
        int totalPontos = 0;
        for (int j = 0; j < P; j++) {
            totalPontos += v[i].pontuacao[j];
        }

        int primeiroPontos = 0;
        int segundoPontos = 0;
        for (int j = 0; j < P; j++) {
            primeiroPontos += primeiro->pontuacao[j];
            segundoPontos += segundo->pontuacao[j];
        }

        if (totalPontos > primeiroPontos) {
            *segundo = *primeiro;
            *primeiro = v[i];
        } else if (totalPontos > segundoPontos) {
            *segundo = v[i];
        }
    }
}

int main() {
    PILOTO v[5];
    
    printf("Inserindo dados dos pilotos:\n");
    for (int i = 0; i < N; i++) {
        printf("Piloto %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", v[i].nome);
        printf("Equipe: ");
        scanf("%s", v[i].equipe);
        printf("Pontuação das 3 corridas: ");
        for (int j = 0; j < P; j++) {
            scanf("%d", &v[i].pontuacao[j]);
        }
    }

    PILOTO primeiroLugar;
    PILOTO segundoLugar;

    calcularPontuacao(v, &primeiroLugar, &segundoLugar);

    printf("Primeiro lugar: %s (%s)\n", primeiroLugar.nome, primeiroLugar.equipe);
    printf("Segundo lugar: %s (%s)\n", segundoLugar.nome, segundoLugar.equipe);

    return 0;
}