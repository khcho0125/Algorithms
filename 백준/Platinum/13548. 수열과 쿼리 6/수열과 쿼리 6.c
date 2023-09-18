#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N_MAX 100001
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Query {
    int idx, i, j;
}Q;

int arr[N_MAX];
int count[N_MAX];
int table[N_MAX];

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

    table[0] = N;
    int s = 1, e = 0, ans = 0, cnt;
    for(int i = 0; i < M; i++) {
        while(query[i].i < s) {
            cnt = ++count[arr[--s]];
            table[cnt - 1]--, table[cnt]++;
            if(ans < cnt) ans = cnt;
        }
        while(s < query[i].i) {
            cnt = count[arr[s++]]--;
            table[cnt - 1]++, table[cnt]--;
            if(!table[ans]) ans = cnt - 1;
        }
        while(query[i].j < e) {
            cnt = count[arr[e--]]--;
            table[cnt - 1]++, table[cnt]--;
            if(!table[ans]) ans = cnt - 1;
        }
        while(e < query[i].j) {
            cnt = ++count[arr[++e]];
            table[cnt - 1]--, table[cnt]++;
            if(ans < cnt) ans = cnt;
        }

        result[query[i].idx] = ans;
    }

    for(int i = 0; i < M; i++) {
        printf("%d\n", result[i]);
    }
}