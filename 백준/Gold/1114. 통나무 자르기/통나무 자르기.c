#include<stdio.h>
#include<stdlib.h>

#define max(a, b) (a > b ? a : b)

int cutPoint[10000];
int answer;

int compare(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if(num1 > num2) return 1;

    if(num1 < num2) return -1;

    return 0;
}

int cutting(int L, int K, int C, int len) {
    int temp = L, cnt = L;
    for(int i = K; i >= 0; i--) {
        if(temp - cutPoint[i] > len) return 0;

        if(cnt - cutPoint[i] > len) {
            cnt = cutPoint[i + 1];
            if(--C < 0) return 0;
        }

        temp = cutPoint[i];
    }

    if(temp > len || (!C && cnt > len)) return 0;

    return (C ? cutPoint[0] : cnt);
}

void solve(int L, int K, int C) {
    int s = 1, e = L, mid, ret;
    while(s < e) {
        mid = (s + e) / 2;
        ret = cutting(L, K, C, mid);

        if(!ret) {
            s = mid + 1;
        }
        else {
            e = mid;
        }
    }

    answer = e;
}

int main() {

    int L, K, C;
    scanf("%d %d %d", &L, &K, &C);
    for(int i = 0; i < K; i++) {
        scanf("%d", &cutPoint[i]);
    }
    qsort(cutPoint, K, sizeof(int), compare);
    int temp = 0;
    for(int i = 1; i < K; i++) {
        if(cutPoint[i] != cutPoint[i - 1]) cutPoint[++temp] = cutPoint[i];
    }

    solve(L, temp, C);

    printf("%d %d", answer, cutting(L, temp, C, answer));
}