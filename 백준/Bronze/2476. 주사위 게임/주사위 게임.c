#include <stdio.h>

int main()
{
    int T, a, b, c, max = 0, money;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a == b && b == c) {
            money = 10000 + a * 1000; 
        }
        else if(a == b || b == c || a == c) {
            money = 1000 + (a == b ? a : c) * 100;
        }
        else {
            money = ((a > b ? a : b) > c ? (a > b ? a : b) : c) * 100;
        }
        if(max < money) {
            max = money;
        }
    }
    printf("%d", max);
}