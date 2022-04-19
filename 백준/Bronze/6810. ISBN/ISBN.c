#include<stdio.h>

int main() {
    int N, M = 91;
    for(int i = 0, three = 1; i < 3; i++) {
        scanf("%d", &N);
        M += N * three;
        if(three != 3) {
            three = 3;
        } else {
            three = 1;
        }
    }
    printf("The 1-3-sum is %d", M);
}