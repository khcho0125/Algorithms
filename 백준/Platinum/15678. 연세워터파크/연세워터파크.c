#include<stdio.h>

#define INF -1000000001
#define max(a, b) ((a) > (b) ? a : b)
#define ll long long

typedef struct Priority {
    ll score;
    int idx;
}PQ;

PQ queue[100000];
int temp = 0;

void push(ll score, int idx) {
    int here = ++temp;
    while(here != 1 && queue[here / 2].score < score) {
        queue[here] = queue[here / 2];
        here /= 2;
    }

    queue[here] = (PQ){.idx = idx, .score = score};
}

PQ pop() {
    PQ top = queue[1];
    PQ last = queue[temp--];

    int child = 2, parent = 1;
    while(child <= temp) {
        if(child + 1 <= temp && queue[child].score < queue[child + 1].score) {
            child++;
        }

        if (queue[child].score < last.score) {
            break;
        }

        queue[parent] = queue[child];
        parent = child;
        child *= 2;
    }

    queue[parent] = last;

    return top;
}

int main() {
    int N, D;
    ll K, result = INF;
    scanf("%d %d", &N, &D);
    for(int i = 0; i < N; i++) {
        while(temp && queue[1].idx + D < i) {
            K = pop().score;
            result = max(result, K);
        }

        scanf("%lld", &K);

        if(temp) K += queue[1].score;

        if(K < 0) {
            result = max(result, K);
            continue;
        }
        
        if(temp && K > queue[1].score) temp = 0;
        push(K, i);
    }

    if(temp) {
        result = max(result, queue[1].score);
    }

    printf("%lld", result);
}