#include<stdio.h>

#define INF 987654321
#define max(a, b) (a > b ? a : b)

int arr[100000];

int main() {
    int N, temp = -1, answer = -INF;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if (temp < 0) temp = 0;
        temp += arr[i];
        answer = max(temp, answer);
    }

    printf("%d", answer);
}