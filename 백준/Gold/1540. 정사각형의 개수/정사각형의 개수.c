#include<stdio.h>

#define ll long long
#define min(a, b) (a < b ? a : b)

ll plus(ll i) {
    if(i == 1) {
        return 0;
    }
    return i * ((i - 1) / 2LL) + (i / 2LL) * ((i - 1) % 2LL);
}

int main() {
    ll count = 0, i, one, two, N;
    scanf("%lld", &N);
    for(i = 1; (i + 1) * (i + 1) <= N; i++) {
        count += i * i;
    }
    ll num = (N - (i * i));
    while(num > 0) {
        count += plus(min(num, i));
        num -= i;
    }
    printf("%lld", count);
}