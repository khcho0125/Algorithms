#include <stdio.h>

int main() {
    long int n, m, i, temp, ucl, pre;
    scanf("%d %d", &n, &m);
    temp = n > m ? n : m;
    ucl = n < m ? n : m;
    for(i = 0; temp % ucl; i++) {
        pre = temp % ucl;
        temp = ucl;
        ucl = pre;
    }
    printf("%ld\n%ld", ucl, (n / ucl) * m);
}