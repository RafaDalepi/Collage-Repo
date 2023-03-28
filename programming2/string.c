#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int N = 100;

void spaces(char str[N], char str2[N]){
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] != ' '){
            str2[j++] = str[i];
            str2[j++] = ' ';
        }
    }
    str2[--j] = '\0';
}

int palindrome(char str[N] ){
    int i, f;
    for( i = 0, f = strlen(str)-1; i < f ; i++, f--){
        if (tolower(str[i]) != tolower(str[f])){
            return 0;
        }
    }
    return 1;
}

int str_to_num(char str[N]){
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++){
        num = num*10 + (str[i] - '0');
    }
    return num;
}    

char num_to_string(int num, char str[N]){
    int i = 0, resto;
    while (num>0){
        resto = num % 10;
        str[i++] = resto + '0';
        num /= 10;
    }
    str[i] = '\0';
    
    int f = i - 1;
    char aux;

    for (i = 0; i < f; i++, f--){
        aux = str[i];
        str[i] = str[f];
        str[f] = aux;
    }
}

int soma_numeros(char str[N]){
    int num = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            num++;
        }
    } 
    return num;
}

// converter pra binários
char converte_binario(int num, char str[N]){
    int i = 0, resto;
    while (num>0){
        resto = num % 2;
        str[i++] = resto + '0';
        num /= 2;
    }
    str[i] = '\0';

    int f = i - 1;
    char aux;
    for (i = 0; i < f; i++, f--){
        aux = str[i];
        str[i] = str[f];
        str[f] = aux;
    }
}

int main(){
    char str[N];
    int num;

    printf("Digite o numero: \n");
    scanf("%d", &num);

    converte_binario(num, str);
    printf("Numero convertido: %s\n", str);

}
