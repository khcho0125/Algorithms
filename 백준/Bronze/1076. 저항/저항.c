#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i, j, k, result[2];
    char input[8] = "";
    char arr[10][7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    for (i = 0; i < 3; i++)
    {
        scanf("%s", input);
        for (j = 0; j < 10; j++)
        {
            if (!strcmp(input, arr[j]))
            {
                if (i != 2)
                {
                    result[i] = j;
                    break;
                }
                else
                {
                    printf("%d", result[0] * 10 + result[1]);
                    if (result[0] * 10 + result[1])
                    {
                        for (k = 0; k < j; k++)
                        {
                            printf("0");
                        }
                    }
                    break;
                }
            }
        }
    }
}