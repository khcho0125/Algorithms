#include<stdio.h>

int GCD(int a, int b) {

    if(a % b == 0) {
        return b;
    }
    
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

int main() {
    int T, x, y, M, N, max;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        max = LCM(M, N);
        while(x <= max) {
            if((x - 1) % N + 1 == y) {
                break;
            }
            x += M;
        }
        if(x > max) {
            printf("-1\n");
        } else {
            printf("%d\n", x);
        }
    }
}