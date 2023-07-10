#include <stdio.h>

// Faça uma função na linguagem de programação C que receba um vetor de tamanho N (o valor N é
// definido pela diretiva #define) e uma estrutura do tipo DATA com a data atual. A função deverá retornar um
// inteiro com o número de associados menores de idade

#define N 2

typedef struct data {
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct associado {
    int codigo;
    char nome[50];
    DATA nascimento;
} ASSOCIADO;


//11 04 2022
//5 07 2006

int MenorDeIdade(ASSOCIADO socio[N], DATA atual){
    int i, menores = 0, diaM, mesM, diaA, mesA; 
    
    for (i = 0; i < N; i++){
        diaM = socio[i].nascimento.dia / 365;
        mesM = socio[i].nascimento.mes / 12;
        diaA = atual.dia / 365;
        mesA = atual.mes /12;

        if(atual.ano < socio[i].nascimento.ano + 18){
            menores++;
        }else if(atual.mes > socio[i].nascimento.mes && atual.ano < socio[i].nascimento.ano + 18){
            menores++;
        }else if(atual.dia > socio[i].nascimento.dia && atual.mes > socio[i].nascimento.mes && atual.ano < socio[i].nascimento.ano + 18){
            menores++;                   
        }
    }    
    return menores;
}

int main(){

    ASSOCIADO socio[N];
    int i, deMenor;

    for(i = 0; i < N; i++){
        printf("Codigo do Assoc.: ");
        scanf("%d", &socio[i].codigo);
        gets();

        printf("Nome do Assoc.: ");
        scanf("%s", &socio[i].nome);
        gets();

        printf("Data de nasc.:");
        scanf("%d %d %d", &socio[i].nascimento.dia, &socio[i].nascimento.mes, &socio[i].nascimento.ano );
        gets();
    }
   
    DATA dataAtual;

    dataAtual.dia = 5;
    dataAtual.mes = 7;
    dataAtual.ano = 2023;

    deMenor = MenorDeIdade(socio, dataAtual); 

    printf("Socios Menores de Idade: %d\n", deMenor);
}