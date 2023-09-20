#include<stdio.h>
#include<string.h>

#define N_MAX 1000001
#define min(a, b) ((a) < (b) ? a : b)

int seq[N_MAX];
int pi[N_MAX];

void kmp(int n) {
    int begin = 1, matched = 0;
    while(begin + matched < n) {
        if(seq[begin + matched] == seq[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else {
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}

int main() {
    int N, k, p;
    scanf("%d", &N);
    for(int i = N - 1; i >= 0; i--) {
        scanf("%d", &seq[i]);
    }

    kmp(N);

    int m = 0;
    for(int i = 1; i < N; i++) if(pi[m] < pi[i]) m = i;

    k = N - m - 1;
    p = N - k - pi[m];
    printf("%d %d", k, p);
}