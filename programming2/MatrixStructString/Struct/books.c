#include <stdio.h>

#define N 6

typedef struct data{
    int d, m, a;
} data;

typedef struct books{
    char Nome[50];
    char Autor[50];
    data edicao;
}books;

void le_livros(books livrovet[N]){
    int i;
    for (i = 0; i < N; i++){
        printf("\nNome do Livro: ");
        gets(livrovet[i].Nome);
        
        printf("\nNome do Autor: ");
        gets(livrovet[i].Autor);
        
        printf("\nData de lançamento: ");
        scanf("%d %d %d", &livrovet[i].edicao.d, &livrovet[i].edicao.m, &livrovet[i].edicao.a);
        getchar();
    }
}

void escreveLivros(books livro){
    printf("\nNome do Livro: %s", livro.Nome);        
    printf("\nNome do Autor: %s", livro.Autor);
    printf("\nData de lançamento: %d/%d/%d", livro.edicao.d, livro.edicao.m, livro.edicao.a);
}

books livro_antigo(books livro[N]){
    books antigo = livro[0];
    int i;
    for(i = 0; i < N; i++){
        if (livro[i].edicao.a < antigo.edicao.a){
            antigo = livro[i];
        }else if (livro[i].edicao.a == antigo.edicao.a && antigo.edicao.m < livro[i].edicao.m){
            antigo = livro[i];
        }else if (livro[i].edicao.a == antigo.edicao.a && antigo.edicao.m == livro[i].edicao.m && antigo.edicao.d < livro[i].edicao.d){
            antigo = livro[i];
        }
    }
}

books livro_novo(books livro[N]){
    books novo = livro[0];
    int i;
    for(i = 0; i < N; i++){
        if (livro[i].edicao.a > novo.edicao.a){
            novo = livro[i];
        }else if (livro[i].edicao.a == novo.edicao.a && novo.edicao.m > livro[i].edicao.m){
            novo = livro[i];
        }else if (livro[i].edicao.a == novo.edicao.a && novo.edicao.m == livro[i].edicao.m && novo.edicao.d > livro[i].edicao.d){
            novo = livro[i];
        }
    }
}

int main(){
    books livrovet[N];
    le_livros(livrovet);

    books antigo = livro_antigo(livrovet);
    books novos = livro_novo(livrovet);

    printf("\n\nLivro mais antigo:");
    escreveLivros(antigo);
    printf("\n\nLivro mais Novo:");
    escreveLivros(novos);
}