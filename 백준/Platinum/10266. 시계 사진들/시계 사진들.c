#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N_MAX 200000
#define CLOCK_ANGLE 360000

int A[N_MAX];
int B[N_MAX];

int AT[N_MAX];
int BT[N_MAX];

int minest(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;

    return A < B ? -1 : A != B;
}

int* matching(int len) {
    int* next = (int*)malloc(sizeof(int) * len);
    memset(next, 0, sizeof(int) * len);

    int matched = 0, begin = 1;
    while(begin + matched < len) {
        if(BT[begin + matched] == BT[matched]) {
            matched++;
            next[begin + matched - 1] = matched;
        }
        else {
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - next[matched - 1];
                matched = next[matched - 1];
            }
        }
    }

    return next;
}

bool kmp(int len) {
    int* next = matching(len);

    int begin = 0, matched = 0;
    while(begin < len) {
        if(AT[(begin + matched) % len] == BT[matched]) {
            matched++;

            if(matched == len) {
                return true;
            }
        }
        else {
            if(matched == 0) {
                begin++;
            }
            else {
                begin += matched - next[matched - 1];
                matched = next[matched - 1];
            }
        }
    }

    return false;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    qsort(A, n, sizeof(int), minest);
    qsort(B, n, sizeof(int), minest);

    AT[0] = A[0] + CLOCK_ANGLE - A[n - 1];
    BT[0] = B[0] + CLOCK_ANGLE - B[n - 1];
    for(int i = 1; i < n; i++) {
        AT[i] = A[i] - A[i - 1];
        BT[i] = B[i] - B[i - 1];
    }
    
    printf(kmp(n) ? "possible" : "impossible");
}