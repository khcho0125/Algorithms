#include <stdio.h>

int main()
{
    int arr[7];
    for(int i = 0; i < 7; i++) {
        scanf("%1d", &arr[i]);
    }
    if(arr[0] == arr[1] && arr[2] == arr[1] && arr[1] == 5) {
        printf("YES");
    } else {
        printf("NO");
    }
}