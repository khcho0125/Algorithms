#include <stdio.h>

int main()
{
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cnt++;
        }
        if(cnt == m) {
            printf("%d", i);
            return 0;
        }
    }
    printf("0");
}