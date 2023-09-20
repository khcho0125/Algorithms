#include<stdio.h>
#include<string.h>

#define N_MAX 1000001

int arr[N_MAX];
int pi[N_MAX];

void kmp(int e) {
    int begin = 1, matched = 0;
    while(begin + matched < e) {
        if(arr[begin + matched] == arr[matched]) {
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
 
void solve(int N) {
    kmp(N);

    int best = 0, cnt = 0;
    for(int i = 0; i < N; i++) {
        if(best < pi[i]) best = pi[i], cnt = 1;
        else if(best == pi[i]) cnt++;
    }

    if(best) printf("%d %d\n", best, cnt);
    else printf("-1\n");
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = N - 1; i >= 0; i--) {
        scanf("%d", &arr[i]);
    }

    solve(N);
}