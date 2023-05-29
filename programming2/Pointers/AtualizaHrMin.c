#include<stdio.h>
#include<stdlib.h>

void calc_horario(int h1, int m1, int *h2, int *m2, int qtdeMin){
	h1 *= 60;
	m1 += h1 + qtdeMin;
	*h2 = (m1/60) % 24;
	*m2 = m1 % 60;
}

int main(){
	int h1 = 23, m1 = 0, h2, m2, qtdeMin;
	qtdeMin = 60;

	calc_horario(h1, m1, &h2, &m2, qtdeMin);

	printf("%d : %d", h2, m2);
}
