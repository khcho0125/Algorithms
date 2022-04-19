#include<stdio.h>

int main() {
    int input, min = 100, sum = 0, E, F;
    for(int i = 0; i < 4; i++) {
        scanf("%d", &input);
        if(input < min) {
            min = input;
        }
        sum+=input;
    }
    scanf("%d %d", &E, &F);
    printf("%d", sum - min + (E > F ? E : F));
}