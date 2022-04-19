#include <stdio.h>

int main()
{
    int N, S = 0, T = 0;
    for(int i = 0; i < 4; i++) {
        scanf("%d", &N);
        S += N;
    }
    for(int i = 0; i < 4; i++) {
        scanf("%d", &N);
        T += N;
    }
    printf("%d", S > T ? S : T);
}
