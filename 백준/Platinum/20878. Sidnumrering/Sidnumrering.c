#include<stdio.h>

#define ll long long

ll counter[10];
int odd[5] = {1, 3, 5, 7, 9};

void printCounter() {
    for(int i = 0; i < 10; i++) printf("%lld ", counter[i]);
}

void page(ll N, ll p) {
    ll head = N / (p * 10);
    ll self = N % (p * 10) / p;

    for(int i = 1; i < self; i++) counter[i] += p / 10 * 5;
    for(ll i = 1; i <= head; i *= 10) counter[head % (i * 10) / i] += p / 10 * 5 * self;

    counter[0] += p / 10 * 5 * (head - !self);
    for(int i = 1; i <= 9; i++) counter[i] += p / 10 * 5 * head;
}

void solution(ll N) {
    ll firstPage = (N % 10 + 1) / 2;
    for(int i = 0; i < firstPage; i++) counter[odd[i]]++;
    for(ll i = 10; i <= N; i *= 10) counter[N % (i * 10) / i] += firstPage;
    for(ll i = 0; i < 5; i++) counter[odd[i]] += N / 10;

    for(ll p = 10; p <= N; p *= 10) {
        page(N, p);
    }

    printCounter();
}

int main() {
    ll N;
    scanf("%lld", &N);
    solution(N);
}