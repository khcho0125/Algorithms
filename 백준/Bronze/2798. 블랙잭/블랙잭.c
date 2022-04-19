#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M, i, j, k, temp = 0;
    scanf("%d %d", &N, &M);
    int* arr = (int*)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < N - 2; i++) {
        for(j = i + 1; j < N - 1; j++) {
            for(k = j + 1; k < N; k++) {
                if(arr[i] + arr[j] + arr[k] <= M && arr[i] + arr[j] + arr[k] > temp) {
                    temp = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }
    printf("%d", temp);
}