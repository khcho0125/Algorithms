#include<stdio.h>

#define INF ~(1LL << 63)
#define ll long long
#define pow(a) ((a) * (a))
#define max(a, b) (a > b ? a : b)

typedef struct Point {
    ll x, y;
}Point;

Point input[1000];
ll lenght[1000] = {0,};

ll len(Point a, Point b) {
    return pow(a.x - b.x) + pow(a.y - b.y);
}

int main() {
    int N;
    ll min = INF, temp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld %lld", &input[i].x, &input[i].y);
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            temp = len(input[i], input[j]);
            lenght[i] = max(temp, lenght[i]);
        }
    }

    Point result;
    for(int i = 0; i < N; i++) {
        if(lenght[i] < min) {
            min = lenght[i];
            result = input[i];
        }
    }

    printf("%lld %lld", result.x, result.y);
}