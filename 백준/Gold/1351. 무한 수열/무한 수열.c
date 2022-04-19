#include<stdio.h>

#define ll long long
#define MAX 5000000

ll memorizes[MAX] = { 1LL,};
ll Q, P;


ll func(ll N) {

    if(N >= MAX) {
        return func(N / Q) + func(N / P);
    }

    if(memorizes[N]) {
        return memorizes[N];
    }

    memorizes[N] = func(N / Q) + func(N / P);
    return memorizes[N];
} 

int main() {
    ll N;
    scanf("%lld %lld %lld", &N, &P, &Q);
    printf("%lld", func(N));
}