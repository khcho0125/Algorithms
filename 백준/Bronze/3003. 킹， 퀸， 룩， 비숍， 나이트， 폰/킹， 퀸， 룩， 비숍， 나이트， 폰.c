#include<stdio.h>

int main() {
    int arr[7] = { 1, 1, 2, 2, 2, 8 };
    int N;
    for(int i = 0; i < 6; i++) {
        scanf("%d", &N);
        arr[i] -= N;
    }
    for(int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);

    }
}