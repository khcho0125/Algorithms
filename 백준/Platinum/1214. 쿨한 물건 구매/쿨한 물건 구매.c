#include<stdio.h>

#define min(a, b) ((a) < (b) ? a : b)
#define swap(a, b) {int _swap = a; a = b; b = _swap;}
#define ll long long

int overDivide(int N, int M) {
    return (N / M) + (N % M != 0);
}

int main() {
    int D, P, Q;

    scanf("%d %d %d", &D, &P, &Q);

    if(P < Q) swap(P, Q);

    int n_max = min((D / P) + (D % P != 0), Q);

    int NP = n_max * P;
    int result = (D <= NP ? NP : NP + overDivide(D - NP, Q) * Q);
    for(int n = 0; n < n_max; n++) {
        NP = n * P;
        int value = NP + overDivide(D - NP, Q) * Q;
        result = min(result, value);
    }

    printf("%d", result);
}