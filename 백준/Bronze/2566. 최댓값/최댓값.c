#include<stdio.h>

int main() {
    int result = -1, x = 0, y = 0, input;
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            scanf("%d", &input);
            if(input > result) {
                x = i;
                y = j;
                result = input;
            }
        }
    }
    printf("%d\n%d %d", result, x, y);
}