#include<stdio.h>

int result = 0;

int func(int L, int R) {
    if(!L) return R ? 0 : 1;

    int num1 = L % 10;
    int num2 = R % 10;

    int next = func(L / 10, R / 10);

    if(!next || num1 != num2) return 0;
    result += (num1 == 8);
    return 1;
}

int main() {
    int L, R;
    scanf("%d %d", &L, &R);
    func(L, R);
    printf("%d", result);
}