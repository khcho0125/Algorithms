#include<stdio.h>

int main() {
    int arr[10] = {0,};
    int N, T;
    scanf("%d", &T);
    for(int i = 0; i < 5; i++) {
        scanf("%d", &N);
        arr[N]++;
    }
    printf("%d", arr[T]);
}