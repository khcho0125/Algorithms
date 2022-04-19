#include<stdio.h>

int main() {
    int arr[4] = {0,};
    int N, M;
    scanf("%d", &N);
    for(int i = 0; i < 5; i++) {
        scanf("%d", &M);
        arr[M - 1]++;
    }
    printf("%d", arr[N - 1]);
}