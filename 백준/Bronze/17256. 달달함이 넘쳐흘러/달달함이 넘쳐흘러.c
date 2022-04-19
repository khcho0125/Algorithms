#include<stdio.h>
int main() {
    int arr[2][3];
    for(int i = 0; i < 2; i++) {
        scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
    }
    printf("%d %d %d", arr[1][0] - arr[0][2], arr[1][1] / arr[0][1], arr[1][2] - arr[0][0]);
}