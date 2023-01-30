#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>


const int qtdeQuest = 10;

int main(){
    char RespC, respostas[qtdeQuest], gabarito[qtdeQuest], repete; 
    //gabarito

    for(int quest = 0; quest < qtdeQuest; quest++){

        printf("Questao %d da prova: ", quest + 1);
        scanf(" %c", &RespC);

        gabarito[quest] = RespC;
    }

    do{
        int acertos = 0;
    //respostas
        for(int quest = 0; quest < qtdeQuest; quest++){

            printf("Resposta da questao %d: ", quest + 1);
            scanf(" %c", &RespC);

            respostas[quest] = RespC;

            if(respostas[quest] == gabarito[quest]){
                acertos++;
            }
        }

        printf("\nAcertou: %d", acertos);
        
        printf("\nDeseja corrigir mais um(s/n)?: ");
        scanf(" %c", &repete);

    } while (repete == 's');
}

