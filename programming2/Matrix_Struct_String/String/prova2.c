#include <stdio.h>

int ValorValido(char senha){
    if(senha >= '0' && senha <= '9'){
        return 1;
    }else if(senha >= 'A' && senha <= 'Z'){
        return 1;
    }else return 0;
}

int main(){
    char senha[32];
    int i, PontosDeSenha = 0;

    printf("Digite a Senha:");
    scanf("%s", &senha);

    for (i = 0; senha[i] != '\0'; i++){
        PontosDeSenha += ValorValido(senha[i]);
    }

    if (i >= 6 && i <= 32 && PontosDeSenha >= 2){
        printf("Senha Valida\n");
    }else printf("Senha Invalida\n");

}