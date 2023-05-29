#include <stdio.h>
#include <stdlib.h>

char *UltimoNome(char *str){
    int i, u, t, k;
    for (i = 0; i != '\0'; i++){
        while(str[i] == ' '){
            u = i;
        }        
    }
    t = i-u;
    char *s = (char *) malloc((t) * sizeof(char));
    if (s==NULL){
        printf("Erro na alocacao");
        exit(0);
    }
    for (i = u+1, k=0; str[i] != '\0' ; i++){
        s[k] = str[i];
    }
    s[k] = '\0';
    return s;
} 

int main(){
    char nome[100];
    int i;
    for (i = 0; i < 5; i++){
        printf("Digite o nome:");
        gets(nome);

        char *s = UltimoNome(nome);
        printf("%s\n", s);
        free(s);
    }
}