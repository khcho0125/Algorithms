#include<stdio.h>

#define ll long long

typedef struct Pair {
    ll value;
    int index;
}P;

P Q[5000000];
int front = 0, back = 0;

int N, L;

void QIn(ll value, int index) {
    while(front < back && (Q[back - 1].index <= index - L || Q[back - 1].value > value)) {
        back--;
    }
    Q[back].value = value;
    Q[back++].index = index;
}

void QOut(int index) {
    while(front < back && Q[front].index <= index - L) {
        front++;
    }
}

int main() {
    ll input;
    scanf("%d %d", &N, &L);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &input);
        QOut(i);
        QIn(input, i);
        printf("%lld ", Q[front].value);
    }

}