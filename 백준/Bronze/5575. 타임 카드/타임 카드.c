#include <stdio.h>

int main()
{
    int arr[3];
    int input;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < 3; i++) {
            scanf("%d", &input);
            arr[i] = input - arr[i];
        }
        for(int i = 2; i >= 0; i--) {
            if(arr[i] < 0) {
                arr[i - 1]--;
                arr[i] += 60;
            }
        }
        printf("%d %d %d\n", arr[0], arr[1], arr[2]);
    }
}
