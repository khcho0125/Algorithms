#include<stdio.h>

int main() {
    int d, h, m, sum = 0;
    scanf("%d %d %d", &d, &h, &m);
    sum += (d - 11) * 1440;
    sum += (h - 11) * 60;
    sum += m - 11;
    if(sum < 0) {
        printf("-1");
        return 0;
    }
    printf("%d", sum);
    
}