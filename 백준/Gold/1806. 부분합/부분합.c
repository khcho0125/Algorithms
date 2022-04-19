#include<stdio.h>

#define INF 987654321
#define min(a, b) ((a < b) ? a : b)

int input[100001] = {0,};

int main() {
    int N, M, result = INF, front = 0, sum = 0;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &input[i]);
        sum += input[i - 1];
        if(sum + input[i] >= M) {
            for(; front < i && sum + input[i] - input[front] >= M; front++) {
                sum -= input[front];
            }
            result = min(i - front + 1, result);
        }
    }
    if(result == INF) {
        printf("0");
    }
    else {
        printf("%d", result);
    }
}