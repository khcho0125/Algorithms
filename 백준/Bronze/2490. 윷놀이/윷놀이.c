#include <stdio.h>

int main()
{
    int a, b, c, d, sum;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        sum = a + b + c + d;
        if(sum == 0) {
            printf("D\n");
        }
        else if(sum == 1) {
            printf("C\n");
        }
        else if(sum == 2) {
            printf("B\n");
        }
        else if(sum == 3) {
            printf("A\n");
        }
        else {
            printf("E\n");
        }
    }
}