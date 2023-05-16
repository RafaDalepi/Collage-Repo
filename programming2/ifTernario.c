#include <stdio.h>

int main(){
    int a = 5;
    int b = 3;
    int c = 0;

    c = (a > b) ? a : b;

    printf("c = %d\n", c);
}    