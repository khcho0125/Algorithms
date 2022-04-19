#include <stdio.h>

int main() {
    int n, temp = 0, result = 1, i;
    scanf("%d", &n);
    for(i = 1; i < n; i+=temp) {
        temp += 6;
        result++;
    }
    printf("%d", result);
}