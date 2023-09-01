#include <stdio.h>

#define N 1

typedef struct data{
    int dia;
    int mes;
    int ano;
} data ;

typedef struct funcionario{
    int cod;
    char nome[51];
    data nasc;
    float salario;
} funcionario;

void le_funcionario(funcionario func[N]){
    int i;
    for ( i = 0; i < N; i++){
        printf("\nCodigo: ");
        scanf("%d", &func[i].cod);
        getchar();
        printf("\nNome: ");
        gets("%s", func[i].nome);
        printf("\nData de nascimento: ");
        scanf("%d %d %d", &func[i].nasc.dia, &func[i].nasc.mes, &func[i].nasc.ano);
        printf("\nSalario: ");
        scanf("%f", &func[i].salario);
    }
}

void escreve_funcionario(funcionario func[N]){
    int i;
    for ( i = 0; i < N; i++){
        printf("\nCodigo: %d", func[i].cod);
        printf("\nNome: %s", func[i].nome);
        printf("\nData de nascimento: %0d/%0d/%4d", func[i].nasc.dia, func[i].nasc.mes, func[i].nasc.ano);
        printf("\nSalario: %.2f", func[i].salario);
    }
}
funcionario mais_velho(funcionario func[N]){
    funcionario mais_velho = func[0];
    int i;
    for ( i = 1; i < N; i++){
        if (func[i].nasc.ano * 10000 + func[i].nasc.mes * 100 + func[i].nasc.dia > mais_velho.nasc.ano * 10000 + mais_velho.nasc.mes * 100 + mais_velho.nasc.dia ){
            mais_velho = func[i];
        }
    } 
    //     if((func[i].nasc.ano < mais_velho.nasc.ano) ||
    //         (func[i].nasc.ano == mais_velho.nasc.ano && func[i].nasc.mes < mais_velho.nasc.mes) ||
    //         (func[i].nasc.ano == mais_velho.nasc.ano && func[i].nasc.mes == mais_velho.nasc.mes && func[i].nasc.dia < mais_velho.nasc.dia)){
    //     }
    // }
    return mais_velho;
}
int main(){
    funcionario func[N];

    le_funcionario(func);
    escreve_funcionario(func);

    funcionario maisvelho = mais_velho(func);
    printf("\nCodigo: %d", maisvelho.cod);
    printf("\nFuncionario mais velho: %s", maisvelho.nome);
    printf("\nData de nascimento: %0d/%0d/%4d", maisvelho.nasc.dia, maisvelho.nasc.mes, maisvelho.nasc.ano);
    printf("\nSalario: %.2f", maisvelho.salario);
}