#include<stdio.h>
#include<string.h>

int isEven(int);

int main() {
    char C0[] = "Hello world of string Arrays!\n";
    char *C2 = "Unchangeable/unmodifiable string literal stored elsewhere in memory";
    char* C1;
    C1 = C0;

    int n = strlen(C0);

    printf("lenght of C0 = %d\n", n);
    for(int i=0; i<n; i++) {
        if(isEven(i)) {
            //printf("%c", C1[i]);
            printf("%c", C1[0]);
            C1++;
        }
        else {
            printf("%c", C0[i]);
            C1++;
        }

    }
    C1 = C0;
    while(*C1 != '\0') {
        printf("%c", *C1);
        C1++;
    }
    printf("%s", C2);
    printf("%c", '\n');
}

int isEven(int num) {
    return !(num & 1);
}
