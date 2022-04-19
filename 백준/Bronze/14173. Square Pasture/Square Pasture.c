#include<stdio.h>

int main() {
    int x, result = 0, x_min, x_max = 0, y_min, y_max = 0;
    for(int i = 0; i < 4; i++) {
        scanf("%d", &x);
        if(i == 0) 
            x_min = x;
        if(x_min > x) 
            x_min = x;
        if(x_max < x) 
            x_max = x;
        scanf("%d", &x);
        if(i == 0) 
            y_min = x;
        if(y_max < x) 
            y_max = x;
        if(y_min > x) 
            y_min = x;
    }
    printf("%d", (x_max - x_min) > (y_max - y_min) ? (x_max - x_min) * (x_max - x_min) : (y_max - y_min) * (y_max - y_min));
}