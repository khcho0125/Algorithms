#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N_MAX 100001
#define A_MAX 1000001

typedef struct Query {
    int idx, i, j;
}Q;

int arr[N_MAX];
int table[A_MAX];
int k;

Q query[N_MAX];
int result[N_MAX];

int sqrtDecomposition(const void* a, const void* b) {
    Q A = *(Q*)a;
    Q B = *(Q*)b;

    int Ask = A.i / k, Bsk = B.i / k;
    
    if(Ask == Bsk) return A.j < B.j ? -1 : A.j > B.j;
    return Ask > Bsk ? 1 : -1;
}

int main() {
    int N, M;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    k = sqrt(N);

    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &query[i].i, &query[i].j);
        query[i].idx = i;
    }

    qsort(query, M, sizeof(Q), sqrtDecomposition);

    int s = 0, e = 0, count = 0;
    for(int i = 0; i < M; i++) {
        while(query[i].i < s) {
            if(!table[arr[--s]]) count++;
            table[arr[s]]++;
        }
        while(s < query[i].i) {
            table[arr[s]]--;
            if(!table[arr[s++]]) count--;
        }
        while(query[i].j < e) {
            table[arr[e]]--;
            if(!table[arr[e--]]) count--;
        }
        while(e < query[i].j) {
            if(!table[arr[++e]]) count++;
            table[arr[e]]++;
        }
        result[query[i].idx] = count;
    }

    for(int i = 0; i < M; i++) {
        printf("%d\n", result[i]);
    }
}