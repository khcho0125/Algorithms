#include<stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    printf("%d %d", (n / 100) * 78, n - ((n / 5) / 100) * 22);
}