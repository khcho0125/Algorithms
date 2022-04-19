#include<stdio.h>

int main() {
    int N, sum = 0;
    for(int i = 0; i < 5; i++) {
        scanf("%d", &N);
        if(N < 40) {
            sum += 40; 
        }
        else {
            sum += N;
        }
    }
    printf("%d", sum / 5);
    
}