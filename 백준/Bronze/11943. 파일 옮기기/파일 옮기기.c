#include<stdio.h>

int main() {
    int orange[2];
    int apple[2];
    for(int i = 0; i < 2; i++) {
        scanf("%d %d", &apple[i], &orange[i]);
    }
    printf("%d", apple[0] + orange[1] > apple[1] + orange[0] ? apple[1] + orange[0] : apple[0] + orange[1]);
}