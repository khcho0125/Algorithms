#include<stdio.h>

#define ll long long
#define MOD 1000000007LL

typedef struct Matrix {
    ll field[21][21];
}Matrix;

Matrix map[30][100];
int N, T;

Matrix operator(Matrix a, Matrix b) {
    Matrix temp;
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            temp.field[k][i] = 0;
            for(int j = 1; j <= N; j++) {
                temp.field[k][i] = (temp.field[k][i] + (a.field[k][j] * b.field[j][i] % MOD)) % MOD;
            }
        }
    }
    return temp;
}

int main() {
    int D, M, a, b, c;
    scanf("%d %d %d", &T, &N, &D);
    for(int i = 0; i < T; i++) {
        scanf("%d", &M);
        for(int j = 0; j < M; j++) {
            scanf("%d %d %d", &a, &b, &c);
            map[0][i].field[a][b] = c;
        }
    }

    for(int i = 0; i < 29; i++) {
        for(int j = 0; j < T; j++) {
            map[i + 1][j] = operator(map[i][j], map[i][(j + (1 << i)) % T]);
        }
    }

    Matrix ans;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            ans.field[i][j] = 0;
        }
        ans.field[i][i] = 1;
    }

    int temp = 0;
    for(int bit = 29; bit >= 0; bit--) {
        if(D & (1 << bit)) {
            ans = operator(ans, map[bit][temp % T]);
            temp += (1 << bit);
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            printf("%lld ", ans.field[i][j]);
        }
        printf("\n");
    }
}