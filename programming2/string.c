#include <stdio.h>

#define N 100

//exercicio n°3


int main(){
    char str[N] = "oi";
    char str2[N];
    int i, j;
    
    printf("digite a string: \n");
    gets(str);

    j=0;

    for (i = 0; i != '\0'; i++){
        str2[j++] = str[i];  
        str2[j++] = str[i];  
    }

    str2[j] ='\0';

    printf("%s\n", str2);
        

}