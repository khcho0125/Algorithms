#include <stdio.h>
#include <stdbool.h>

long long Mbit[50] = {0,};
long long Nbit[50] = {0,};
int cnt[50] = {0,};
bool visit[50] = {0,};

int max(int a, int b) {
    return a > b ? a : b;
}

int main()
{
    int N, M, result = 0, K;
    long long input;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1lld", &input);
            Mbit[j] = (Mbit[j] << 1) + input;
        }
    }
    scanf("%d", &K);
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            cnt[n] += !((Mbit[m] >> n) & 1);
            Nbit[n] = (Nbit[n] << 1) + !((Mbit[m] >> n) & 1);
        }
    }
    for(int n = 0; n < N; n++) {
        if(visit[n]) continue;
        int temp = 0;
        visit[n] = true;
        if(cnt[n] <= K && cnt[n] % 2 == K % 2) {
            temp = 1;
            for(int i = n + 1; i < N; i++) {
                if(Nbit[n] == Nbit[i]) {
                    temp++;
                    visit[i] = true;
                }
            }
        }
        result = max(temp, result);
    }
    printf("%d", result);
}