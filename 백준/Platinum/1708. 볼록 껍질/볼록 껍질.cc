#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define ll long long

typedef struct Point {
    ll x, y, p, q;
}Point;

Point stack[100002];
int pre = 0;

bool comparePoint(const Point& num1, const Point& num2) {
    if(num1.q * num2.p != num1.p * num2.q) return (num1.q * num2.p) < (num1.p * num2.q);
    if(num1.y != num2.y) return num1.y < num2.y;
    return num1.x < num2.x;
}

int ccw(Point* one, Point* two, Point* three) {
    ll direct = (two->x - one->x) * (three->y - one->y) - (three->x - one->x) * (two->y  - one->y);
    return direct < 0 ? -1 : (direct > 0 ? 1 : 0);
}

int main() {
    int N, direct;
    ll x, y;
    scanf("%d", &N);
    Point* input = (Point*)malloc(sizeof(Point) * N);
    for(int i = 0; i < N; i++) {
        scanf("%lld %lld", &input[i].x, &input[i].y);
        input[i].p = 0;
        input[i].q = 0;
    }

    sort(input, input + N, comparePoint);
    for(int i = 1; i < N; i++) {
        input[i].p = input[i].x - input[0].x;
        input[i].q = input[i].y - input[0].y;
    }
    sort(input + 1, input + N, comparePoint);
    stack[pre++] = input[0];
    stack[pre++] = input[1];
    for(int i = 2; i < N + 2; i++) {
        while(1) {
            direct = ccw(&stack[pre - 2], &stack[pre - 1], &input[i % N]);
            if(direct == 0) {
                stack[pre - 1] = input[i % N];
                break;
            }
            else if(direct == 1) {
                stack[pre++] = input[i % N];
                break;
            }
            else if(--pre < 2) {
                stack[pre++] = input[i % N];
                break;
            }
        }
    }

    printf("%d", pre - 2);
}