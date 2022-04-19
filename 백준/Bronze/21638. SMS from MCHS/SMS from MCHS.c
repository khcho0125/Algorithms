#include <stdio.h>

int main()
{
    int t1, u1, t2, u2;
    scanf("%d %d %d %d", &t1, &u1, &t2, &u2);
    if(t2 < 0 && u2 >= 10) {
        printf("A storm warning for tomorrow! Be careful and stay home if possible!");
    } else if(t1 > t2) {
        printf("MCHS warns! Low temperature is expected tomorrow.");
    } else if(u1 < u2) {
        printf("MCHS warns! Strong wind is expected tomorrow.");
    } else {
        printf("No message");
    }
}