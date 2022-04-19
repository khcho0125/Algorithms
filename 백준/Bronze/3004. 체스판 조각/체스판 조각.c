#include<stdio.h>

int main() {
    int N, result = 1, num = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        if(i % 2) {
            result += num;
        } else {
            result += num++;
        }
    }
    printf("%d", result);

}