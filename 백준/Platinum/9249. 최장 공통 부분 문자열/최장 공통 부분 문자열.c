#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 200010
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Rank {
    int i, first, second;
}R;

char S[N_MAX];
char T[N_MAX];
int s_len, t_len;

R table[N_MAX];
int rank[N_MAX];
int suffix[N_MAX];
int isa[N_MAX];

int compare(const void* a, const void* b) {
    R A = *(R*)a;
    R B = *(R*)b;

    if(A.first != B.first) return A.first > B.first ? 1 : -1;
    return A.second > B.second ? 1 : -1;
}

bool diff(const R* a, const R* b) {
    return a->first != b->first || a->second != b->second;
}

int str(int idx) {
    if(idx < s_len) return S[idx] - 'a' + 1;
    return idx == s_len ? 0 : T[idx - s_len - 1] - 'a' + 1;
}

void suffix_array() {
    int len = s_len + t_len + 1;
    for(int sp = 0; sp < len; sp++) {
        table[sp].i = sp;
        rank[sp] = str(sp);
    }

    for(int d = 1; d < len; d <<= 1) {
        for(int i = 0; i < len; i++) {
            table[i].first = rank[table[i].i];
            table[i].second = table[i].i + d < len ? rank[table[i].i + d] : 0;
        }

        qsort(table, len, sizeof(R), compare);

        rank[table[0].i] = 0;
        for(int i = 1; i < len; i++) rank[table[i].i] = rank[table[i - 1].i] + diff(&table[i - 1], &table[i]);
    }

    for(int i = 0; i < len; i++) {
        suffix[i] = table[i].i;
        isa[suffix[i]] = i;
    }
}

void lcp() {
    int result = -1, cs = 0;
    for(int i = 0, k = 0; i < s_len + t_len + 1; i++) if(isa[i]) {
        for(int j = suffix[isa[i] - 1]; str(i + k) == str(j + k) && (i < s_len) ^ (j < s_len); k++);
        if(result < k) {
            result = k;
            cs = i;
        }
        if(k) --k;
    }

    printf("%d\n", result);
    for(int i = cs; i < cs + result; i++) printf("%c", 'a' + str(i) - 1);
}

int main() {
    scanf("%s", S);
    scanf("%s", T);

    s_len = strlen(S);
    t_len = strlen(T);

    suffix_array();
    lcp();
}