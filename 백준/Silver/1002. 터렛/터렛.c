#include<stdio.h>
#include<math.h>

#define Pow(a) ((a) * (a))

int main() {
    int T, result;
    double x1, y1, x2, y2, temp;
    int r1, r2;
    scanf("%d", &T);
    for(int t = 0; t < T; t++) {
        scanf("%lf %lf %d %lf %lf %d", &x1, &y1, &r1, &x2, &y2, &r2);
        temp = sqrt(Pow(x1 - x2) + Pow(y1 - y2));
        if(x1 == x2 && y1 == y2 && r1 == r2) {
            result = -1;
        }
        else if(temp == r1 + r2 || temp + r1 == r2 || temp + r2 == r1) {
            result = 1;
        }
        else if(temp > r1 + r2 || temp + r1 < r2 || temp + r2 < r1) {
            result = 0;
        }
        else {
            result = 2;
        }
        printf("%d\n", result);
    }
}