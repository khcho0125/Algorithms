#include<stdio.h>
#include<math.h>

#define Pow(a) ((a) * (a))

int main() {
    int T, N, x1, y1, x2, y2, x, y, r;
    double temp1, temp2;
    scanf("%d", &T);
    for(int i = 0, result = 0; i < T; i++, result = 0) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &N);
        for(int j = 0; j < N; j++) {
            scanf("%d %d %d", &x, &y, &r);
            temp1 = sqrt(Pow(x - x1) + Pow(y - y1));
            temp2 = sqrt(Pow(x - x2) + Pow(y - y2));
            if((temp1 < r && !(temp2 < r)) || (!(temp1 < r) && temp2 < r)) {
                result++;
            }
        }
        printf("%d\n", result);
    }
}