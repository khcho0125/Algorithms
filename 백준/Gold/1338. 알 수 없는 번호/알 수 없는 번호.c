#include<stdio.h>
#include<stdbool.h>

#define swap(a, b) {int i = a; a = b; b = i;}
#define abs(a) ((a) < 0 ? (a) * -1 : a)
#define ll long long

int main() {
    int UnknwonNumber = false;
    ll N, M, x, y, num, absx;
    scanf("%lld %lld %lld %lld", &N, &M, &x, &y);

    absx = abs(x);

    if(N > M) {
        swap(N, M);
    }

    if(0 > y || absx <= y) {
        UnknwonNumber = true;
    }

    if(!UnknwonNumber) {
        ll r = (N % x + x) % x;
        ll Nx = (N - r) / x;
        num = Nx * x + y;

        if(y < r) {
            num += absx;
        }

        UnknwonNumber = num > M || num + absx <= M;
        
    }

    if(UnknwonNumber) {
        printf("Unknwon Number");
        return 0;
    }

    printf("%lld", num);
}