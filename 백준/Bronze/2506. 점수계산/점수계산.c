#include<stdio.h>

int main() {
    int N, input, temp = 0, result = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input) {
            result += ++temp;
        }
        else {
            temp = 0;
        }
    }
    printf("%d", result);
}