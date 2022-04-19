#include<stdio.h>

int main() {
    double arr[100];
    double N, sum = 0, temp = 0;
    scanf("%lf", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
        temp += arr[i] / N;
    }
    if(N != 0) {
        printf("%.2lf", (sum / N) / temp);
    } else {
        printf("divide by zero");
    }
}