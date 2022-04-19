#include<stdio.h>

int main() {
    int T, n, sum = 0, cnt = 0, temp;
    scanf("%d", &T);
    for(int i = 0; i < T; i++, sum = 0) {
        scanf("%d", &n);
        for(int j = 2; j <= n; j++) {
            temp = n;
            while(temp % j == 0) {
                sum++;
                temp /= j;
            }
        }
        printf("%d\n", sum);
    }
}