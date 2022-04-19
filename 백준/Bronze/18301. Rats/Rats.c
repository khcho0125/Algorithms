#include<stdio.h>
int main() {
    int n, m, set;
    scanf("%d %d %d", &n, &m, &set);
    printf("%d", (n + 1)*(m + 1) / (set + 1) - 1);
}