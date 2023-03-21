#include <stdio.h>

int total_dias(int mes, int ano){
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    } else if (mes == 2 && ano%4==0){
        return 29;   
    } else {
        return 28;
    }
}

void gera_calendario(int calendario[6][7], int ds, int total){
    int i, j, dia = 1;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 7; j++){
            if (i == 0 && j < ds){
                calendario[i][j] = 0;
            } else if (dia <= total){
                calendario[i][j] = dia;
                dia++;
            } else {
                calendario[i][j] = 0;
            }
        }
    }
    for(i = 0; i < 6; i++){
        for(j = 0; j < 7; j++){
            printf("%2d ", calendario[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int ds, m, a, total, calendario[6][7];
    printf("Digite o dia da semana: ");
    scanf("%d", &ds);
    printf("Digite o mes e o ano: ");
    scanf("%d %d", &m, &a);
    total = total_dias(m, a);
    gera_calendario(calendario, ds, total);
}
