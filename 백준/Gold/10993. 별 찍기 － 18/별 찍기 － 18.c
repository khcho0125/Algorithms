#include<stdio.h>
#include<math.h>

char map[2050][2050];

void func(int n, int x, int y, int P) {
    if(n < 0) return;

    int length = P - 1;

    if(n % 2) {
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length * 2 - 1 - i; j++) {
                map[x - i][y + j] = ' ';
            }
            map[x][i + y] = '*';
            map[x][(length * 2 - 1) - 1 - i + y] = '*';
            map[x - i][i + y] = '*';
            map[x - i][(length * 2 - 1) - 1 - i + y] = '*';
        }
        func(n - 1, x - length / 2, y + P / 2, P / 2);
    }
    else {
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length * 2 - 1 - i; j++) {
                map[x + i][y + j] = ' ';
            }
            map[x][i + y] = '*';
            map[x][(length * 2 - 1) - 1 - i + y] = '*';
            map[x + i][i + y] = '*';
            map[x + i][(length * 2 - 1) - 1 - i + y] = '*';
        }
        func(n - 1, x + length / 2, y + P / 2, P / 2);
    }
}

int main() {
    int N, length, P;
    scanf("%d", &N);
    P = pow(2, N);
    length = P - 1;
    func(N, (N % 2 ? length - 1 : 0), 0, P);
    for(int i = 0; i < length; i++) {
        printf("%s\n", map[i]);
    }
}