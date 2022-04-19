#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define INF 3000000001
#define min(a, b) ((a < b) ? a : b)
#define abs(a) ((a < 0) ? (a) * -1 : a)


ll arr[5000] = {0,};
ll result[3] = {0,};
ll temp = INF;

int compare(const void* a, const void* b) {
    ll num1 = *(ll*)a;
    ll num2 = *(ll*)b;
    
    if(num1 > num2) {
        return 1;
    }

    if(num1 < num2) {
        return -1;
    }
    return 0;
}

int logN(ll value, int N) {
    int min = 1, mid, max = N;
    while(min <= max) {
        mid = (min + max) / 2;
        if(arr[mid - 1] < value) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    return min - 1;
}

int main() {
    int N, K;
    ll V, idx, sum, test;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, N, sizeof(ll), compare);
    for(int T = 0; T < N; T++) {
        for(int i = 0; i < N; i++) {
            if(i == T) continue;

            V = logN((arr[i] + arr[T]) * -1, N);

            if(V == N || (V != 0 && abs(arr[i] + arr[T] + arr[V - 1]) < abs(arr[i] + arr[T] + arr[V]))) V--;

            for(K = 0, sum = INF; K < 3 && sum == INF; K++) {

                if(K + V < N && K + V != i && K + V != T) {
                    sum = min(sum, abs(arr[i] + arr[T] + arr[V + K]));
                    V = V + K;
                }
                if(K != 0 && V - K >= 0 && V - K != i && V - K != T) {
                    sum = min(sum, abs(arr[i] + arr[T] + arr[V - K]));
                    V = V - K;
                }
            }
            if(temp > sum) {
                temp = sum;
                result[0] = arr[T];
                result[1] = arr[i];
                result[2] = arr[V];
            }
        }
    }
    for(int i = 1; i < 3; i++) {
        idx = i;
        temp = result[i];
        while((idx != 0) && temp < result[idx - 1]) {
            result[idx] = result[idx - 1];
            idx--;
        }
        result[idx] = temp;
    }
    printf("%lld %lld %lld", result[0], result[1], result[2]);
}