#include <stdio.h>

int main()
{
    int B;
    scanf("%d", &B); 
    printf("%d\n", 5 * B - 400);
    if(5 * B - 400 == 100) {
        printf("0");
    } else {
        printf("%d", (5 * B - 400 > 100 ? -1 : 1));
    }
}