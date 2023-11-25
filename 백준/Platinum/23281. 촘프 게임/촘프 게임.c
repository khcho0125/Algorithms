#include<stdio.h>
#include<stdbool.h>

#define N_MAX 101
#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)

int dp[N_MAX][N_MAX][N_MAX];

void update(int *this, int next) {
    int temp = *this;

    bool nextWin = next & 1, thisWin = temp & 1;

    if(!temp) temp = next;
    else if(nextWin && !thisWin) temp = next;
    else if(nextWin == thisWin) temp = max(temp, next);

    *this = temp;
}

int chomp(int one, int two, int three) {
    int *this = &dp[one][two][three];

    if(*this) return *this;

    *this = 0;

    for(int i = 1; i < one; i++) {
        int temp = chomp(i, min(i, two), min(i, three));
        update(this, temp);
    }

    for(int i = 0; i < two; i++) {
        int temp = chomp(one, i, min(i, three));
        update(this, temp);
    }

    for(int i = 0; i < three; i++) {
        int temp = chomp(one, two, i);
        update(this, temp);
    }

    (*this)++;

    return *this;
}

int solution(int N) {
    dp[1][0][0] = 1;
    return chomp(N, N, N);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d", solution(N));
}