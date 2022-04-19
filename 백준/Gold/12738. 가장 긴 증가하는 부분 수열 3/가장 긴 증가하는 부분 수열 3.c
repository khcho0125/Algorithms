#include<stdio.h>

int list[1000000] = {-1000000001, 0};
int last = 1;

void logN(int n) {
    int min = 1, mid, max = last;
    while(min <= max) {
        mid = (min + max) / 2;
        if(list[mid] < n) {
            min = mid + 1;
        }
        else  {
            max = mid - 1;
        }
    }
    list[min] = n;
}

int main() {
    int input, N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if((last == 1) || list[last - 1] < input) {
            list[last++] = input;
        } else {
            logN(input);
        }
    }
    printf("%d", last - 1);
}