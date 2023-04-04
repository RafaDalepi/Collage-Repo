#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

typedef struct pessoa{
    char nome[50];
    int idade;
    char sexo;    
}PESSOA;

int main(){
    PESSOA p1, p2;

    printf("Digite seu nome: ");
    fgets(p1.nome, 50, stdin);
    printf("Digite sua idade: ");
    scanf("%d", &p1.idade);
    __fpurge(stdin);
    printf("Digite seu sexo: ");
    scanf("%c", &p1.sexo);

    p2 = p1;

    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Sexo: %c\n", p1.sexo);
}