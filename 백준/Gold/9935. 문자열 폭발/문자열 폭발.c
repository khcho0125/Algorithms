#include <stdio.h>
#include <string.h>

int main()
{
    char bomb[36];
    char stack[1000001];
    char input[1000001];
    scanf("%s%s", input, bomb);
    int Len = strlen(bomb), pre = 0, i, j;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (bomb[Len - 1] == input[i] && Len - 1 <= pre)
        {
            for (j = 0; j < Len - 1; j++)
            {
                if (stack[pre - Len + 1 + j] != bomb[j])
                {
                    stack[pre++] = input[i];
                    break;
                }
            }
            if (j == Len - 1)
            {
                pre -= Len - 1;
            }
        }
        else
        {
            stack[pre++] = input[i];
        }
    }
    for (int i = 0; i < pre; i++)
    {
        printf("%c", stack[i]);
    }
    if (!pre)
    {
        printf("FRULA");
    }
}
