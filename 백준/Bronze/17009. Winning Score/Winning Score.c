#include<stdio.h>

int main() {

    int input, A = 0, B = 0;
    for(int i = 3; i > 0; i--) {
        scanf("%d", &input);
        A += input * i;
    }
    for(int i = 3; i > 0; i--) {
        scanf("%d", &input);
        B += input * i;
    }
    if(A > B) {
        printf("A");
    } else if(B > A) {
        printf("B");
    } else {
        printf("T");
    }
}
