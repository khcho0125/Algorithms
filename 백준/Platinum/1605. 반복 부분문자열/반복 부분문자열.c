#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 200001

#define max(a, b) ((a) > (b) ? a : b)
#define cmp(a, b, c) (rank[a] < rank[b] || (rank[a] == rank[b] && rank[a + c] < rank[b + c]))

char str[MAX_LEN];
int rank[MAX_LEN + MAX_LEN], nextRank[MAX_LEN + MAX_LEN];
int idx[MAX_LEN];

int* suffix(int len) {
    int m = len + 1;
    int* cnt = (int*)malloc(sizeof(int) * m);
    int* sa = (int*)malloc(sizeof(int) * len);

    for(int i = 0; i < len; i++) sa[i] = i, rank[i] = str[i] - 'a' + 1;

    for(int d = 1; d < len; d <<= 1) {
        memset(cnt, 0, sizeof(int) * m);
        for(int i = 0; i < len; i++) cnt[rank[i + d]]++;
        for(int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for(int i = len - 1; i >= 0; i--) idx[--cnt[rank[i + d]]] = i;

        memset(cnt, 0, sizeof(int) * m);
        for(int i = 0; i < len; i++) cnt[rank[i]]++;
        for(int i = 1; i < m; i++) cnt[i] += cnt[i - 1];
        for(int i = len - 1; i >= 0; i--) sa[--cnt[rank[idx[i]]]] = idx[i];

        nextRank[sa[0]] = 1;
        for(int i = 1; i < len; i++) nextRank[sa[i]] = nextRank[sa[i - 1]] + cmp(sa[i - 1], sa[i], d);
        for(int i = 0; i < len; i++) rank[i] = nextRank[i];

        if(rank[sa[len - 1]] == len) break;
    }

    return sa;
}

int lcp(int* sa, int len) {
    int result = 0;
    int* isa = (int*)malloc(sizeof(int) * len);

    for(int i = 0; i < len; i++) isa[sa[i]] = i;

    for(int i = 0, k = 0; i < len; i++) if (isa[i]) {
        for(int j = sa[isa[i] - 1]; str[j + k] == str[i + k]; k++);
        result = max(result, k);
        k ? k-- : 0;
    }

    return result;
}

int main() {
    int L;
    scanf("%d %s", &L, str);

    int* sa = suffix(L);
    printf("%d", lcp(sa, L));
}