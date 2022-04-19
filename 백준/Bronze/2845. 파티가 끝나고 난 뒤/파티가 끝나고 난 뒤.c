#include<stdio.h>

int main() {
    int A, B;
    int arr[5];
    scanf("%d %d", &A, &B);
    for(int i = 0; i < 5; i++) scanf("%d", &arr[i]);
    for(int i = 0; i < 5; i++) printf("%d ", arr[i]-(A*B));
}