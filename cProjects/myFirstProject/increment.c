#include<stdio.h>

void Increment(int *p) {
    *p = *p+1;
}

int main() {
    int a;
    a = 10;
    printf("a = %d", a);
    Increment(&a);
    printf("a is now = %d\n", a);
}