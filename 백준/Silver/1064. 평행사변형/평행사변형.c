#include <stdio.h>
#include <math.h>

int main()
{
    int xA, yA, xB, yB, xC, yC;
    double g, h, k;
    scanf("%d %d %d %d %d %d", &xA, &yA, &xB, &yB, &xC, &yC);

    if(fabs(yB - yA) / fabs(xB - xA) == fabs(yC - yB) / fabs(xC - xB) || (xA == xB && xB == xC) || (yA == yB && yB == yC)) {
        printf("-1");
        return 0;
    }

    g = sqrt(pow((xA > xB ? xA - xB : xB - xA), 2) + pow((yA > yB ? yA - yB : yB - yA), 2));
    h = sqrt(pow((xA > xC ? xA - xC : xC - xA), 2) + pow((yA > yC ? yA - yC : yC - yA), 2));
    k = sqrt(pow((xC > xB ? xC - xB : xB - xC), 2) + pow((yC > yB ? yC - yB : yB - yC), 2));
    if(g > h && g > k) {
        printf("%.9lf", (h > k ? g - k : g - h) * 2);
    } else if(h > g && h > k) {
        printf("%.9lf", (g > k ? h - k : h - g) * 2);
    } else {
        printf("%.9lf", (h > g ? k - g : k - h) * 2);
    }
}