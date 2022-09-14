#include<stdio.h>

#define max(a, b) (a > b ? a : b)

int T[6][3];
int result;

void solve(int idx, int bit, int next, int last, int sum) {

    if(bit == (1 << 6) - 1) {
        for(int i = 0; i < 3; i++) {
            if(T[idx][i] == next && T[idx][(i + 2) % 3] == last) {
                result = max(result, sum + T[idx][(i + 1) % 3]);
            }
        }
        return;
    }

    for(int i = 0; i < 3; i++) {
        if(T[idx][i] == next) {
            for(int j = 1; j < 6; j++) {
                if(!(bit & 1 << j)) {
                    solve(j, bit | 1 << j, T[idx][(i + 2) % 3], last, sum + T[idx][(i + 1) % 3]);
                }
            }
        }
    }
}

int main() {
    char input = '*';
    while(input == '*') {
        result = -1;
        for(int i = 0; i < 6; i++) {
            scanf("%d %d %d", &T[i][0], &T[i][1], &T[i][2]);
        }

        int temp;
        for(int i = 0; i < 3; i++) {
            for(int j = 1; j < 6; j++) {
                solve(j, 1 + (1 << j), T[0][i], T[0][(i + 1) % 3], T[0][(i + 2) % 3]);
            }
        }

        result == -1 ? printf("none\n") : printf("%d\n", result);

        scanf(" %c", &input);
    }
}