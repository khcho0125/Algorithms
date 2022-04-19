#include<stdio.h>

int main() {
    int T;
    double input;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%lf", &input);
        printf("$%.2lf\n", input / 5 * 4);
    }
}