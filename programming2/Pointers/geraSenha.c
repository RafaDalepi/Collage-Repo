#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char * gera_senha(int n){
    int i, op;
    
    srand(time(NULL));

    char *s = (char *)malloc((n+1) * sizeof(char));
    if (s==NULL)
    {
        printf("Erro ao Alocar");
        exit(0);
    }
    for (i = 0; i < n; i++){
        op = rand()%3;

        switch (op){
        case 0: s[i] = rand()%26 + 'a';
            break;
        case 1: s[i] = rand()%26 + 'A';
            break;
        case 2: s[i] = rand()%10 + '0';
            break;
        }
    }
    s[i] = '\0';

    return s;
}

int main(){
    char * senha = gera_senha(20);

    printf("%s\n", senha);

    free(senha);
}
