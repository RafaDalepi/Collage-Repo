#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media(char arquivo[50], char cadastro[50]){
    FILE *f = fopen(arquivo, "r");
    if (f == NULL){
        printf("erro");
        exit(0);
    }
    
    char mat[50];
    float n1, n2, n3, m = -1;

    while(fscanf(f,"%s %f %f %f",mat,n1,n2,n3) == 4){
        printf("%s\n", mat);
        if (strcasecmp(cadastro, mat) == 0){
            m = (n1 + n2 + n3) /3;
            break;
        }
    }
    
    fclose(f);
    return m;        
}

int main(){
    char arquivo[50] = "questao2.txt";
    char cadastro[50] = "8820324-3";

    float m = media(arquivo, cadastro);
    printf("Media: %.2f\n", m);
}
