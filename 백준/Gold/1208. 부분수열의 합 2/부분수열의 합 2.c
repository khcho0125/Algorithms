#include<stdio.h>

#define hash 2000000

int number[40] = {0,};
long long result = 0;
int Hash[4000001] = {0,};
int t = 0;

void Ldfs(int idx, int sum, int Lim) {
    if(idx == Lim) {
        Hash[hash + sum]++;
        return;
    }
    Ldfs(idx + 1, sum + number[idx], Lim);
    Ldfs(idx + 1, sum, Lim);
}

void Rdfs(int idx, int sum, int Lim, int S) {
    if(idx == Lim) {
        if(S - sum <= hash && S - sum >= -hash) {
            result += Hash[hash + S - sum];
        }
        return;
    }
    Rdfs(idx + 1, sum + number[idx], Lim, S);
    Rdfs(idx + 1, sum, Lim, S);
}

int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    for(int i = 0; i < N; i++) {
        scanf("%d", &number[i]);
    }
    Ldfs(0, 0, N / 2);
    Rdfs(N / 2, 0, N, S);
    if(S == 0) result--;
    printf("%lld", result);
}