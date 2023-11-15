#include<stdio.h>

int calculateBottle(int n) {
    return n ? calculateBottle(n - (-n & n)) + 1 : 0;
}

int main() {
    int N, K, temp;
    scanf("%d %d", &N, &K);
    for(temp = N; calculateBottle(temp) > K; temp += -temp & temp);
    printf("%d", temp - N);
}