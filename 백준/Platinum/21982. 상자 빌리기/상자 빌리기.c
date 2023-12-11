#include<stdio.h>

#define ll long long
#define N_MAX 5000000
#define max(a, b) ((a) > (b) ? a : b)

typedef struct Box {
    ll h, w;
}B;

ll h[4], w[4];
B queue[N_MAX];
ll p, q;

ll nextHeight(ll x) {
    return x + 1 + ((x * h[1] + h[2]) % h[3]);
}

ll nextWeight(ll x) {
    return (x * w[1] + w[2]) % w[3] + 1;
}

ll solution(ll N, ll X) {
    p = 0, q = 0;

    ll result = -1;
    ll H = (h[0] % h[3]) + 1;
    ll W = (w[0] % w[3]) + 1;

    queue[q++] = (B){.h = H, .w = W};
    for(int i = 1; i < N; i++) {
        ll nextH = nextHeight(H);
        ll nextW = nextWeight(W);

        for(; p < q && nextH - queue[p].h > X; p++);

        if(p < q) result = max(result, queue[p].h * queue[p].w + nextH * nextW);

        for(; p < q && queue[q - 1].h * queue[q - 1].w < nextH * nextW; q--);
        queue[q++] = (B){.h = nextH, .w = nextW};

        H = nextH;
        W = nextW;
    }

    return result;
}

int main() {
    int T, N, X;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &N, &X);
        for(int i = 0; i < 4; i++) scanf("%lld", &h[i]);
        for(int i = 0; i < 4; i++) scanf("%lld", &w[i]);
        printf("%lld\n", solution(N, X));
    }
}