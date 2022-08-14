#include<stdio.h>
#include<stdlib.h>

#define ll long long
#define MOD 1000000007LL

ll memu[300000];
ll bit[300000] = {1,};
ll memori[300000];

int compare(const void* a, const void* b) {
    ll num1 = *(ll*)a;
    ll num2 = *(ll*)b;

    return num1 > num2;
}

void init(int N) {
    for(int i = 1; i < N; i++) {
        bit[i] = (bit[i - 1] << 1) % MOD;
    }
}

int main() {
    int N;
    ll result = 0;
    scanf("%d", &N);
    init(N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &memu[i]);
    }
    qsort(memu, N, sizeof(ll), compare);
    for(int i = 0; i < N; i++) {
        memori[i] = ((memu[N - i - 1] - memu[i]) % MOD * bit[i] % MOD + memori[i - 1] * 2 % MOD + MOD) % MOD;
        result = (result + memori[i]) % MOD;
    }
    printf("%lld", result);
}