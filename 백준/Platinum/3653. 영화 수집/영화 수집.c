#include<stdio.h>

int segment[800008];
int indexed[100001];

int segment_init(int N, int start, int end, int idx) {
    if (start == end) {

        if(start <= N) {
            indexed[N - start + 1] = start;
            return segment[idx] = 1;
        }

        return segment[idx] = 0;
    }

    int mid = (start + end) / 2;

    int L = segment_init(N, start, mid, idx * 2);
    int R = segment_init(N, mid + 1, end, idx * 2 + 1);

    return segment[idx] = L + R;
}

void init(int N, int M) {
    segment_init(N, 1, N + M, 1);
}

int query(int s, int e, int start, int end, int idx) {
    if (e < start || s > end) return 0;
    
    if (s <= start && end <= e) {
        return segment[idx];
    }

    int mid = (start + end) / 2;

    int L = query(s, e, start, mid, idx * 2);
    int R = query(s, e, mid + 1, end, idx * 2 + 1);

    return L + R;
}

int update(int start, int end, int idx, int where, int value) {
    if (where < start || where > end) {
        return segment[idx];
    }

    if (start == end) {
        return segment[idx] = value;
    }

    int mid = (start + end) / 2;

    int L = update(start, mid, idx * 2, where, value);
    int R = update(mid + 1, end, idx * 2 + 1, where, value);

    return segment[idx] = L + R;
}


int main() {
    int T, N, M, movie;

    scanf("%d", &T);
    for(int t = 0; t < T; t++) {

        scanf("%d %d", &N, &M);
        init(N, M);

        for(int i = 0; i < M; i++) {

            scanf("%d", &movie);
            printf("%d ", query(indexed[movie] + 1, N + i, 1, N + M, 1));

            update(1, N + M, 1, indexed[movie], 0);

            indexed[movie] = N + i + 1;
            update(1, N + M, 1, indexed[movie], 1);
        }

        printf("\n");
    }
}