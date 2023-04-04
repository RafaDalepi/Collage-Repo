#include <stdio.h>

typedef struct horario{
    int hora;
    int minuto;
    int segundo;
}HORARIO;

const int N = 1;

typedef struct datas{
    int ano;
    int mes;
    int dia;
}DATAS;

HORARIO calculaSegSeguinte(HORARIO atual){
    HORARIO seg;
    int total = atual.hora*3600 + atual.minuto*60 + atual.segundo + 1;

    seg.hora = (total / 3600) % 24;
    total = total % 3600;
    seg.minuto = total / 60;
    seg.segundo = total % 60;

    return seg;
}

DATAS calculaproximoDia(DATAS atual){
    DATAS sec;
    if (atual.dia == 31 && atual.mes == 12){
        sec.dia = 1;
        sec.mes = 1;
        sec.ano = atual.ano + 1;
    }else if (atual.dia == 31 && (atual.mes == 1 || atual.mes == 3 || atual.mes == 5 || atual.mes == 7 || atual.mes == 8 || atual.mes == 10)){
        sec.dia = 1;
        sec.mes = atual.mes + 1;
        sec.ano = atual.ano;
    }else if (atual.dia == 30 && (atual.mes == 4 || atual.mes == 6 || atual.mes == 9 || atual.mes == 11)){
        sec.dia = 1;
        sec.mes = atual.mes + 1;
        sec.ano = atual.ano;
    }else if(atual.dia == 29 && atual.mes == 2 && atual.ano % 4 == 0){
        sec.dia = 1;
        sec.mes = 3;
        sec.ano = atual.ano;
    }else if(atual.dia == 28 && atual.mes == 2 && atual.ano % 4 != 0){
        sec.dia = 1;
        sec.mes = 3;
        sec.ano = atual.ano;
    }else{
        sec.dia = atual.dia + 1;
        sec.mes = atual.mes;
        sec.ano = atual.ano;
    }
    
        
    return sec;
}

int main(){
    DATAS atual, seg;
    for (int i = 0; i < N; i++){
    printf("digite o dia atual: \n");
    scanf("%d %d %d", &atual.dia, &atual.mes, &atual.ano);

    seg = calculaproximoDia(atual);
    printf("O dia seguinte é: %d/%d/%d\n", seg.dia, seg.mes, seg.ano);
    }
}
