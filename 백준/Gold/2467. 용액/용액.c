#include<stdio.h>

#define INF 2000000001
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)
#define abs(a) ((a < 0) ? (a) * -1 : a)


int arr[100000] = {0,};
int result[2] = {0,};
int temp = INF;

int logN(int value, int N) {
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
    int N, V;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < N; i++) {
        V = logN(arr[i] * -1, N);
        if(V == N || (V != 0 && abs(arr[i] + arr[V - 1]) < abs(arr[i] + arr[V]))) V--;
        if(V == i) {
            if(V != 0 && V + 1 != N) {
                V = abs(arr[i] + arr[V - 1]) < abs(arr[i] + arr[V + 1]) ? V - 1 : V + 1;
            }
            else if(V != 0) {
                V = V - 1;
            }
            else {
                V = V + 1;
            }
        }
        if(temp > abs(arr[i] + arr[V])) {
            result[0] = min(arr[i], arr[V]);
            result[1] = max(arr[i], arr[V]);
            temp = abs(arr[i] + arr[V]);
        }
    }
    printf("%d %d", result[0], result[1]);
}