#include<stdio.h>
#include<math.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

typedef struct Point {
    int x, y;
}Point;

typedef struct Line {
    double w, l;
}Line;

Line line(Point A, Point B) {
    double x = fabs(A.x - B.x);
    double y = fabs(A.y - B.y);

    return (Line){
        .w = y / x,
        .l = sqrt(x * x + y * y)
    };
}

int main() {
    Point A, B, C;

    scanf("%d %d %d %d %d %d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);
    
    Line AB = line(A, B);
    Line BC = line(B, C);
    Line AC = line(A, C);

    if (AB.w == BC.w && AB.w == AC.w) {
        printf("-1");
        return 0;
    }

    double one = (AB.l + BC.l);
    double two = (AB.l + AC.l);
    double three = (BC.l + AC.l);

    double result = (max(one, max(two, three)) - min(one, min(two, three))) * 2;

    printf("%.9lf", result);

}