#include <stdio.h>
#include <stdlib.h>

typedef struct estado{
            char nome[31];
            int numveic;
            int numacid;
} ESTADO;

ESTADO estadoMaiorNumAcidentes(char nomeArquivo[80]){
    ESTADO aux, maisAcidentes = {"",0,0};
    
    FILE *file = fopen(nomeArquivo, "rb");
    if(file == NULL){
        printf("Erro na leitura");
        exit(0);
    }

    while (fread(&aux, sizeof(ESTADO), 1, file)){
        if (aux.numacid > maisAcidentes.numacid){
            maisAcidentes = aux;
        }        
    }
    fclose(file);
    return maisAcidentes;    
}

int main(){
    ESTADO maisAcidentes = estadoMaiorNumAcidentes("questao3.bin");
    printf("%s %d\n", maisAcidentes.nome, maisAcidentes.numacid);
}