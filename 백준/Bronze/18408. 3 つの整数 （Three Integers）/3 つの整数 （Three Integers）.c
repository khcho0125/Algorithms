#include <stdio.h>

int main()
{
    int arr[2] = {0,};
    int input;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &input);
        arr[input - 1]++;
    }
    printf("%d", (arr[0] > arr[1] ? 1 : 2));
}