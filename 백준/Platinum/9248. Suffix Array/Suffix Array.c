#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 500001

typedef struct Rank {
    int i, first, second;
}R;

char S[N_MAX];

int compare(const void* a, const void* b) {
    R A = *(R*)a;
    R B = *(R*)b;

    if(A.first != B.first) return A.first > B.first ? 1 : -1;
    return A.second > B.second ? 1 : -1;
}

bool diff(const R* a, const R* b) {
    return a->first != b->first || a->second != b->second;
}

int* suffix_array(int s_len) {
    R* order = (R*)malloc(sizeof(R) * s_len);
    int* rank = (int*)malloc(sizeof(int) * s_len);
    int* suffix = (int*)malloc(sizeof(int) * s_len);

    for(int i = 0; i < s_len; i++) {
        order[i].i = i;
        rank[i] = S[i] - 'a' + 1;
    }

    for(int d = 1; d < s_len; d <<= 1) {
        for(int i = 0; i < s_len; i++) {
            order[i].first = rank[order[i].i];
            order[i].second = order[i].i + d < s_len ? rank[order[i].i + d] : 0;
        }

        qsort(order, s_len, sizeof(R), compare);

        rank[order[0].i] = 1;
        for(int i = 1; i < s_len; i++) rank[order[i].i] = rank[order[i - 1].i] + diff(&order[i - 1], &order[i]);
    }

    for(int i = 0; i < s_len; i++) suffix[i] = order[i].i;

    return suffix;
}

int* build_lcp(int* suffix, int s_len) {
    int* isa = (int*)malloc(sizeof(int) * s_len);
    int* lcp = (int*)malloc(sizeof(int) * s_len);
    memset(lcp, 0, sizeof(int) * s_len);

    for(int i = 0; i < s_len; i++) isa[suffix[i]] = i;

    for(int i = 0, k = 0; i < s_len; i++) if(isa[i]) {
        for(int j = suffix[isa[i] - 1]; S[j + k] == S[i + k]; k++);
        lcp[isa[i]] = k;
        if(k) --k;
    }

    return lcp;
}

int main() {
    int len;
    scanf("%s", S);
    
    len = strlen(S);

    int* suffix = suffix_array(len);
    int* lcp = build_lcp(suffix, len);

    for(int i = 0; i < len; i++) {
        printf("%d ", suffix[i] + 1);
    }
    printf("\nx ");
    for(int i = 1; i < len; i++) {
        printf("%d ", lcp[i]);
    }
}