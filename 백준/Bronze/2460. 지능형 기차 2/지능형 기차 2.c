#include<stdio.h>

int main() {
    int n, m, ple = 0, max = 0;
    for(int i = 0; i < 10; i++) {
        scanf("%d %d", &n, &m);
        ple += m - n;
        if(ple > max) {
            max = ple;
        }
    }
    printf("%d", max);
}