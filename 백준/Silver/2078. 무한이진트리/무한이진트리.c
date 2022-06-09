#include<stdio.h>

int left, right = 0;

void func(int a, int b) {
    if(a == 1) {
        right += b - 1;
        return;
    }
    if(b == 1) {
        left += a - 1;
        return;
    }
    if(a > b) {
        left++;
        func(a - b, b);
    }
    else {
        right++;
        func(a, b - a);
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    func(a, b);
    printf("%d %d", left, right);
}