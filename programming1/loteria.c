#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

const int qtdeNum = 5;

int main(){
   int  numero, cartela[qtdeNum], numeroConf, certo[qtdeNum], acertos = 0, erros = 0;

   for(int aposta = 0; aposta < qtdeNum; aposta++){

      printf("Aposta %d: ", aposta + 1);
      scanf("%d", &numero);

      cartela[aposta] = numero;
   }

   for(int numConf = 0; numConf < qtdeNum; numConf++){

      printf("Numero Conferido %d: ", numConf + 1);
      scanf("%d", &numeroConf);

      certo[numConf] = numeroConf;
   }

   for(int numConf = 0; numConf < qtdeNum; numConf++){
      for(int aposta = 0; aposta < qtdeNum; aposta++){
         if(certo[aposta] == cartela[numConf]){
            acertos++;
         }else{
            erros++;
         }
      }
   }

   printf("Voce acertou: %d\n", acertos);
}
