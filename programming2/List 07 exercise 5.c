#include <stdio.h>
#include <string.h>

#define N 8

typedef struct cliente{
    char nome[51];
    float fat;  
}cliente;

void le_clientes(cliente c[N]){
    for(int i = 0; i < N; i++){
        printf("\nNome: ");
        scanf("%s", c[i].nome);
        printf("\nFaturamento: ");
        scanf("%f", &c[i].fat);
        getchar();
    }
}

void escreve_clientes(cliente c[N]){
    for(int i = 0; i < N; i++){
        printf("\nNome: %s\nFaturamento: %.2f", c[i].nome,c[i].fat);
    }
}

void ordena_clientes(cliente c[N]){
    cliente aux;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            if(c[i].fat < c[j].fat){
                aux = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
        }
    }
}

float soma_faturamento(cliente c[N]){
    float soma = 0;
    for(int i = 0; i < N; i++){
        soma += c[i].fat;
    }
    return soma;
}
int total_de_clientes(float total, cliente c[N]){
    int nclientes;
    float soma ;
    while (soma < total/2)
    {
        soma += c[nclientes].fat;
        nclientes++;
    }
    return nclientes;
}

void resumo_clientes(float total, int nclientes, cliente c[N]){
    int i;
    printf("\nTotal de faturamento: %.2f", total);
    printf("\nTotal de clientes: %d", nclientes);
    for (i= 0; i < nclientes; i++){
        printf("%s %.2f", c[i].nome, c[i].fat);
    }
    
}

int main(){
    cliente c[N];

    le_clientes(c);
    ordena_clientes(c);
    escreve_clientes(c);
    int total = soma_faturamento(c);
    int nclientes = total_de_clientes(total, c);
    resumo_clientes(total, nclientes, c);
}



