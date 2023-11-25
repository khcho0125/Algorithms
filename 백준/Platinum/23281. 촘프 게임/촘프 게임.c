#include<stdio.h>

#define N_MAX 101
#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Pair {
    int first, second;
}P;

P dp[N_MAX][N_MAX][N_MAX];

void updatePair(P *this, P next) {
    this->first = max(this->first, next.second);

    if(!this->second) this->second = next.first;
    else if(next.first * this->second > 0) this->second = max(this->second, next.first);
    else this->second = min(this->second, next.first);
}

P chomp(int one, int two, int three) {
    P *this = &dp[one][two][three];

    if(this->first) return *this;

    *this = (P){0, 0};

    for(int i = 1; i < one; i++) {
        P temp = chomp(i, min(i, two), min(i, three));
        updatePair(this, temp);
    }

    for(int i = 0; i < two; i++) {
        P temp = chomp(one, i, min(i, three));
        updatePair(this, temp);
    }

    for(int i = 0; i < three; i++) {
        P temp = chomp(one, two, i);
        updatePair(this, temp);
    }

    this->first += (this->first > 0 ? 1 : -1);
    this->second += (this->second > 0 ? 1 : -1);

    return *this;
}

int solution(int N) {
    dp[1][0][0] = (P) {.first = -1, .second = 1};
    return chomp(N, N, N).first;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d", solution(N));
}