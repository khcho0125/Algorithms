#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define S_MAX_LEN 1000001
#define ll long long
#define max(a, b) ((a) > (b) ? a : b)

char S[S_MAX_LEN];
int suffix[S_MAX_LEN];
int rank[S_MAX_LEN * 2], nextRank[S_MAX_LEN * 2];
int cnt[S_MAX_LEN];
int idx[S_MAX_LEN];

int lcp[S_MAX_LEN];
int isa[S_MAX_LEN];

bool diff(int a, int b, int d) {
    return rank[a] != rank[b] || rank[a + d] != rank[b + d];
}

void suffix_array(int len) {
    int lim = max(27, len);
    for(int i = 0; i < len; i++) suffix[i] = i, rank[i] = S[i] - 'a' + 1;

    for(int d = 1; d < len; d <<= 1) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < len; i++) cnt[rank[i + d]]++;
        for(int i = 1; i <= lim; i++) cnt[i] += cnt[i - 1];
        for(int i = len - 1; i >= 0; i--) idx[--cnt[rank[i + d]]] = i;

        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < len; i++) cnt[rank[i]]++;
        for(int i = 1; i <= lim; i++) cnt[i] += cnt[i - 1];
        for(int i = len - 1; i >= 0; i--) suffix[--cnt[rank[idx[i]]]] = idx[i];

        nextRank[suffix[0]] = 1;
        for(int i = 1; i < len; i++) nextRank[suffix[i]] = nextRank[suffix[i - 1]] + diff(suffix[i], suffix[i - 1], d);
        for(int i = 0; i < len; i++) rank[i] = nextRank[i];
    }
}

void lcp_array(int len) {
    for(int i = 0; i < len; i++) isa[suffix[i]] = i;
    
    for(int i = 0, k = 0; i < len; i++) if(isa[i]) {
        for(int j = suffix[isa[i] - 1]; S[j + k] == S[i + k]; k++);
        lcp[isa[i]] = k;
        if(k) k--;
    }
}

int main() {
    scanf("%s", S);
    int len = strlen(S);

    suffix_array(len);
    lcp_array(len);

    ll result = 0;
    for(int i = 0; i < len; i++) result += len - i - lcp[i];
    printf("%lld", result);
}