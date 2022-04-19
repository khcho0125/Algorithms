#include <stdio.h>

int main()
{
    int input, result = 0, min = 100;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &input);
        if(min > input) min = input;
        result += input;
    }
    printf("%d", result - min);
}