#include <stdio.h>

int main()
{
    int n, k, i, j, T, sum;
    int arr[15][15];
    for(i = 0; i < 15; i++) {
        sum = 0;
        for(j = 1; j < 15; j++) {
            if(i == 0) {
                arr[i][j] = j;
            } else {
                sum += arr[i - 1][j];
                arr[i][j] = sum;
            }
        }
    }
    scanf("%d", &T);
    for(i = 0; i < T; i++) {
        scanf("%d %d", &n, &k);
        printf("%d\n", arr[n][k]);
    }
}