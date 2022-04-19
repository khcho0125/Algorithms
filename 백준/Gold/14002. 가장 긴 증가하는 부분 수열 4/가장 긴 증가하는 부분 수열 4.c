#include<stdio.h>

int List[1001] = {0,};
int input[1000] = {0,};
int idx[1000] = {0,};
int back = 1;

int search(int n) {
    int min = 1, mid, max = back;
    while(min <= max) {
        mid = (min + max) / 2;
        if(List[mid] < n) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    List[min] = n;
    return min;
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
        if(back == 1 || List[back - 1] < input[i]) {
            idx[i] = back;
            List[back++] = input[i];
        }
        else {
            idx[i] = search(input[i]);
        }
    }
    printf("%d\n", back - 1);
    for(int i = back - 1; i > 0; i--) {
        for(; idx[N - 1] != i; N--);
        List[i] = input[N - 1];
    }
    for(int i = 1; i < back; i++) {
        printf("%d ", List[i]);
    }
}   