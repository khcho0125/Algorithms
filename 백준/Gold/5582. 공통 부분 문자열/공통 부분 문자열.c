#include<stdio.h>
#include<string.h>

int LCS[4001][4001] = {0,};

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char arr[2][4001];
    int result = 0;
    scanf("%s", &arr[0]);
    scanf("%s", &arr[1]);
    int len0 = strlen(arr[0]);
    int len1 = strlen(arr[1]);
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len0; j++) {
            if(arr[1][i - 1] == arr[0][j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                result = max(result, LCS[i][j]);
            }
        }
    }
    printf("%d", result);
}