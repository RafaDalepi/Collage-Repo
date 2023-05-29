#include<stdio.h>

void change( int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;

}

int main(){
	int a = 5;
	int b = 3;
	change(&a, &b);
	printf("a = %d, b = %d\n", a, b);
}
