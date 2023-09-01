#include <stdio.h>
#include <stdlib.h>

void le_arquivo(){

}

int main(){
    char entrada[50] = "questao1.txt", nome[50];
    char saida[50] = "saida1.txt";

    FILE *f = fopen(entrada, "r");

    if (f==NULL){
        printf("Erro");
        exit(0);
    }

    float n1, n2, n3, m;
    int a=0, r=0;

    while (fgets(nome, 50, f)){
        nome[strlen(nome) -1] = '\0';
        fscanf(f, "%f %f %f\n", &n1, &n2, &n3);
        m = (n1+n2+n3) /3;
        if (m>=5){
            a++;
        }else{
            r++;
        }
    }   
    FILE *s = fopen(saida, "w");
    if (s == NULL){
        printf("Erro");
        exit(0);
    }
    
    fprintf(s, "Aprovados: %d\n", a);
    fprintf(s, "Reprovados: %d\n", r);


    fclose(f);
    fclose(s);
}