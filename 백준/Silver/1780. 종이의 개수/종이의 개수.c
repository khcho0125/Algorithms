#include<stdio.h>
#include<stdlib.h>

void func(int, int, int);

int map[2187][2187] = {0,};

int minus = 0, zero = 0, one = 0;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    
    func(n, 0, 0);

    printf("%d\n%d\n%d", minus, zero, one);
}

void func(int n, int x, int y) {
    int m = 0, z = 0, o = 0;
    for(int i = y; i < n + y; i++) {
        for(int j = x; j < n + x; j++) {
            if(map[i][j] == -1)
                m = 1;
            else if(map[i][j] == 0) 
                z = 1;
            else 
                o = 1;
        }
    }
    
    if(m && !o && !z) {
        minus += 1;
    }
    else if(!m && o && !z) {
        one += 1;
    }
    else if(!m && !o && z) {
        zero += 1;
    }
    else {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                func(n / 3,  x + i * (n / 3), y + j * (n / 3));
            }
        }
    }
}