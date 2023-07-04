#include <stdio.h>
#include <stdlib.h>

int main(){
    char entrada[50] = "questao7.txt";
    char saida[50] = "saida1.txt";

    FILE *f = fopen(entrada, "r");
    if (f == NULL){
        exit(0);
    }

    int i, cod, np;
    float sum, n, media; 
    FILE *s = fopen(saida, "w");
    if (s == NULL){
        exit(0);
    }

    while(fscanf(f, "%d %d", &cod, &np) == 2 ){
        sum = 0;
        for (i = 0; i < np; i++){
            fscanf(f, "%f", &n);
            sum += n;
        }   
        media = sum / np;

        fprintf(s, "%5d %4d %5.1f\n",cod, np, media);
    }
    fclose(f);
    fclose(s);
}