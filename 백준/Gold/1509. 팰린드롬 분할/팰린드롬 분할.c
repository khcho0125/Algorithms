#include<stdio.h>
#include<stdbool.h>

#define min(a, b) (a < b ? a : b)

int D[2501] = {0,};
bool P[2501][2501];
char str[2501];

int main() {
    int len = 0;
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++, len++) P[i][i] = true;
    
    for(int i = 0; i < len - 1; i++) {
        P[i][i + 1] = str[i] == str[i + 1];
    }

    for(int i = 2; i < len; i++) {
        for(int j = 0; j < len - i; j++) {
            P[j][j + i] = str[j] == str[j + i] && P[j + 1][j + i - 1];
        }
    }

    D[0] = 1;
    for(int i = 1; i < len; i++) {
        D[i] = D[i - 1] + 1;
        for(int j = 1; j <= i; j++) {
            if(P[i - j][i]) D[i] = min(D[i], D[i - j - 1] + 1);
        }
    }

    printf("%d", D[len - 1]);

}