#include <stdio.h>

#define N 100

void separaString(char string[N], char string2[N]){
    int k = 0, i, j, n;
    for(i = 0; string[i] != '\0';){
        if (string[i] != '#'){
            string2[k++] == string[i++];
        }else{
            n = string[i+1] - '0';
            for(j = 0; j < n; j++){
                string2[k++] = ' ';
            }
            i += 2;
        }
    }
    string2[k] = '\0';
}

int main(){
    char string[N] = "Isto#4e#5uma#6pequena#1frase." , string2[N];

    separaString(string, string2);

    printf("%s\n", string2);
}