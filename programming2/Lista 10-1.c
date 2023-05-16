#include <stdio.h>
#include <stdlib.h>

char * aloca_vet(int n){
    int i;

    char *s = (char *)malloc((n+1) * sizeof(char));
    
    if (s == NULL){
        printf("Erro na alocacao");
        exit(0);
    }

    for ( i = 0; i < n; i++){
        s[i] = 'a';
    }
    s[i] = '\0';

    return s;
    
}

int main(){
    int n = 2, i;
    char *vet = aloca_vet(n);

    printf("%s\n", vet);
    
    free(vet);
}