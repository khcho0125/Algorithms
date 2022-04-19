#include <stdio.h>

int main() {
    long long int a, b, c;
    int temp;
    scanf("%lld %lld %lld", &a, &b, &c);
    while(a || b || c) {
        if(a < b) {
            temp = a;
            a = b;
            b = temp;
        }
        if(a < c) {
            temp = a;
            a = c;
            c = temp;
        }
        if(a*a == b*b + c*c) printf("right\n");
        else printf("wrong\n");
        scanf("%lld %lld %lld", &a, &b, &c);
    }
}