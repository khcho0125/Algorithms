#include<stdio.h>

int main() {
    int n, m, result = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        result--;
        scanf("%d", &m);
        result += m;
    }

    printf("%d", result);
}