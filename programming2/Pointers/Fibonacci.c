#include <stdio.h>
#include <stdlib.h>

int * fibonacci(int n){
    int f0 = 0, f1 = 1, fn;
    int i;

    int *f = (int *)malloc(n * sizeof(int));
    if (f==NULL)
    {
        printf("Erro ao Alocar");
        exit(0);
    }

    for (i = 0; i < n; i++){
        f[i] = f0;
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }

    return f;

}
void escreve(int *v, int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){
    int * fib = fibonacci(10), i;
    escreve(fib, 10);   
}