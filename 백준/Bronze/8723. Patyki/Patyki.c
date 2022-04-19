#include<stdio.h>

int main() {
    int arr[3], temp;
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
    if(arr[0] == arr[1] && arr[0] == arr[2]) {
        printf("2");
        return 0;
    }
    for(int i = 1; i < 3; i++) {
        if(arr[i - 1] > arr[i]) {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
    }
    if(arr[2] * arr[2] == arr[0] * arr[0] +arr[1] * arr[1]) {
        printf("1");
    } else {
        printf("0");
    }
}