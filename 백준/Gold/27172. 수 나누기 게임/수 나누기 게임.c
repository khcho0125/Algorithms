#include<stdio.h>

#define LIMIT 1000001

int num[LIMIT];
int arr[100001];
int score[100001];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        num[arr[i]] = i;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = arr[i] * 2; j < LIMIT; j += arr[i]) {
            if(num[j]) {
                score[num[j]]--;
                score[i]++;
            }
        }
    }
    
    
    for(int i = 1; i <= N; i++) {
        printf("%d ", score[i]);
    }
}