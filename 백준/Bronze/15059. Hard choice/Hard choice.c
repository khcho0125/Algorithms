#include<stdio.h>

int main() {
    int arr[3], arr2[3], result = 0;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < 3; i++) {
        scanf("%d", &arr2[i]);
        if(arr2[i] > arr[i]) {
            result += arr2[i] - arr[i];
        }
    }
    printf("%d", result);
}