#include<stdio.h>
#include<math.h>

int main() {
    int A, B, C, D, E, result = 0;
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);
    
    while(A < B) {
        if(A < 0) {
            result += C;
        } else if(A == 0) {
            result += D + E;
        } else {
            result += E;
        }
        A++;
    }
    printf("%d", result);
}