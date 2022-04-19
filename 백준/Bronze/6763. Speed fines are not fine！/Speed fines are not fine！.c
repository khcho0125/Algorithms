#include<stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    if(M - N < 1) {
        printf("Congratulations, you are within the speed limit!");
    } else if(M - N <= 20) {
        printf("You are speeding and your fine is $100.");
    } else if(M - N <= 30) {
        printf("You are speeding and your fine is $270.");
    } else {
        printf("You are speeding and your fine is $500.");
    }
}