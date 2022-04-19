#include<stdio.h>

int main() {
    int N, sum = 0;
    for(int i = 0; i < 4; i++) {
        scanf("%d", &N);
        sum+=N;
    }
    printf("%d\n", sum / 60);
    printf("%d", sum % 60);
}