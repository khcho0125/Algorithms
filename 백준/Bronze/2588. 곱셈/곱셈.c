#include<stdio.h>

int main() {
    int arr[3], sum = 0;;
    int A, ten = 1;
    scanf("%d", &A);
    for(int i = 0; i < 3; i++) {
        scanf("%1d", &arr[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("%d\n", arr[2 - i] * A);
        sum += arr[2 - i] * A * ten;
        ten *= 10;
    }
    printf("%d", sum);
}