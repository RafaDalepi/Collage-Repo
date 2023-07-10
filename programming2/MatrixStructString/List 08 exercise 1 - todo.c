#include <stdio.h>
#define N 500

typedef struct camiseta{
    char Tamanho[1];
    char NomePessoa[50];
    char CorCamisa[50];
} TipoCamiseta;

void LeCamisetas(TipoCamiseta Quantidade[N], int NumQtde){
    for(int i = 0; i < NumQtde ; i++){
        printf("Tamanho: ");
        scanf("%s", Quantidade[i].Tamanho);
        getchar();

        printf("Nome: ");
        gets(Quantidade[i].NomePessoa);
        
        printf("Cor: ");
        scanf("%s", Quantidade[i].CorCamisa);
        getchar();
    }
}

void EscreveCamisas(int qtde, TipoCamiseta camisetas[N]){
    for (int i = 0; i < qtde; i++){
        printf("%s", camisetas[i].CorCamisa);
        printf("%s", camisetas[i].Tamanho);
        printf("%s", camisetas[i].NomePessoa);
    }
}
void ordenaParam(int qtde, TipoCamiseta camisetas[N]){
    TipoCamiseta ordenacao[N];

    for (int i = 0; i < qtde; i++){
        if (camisetas[i].NomePessoa < camisetas[i+1].NomePessoa && camisetas[i].Tamanho < camisetas[i+1].Tamanho && camisetas[i].CorCamisa < camisetas[i+1].CorCamisa){
            ordenacao[i] = camisetas[i];
            ordenacao[i+1] = camisetas[i+1];
        }   
    } 
}
int main(){
    TipoCamiseta camisetas[N];
    int qtde = 0;
    
    printf("Quantidade de Camisas: ");
    scanf("%d", &qtde);
    getchar();

    LeCamisetas(camisetas, qtde);
    EscreveCamisas(qtde, camisetas);

    
}   
