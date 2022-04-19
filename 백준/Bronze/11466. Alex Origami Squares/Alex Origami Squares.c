#include<stdio.h>

int main() {
    double M, H, temp = 0, i;
    scanf("%lf %lf", &M, &H);
    for(i = 1; i <= 3; i++) {
        if(temp < H / i && H / i <= M / (4 - i)) {
            temp = H / i;
        }
    }
    for(i = 1; i <= 3; i++) {
        if(temp < M / i && M / i <= H / (4 - i)) {
            temp = M / i;
        }
    }
    printf("%lf", temp);
}