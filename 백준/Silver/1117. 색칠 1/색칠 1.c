#include<stdio.h>

#define ll long long
#define min(a, b) (a < b ? a : b)

int main() {
    ll W, H, F, C, X1, X2, Y1, Y2;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &W, &H, &F, &C, &X1, &Y1, &X2, &Y2);
    F = min(F, W - F);
    ll color = (((X2 - X1) * (Y2 - Y1)) + (X2 <= F ? (X2 - X1) * (Y2 - Y1) : (X1 < F ? (F - X1) * (Y2 - Y1) : 0LL))) * (C + 1LL);
    printf("%lld", W * H - color);
}