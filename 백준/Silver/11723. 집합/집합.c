#include <stdio.h>
#include <string.h>

int main()
{
    int T, n;
    int Bit = Bit & (1 << 20);
    char input[7];
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%s", input);
        if (!strcmp(input, "add"))
        {
            scanf("%d", &n);
            Bit = Bit | (1 << n - 1);
        }
        else if (!strcmp(input, "check"))
        {
            scanf("%d", &n);
            printf("%d\n", (Bit >> n - 1) & 1);
        }
        else if (!strcmp(input, "remove"))
        {
            scanf("%d", &n);
            Bit = Bit & ~(1 << n - 1);
        }
        else if (!strcmp(input, "toggle"))
        {
            scanf("%d", &n);
            Bit = Bit ^ (1 << n - 1);
        }
        else if (!strcmp(input, "all"))
        {
            Bit = Bit | ~(1 << 20);
        }
        else if (!strcmp(input, "empty"))
        {
            Bit = Bit & (1 << 20);
        }
    }
}