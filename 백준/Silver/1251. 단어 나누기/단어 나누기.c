#include<stdio.h>
#include<string.h>

char str[51];
char result[51];

void solve(int one, int two, int len) {
    int i;
    for(i = 0; i <= one; i++) {
        result[i] = str[one - i];
    }
    for(i = 0; i < two - one; i++) {
        result[one + i + 1] = str[two - i];
    }
    for(i = 0; i < len - two; i++) {
        result[two + i + 1] = str[len - i];
    }
}

int compare(int one, int two, int len) {
    int i;
    for(i = 0; i <= one; i++) {
        if(result[i] < str[one - i]) return 0;
        if(result[i] > str[one - i]) return 1;
    }
    for(i = 0; i < two - one; i++) {
        if(result[one + i + 1] < str[two - i]) return 0;
        if(result[one + i + 1] > str[two - i]) return 1;
    }
    for(i = 0; i < len - two; i++) {
        if(result[two + i + 1] < str[len - i]) return 0;
        if(result[two + i + 1] > str[len - i]) return 1;
    }
    return 0;
}

int main() {
    int k;
    scanf("%s", str);
    int len = strlen(str) - 1;
    for(int i = 0; i < len - 1; i++) {
        for(int j = i + 1; j < len; j++) {
            if(!(i == 0 && j == 1) && !compare(i, j, len)) {
                continue;
            }
            solve(i, j, len);
        }
    }
    printf("%s", result);
}