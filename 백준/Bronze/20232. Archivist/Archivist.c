#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    if(N == 1996 || N == 1997 || N == 2007 || N == 2008 || N == 2000 || N == 2013 || N == 2018) {
        printf("SPbSU");
    } else {
        if(N == 2006) {
            printf("PetrSU, ");
        }
        printf("ITMO");
    }
}