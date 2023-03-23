#include <stdio.h>
#include <string.h>

const int N = 100;

    // j=0;

    // for (i = 0; str1[i] != '\0'; i++){
    //     str2[j++] = str1[i];  
    //     str2[j++] = str1[i];  
    // }

    // str2[j] ='\0';

int main(){
    char str1[N], str2[N];
    int j;
    
    printf("digite a string: \n");
    fgets(str1, N, stdin);

    j=0;

    for (int i = 0; str1[i] != '\0'; i++){
        str2[j++] = str1[i];
        str2[j++] = ' ';
    }
    
    printf("%s\n", str2);
    
}
