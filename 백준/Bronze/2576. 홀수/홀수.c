#include<stdio.h>

#define min(a, b) ((a < b) ? a : b)

int main() {
    int Max = -1, Sum = 0, input;
    for(int i = 0; i < 7; i++) {
        scanf("%d", &input);
        if(input % 2) {
            if(Max == -1) {
                Max = input;
            }
            else Max = min(Max, input);
            
            Sum += input;
        }
    }
    if(Max == -1) {
        printf("-1");
        return 0;
    }
    printf("%d\n%d", Sum, Max);
}