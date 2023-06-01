#include<stdio.h>

int main() {
    double result;
    char input[2];
    scanf("%s", input);
    result = 'E' - input[0];
    if(result > 0) {
        result += (input[1] == '+' ? 0.3f : (input[1] == '-' ? -0.3f : 0));
        printf("%.1lf", result);
        return 0;
    }
    printf("0.0");
}