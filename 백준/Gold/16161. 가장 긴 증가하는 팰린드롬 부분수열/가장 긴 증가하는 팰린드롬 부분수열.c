#include<stdio.h>
#include<stdbool.h>

#define N_MAX 100000
#define max(a, b) ((a) > (b) ? a : b)

int arr[N_MAX];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int result = 0, j;
    for(int i = 0; i < N; i++) {
        for(j = 1; i + j < N && i - j >= 0 && arr[i - j] < arr[i - j + 1] && arr[i + j - 1] > arr[i + j] && arr[i - j] == arr[i + j]; j++);
        result = max(result, j * 2 - 1);
        
        if(i + 1 < N && arr[i] == arr[i + 1]) {
            for(j = 1; i + j + 1 < N && i - j >= 0 && arr[i - j] < arr[i - j + 1] && arr[i + j] > arr[i + j + 1] && arr[i - j] == arr[i + j + 1]; j++);
            result = max(result, j * 2);
        }
    }

    printf("%d", result);
}