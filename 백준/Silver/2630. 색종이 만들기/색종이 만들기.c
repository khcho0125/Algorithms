#include<stdio.h>

int map[128][128] = {0,};

int white = 0, blue = 0;

int func(int n, int x, int y) {
    
    if(n == 1) {
        return map[x][y];
    }

    int onepi = func(n / 2, x, y);
    int twopi = func(n / 2, x, y + n / 2);
    int threepi = func(n / 2, x + n / 2, y);
    int fourpi = func(n / 2., x + n / 2, y + n / 2);
    if(onepi == twopi && onepi == threepi && onepi == fourpi) {
        return onepi;
    }
    else {
        if(onepi <= 1) {
            onepi > 0 ? blue++ : white++;
        }
        if(twopi <= 1) {
            twopi > 0 ? blue++ : white++;
        }
        if(threepi <= 1) {
            threepi > 0 ? blue++ : white++;
        }
        if(fourpi <= 1) {
            fourpi > 0 ? blue++ : white++;
        }
        return 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    int last = func(n, 0, 0);
    if(last == 1)
        blue++;
    if(last == 0) 
        white++;

    printf("%d\n%d", white, blue);
}