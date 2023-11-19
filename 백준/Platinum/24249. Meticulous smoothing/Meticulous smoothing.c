#include<stdio.h>

#define ll long long
#define N_MAX 1000000

int arr[N_MAX];

int main() {
    int N;
    ll result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int temp = arr[0] + 1;
    for(int i = 1; i < N; i++, temp++) {
        if(arr[i] <= temp) temp = arr[i];
        else {
            result += arr[i] - temp;
            arr[i] = temp;
        }
    }

    temp = arr[N - 1] + 1;
    for(int i = N - 2; i >= 0; i--, temp++) {
        if(arr[i] <= temp) temp = arr[i];
        else result += arr[i] - temp;
    }

    printf("%lld", result);
}