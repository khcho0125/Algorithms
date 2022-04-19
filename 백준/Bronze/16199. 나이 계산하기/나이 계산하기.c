#include<stdio.h>

int main() {
    int y ,y2 ,m ,m2 ,d ,d2;
    scanf("%d %d %d %d %d %d", &y, &m, &d, &y2, &m2, &d2);
    printf("%d\n%d\n%d\n", y2 - y + (m < m2 || (m == m2 && d <= d2)) - 1, y2 - y + 1, y2 - y);
}
