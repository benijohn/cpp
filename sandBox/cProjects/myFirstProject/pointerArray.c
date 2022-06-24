#include<stdio.h>

int A[] = {2,4,5,8,1};
int i;
int *p = A;

int main () {
    for(int i = 0; i<5; i++) {
        printf("address = %d\n", &A[i]);
        printf("address = %d\n", A+i);
        printf("address = %d\n", p);
        printf("value = %d\n", A[i]);
        printf("value = %d\n", *(A+i));
        printf("address = %d\n", *p);
        p++;
    }
}