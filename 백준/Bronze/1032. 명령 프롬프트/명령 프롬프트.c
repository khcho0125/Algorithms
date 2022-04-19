#include<stdio.h>
#include<string.h>

int main() {
    int N;
    char str[50];
    char str2[50];
    scanf("%d", &N);
    scanf("%s", str);
    for(int i = 0; i < N - 1; i++) {
        scanf("%s", str2);
        if(strcmp(str, str2)) {
            for(int j = 0; j < strlen(str); j++) {
                if(str[j] != str2[j]) {
                    str[j] = '?';
                }
            }
        }
    }
    printf("%s", str);
}