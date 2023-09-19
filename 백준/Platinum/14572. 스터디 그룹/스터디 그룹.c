#include<stdio.h>
#include<stdlib.h>

#define N_MAX 100000
#define K_MAX 31
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Student {
    int known, d;
}S;

S member[N_MAX];
int algorithm[K_MAX];

int compare(const void* a, const void* b) {
    int ad = ((S*)a)->d;
    int bd = ((S*)b)->d;

    return ad < bd ? -1 : ad > bd;
}

int E(int group, int K) {
    int count = 0;
    for(int i = 1; i <= K; i++) {
        count += (algorithm[i] > 0) - (algorithm[i] == group);
    }
    return count * group;
}

int main() {
    int N, K, D, M, A, a;
    scanf("%d %d %d", &N, &K, &D);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &M, &member[i].d);
        for(int j = 0; j < M; j++) {
            scanf("%d", &a);
            member[i].known |= 1 << a;
        }
    }

    qsort(member, N, sizeof(S), compare);
    
    int low = 0, high = 0, best = 0, next;
    while(high < N) {
        for(next = high + 1; next < N && member[next].d - member[low].d <= D; next++);

        for(int i = high; i < next; i++) {
            for(int k = 1; k <= K && (1 << k) <= member[i].known; k++) algorithm[k] += ((member[i].known & (1 << k)) != 0);
        }
        
        high = next;

        int result = E(high - low, K);
        best = max(best, result);

        for(next = low + 1; member[high].d - member[next].d > D; next++);

        for(int i = low; i < next; i++) {
            for(int k = 1; k <= K && (1 << k) <= member[i].known; k++) algorithm[k] -= ((member[i].known & (1 << k)) != 0);
        }

        low = next;
    }

    printf("%d", best);
}