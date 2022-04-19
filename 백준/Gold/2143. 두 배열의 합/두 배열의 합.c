#include<stdio.h>
#include<stdlib.h>

#define ll long long

int A[1000] = {0,};
int B[1000] = {0,};

ll group1[1000000] = {0,};
ll group2[1000000] = {0,};
int first = 0, second = 0;

int compare(const void* a, const void* b) {
    ll num1 = *(ll*)a;
    ll num2 = *(ll*)b;
    if(num1 > num2) {
        return 1;
    }
    if(num1 < num2) {
        return -1;
    }
    return 0;
}

ll lower(ll* arr, ll x, int end) {
    int min = 1, mid, max = end;
    while(min <= max) {
        mid = (min + max) / 2;
        if(arr[mid - 1] < x) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    return min - 1;
}

ll upper(ll* arr, ll x, int end) {
    int min = 1, mid, max = end;
    while(min <= max) {
        mid = (min + max) / 2;
        if(arr[mid - 1] <= x) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    return min - 1;
}

int main() {
    int N, M, i, j;
    ll result = 0, T, sum;
    scanf("%lld %d", &T, &N);
    for(i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    for(i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    for(i = 0, sum = 0; i < N; i++, sum = 0) {
        for(j = i; j < N; j++) {
            sum += A[j];
            group1[first++] = sum;
        }
    }
    for(i = 0, sum = 0; i < M; i++, sum = 0) {
        for(j = i; j < M; j++) {
            sum += B[j];
            group2[second++] = sum;
        }
    }
    qsort(group1, first, sizeof(ll), compare);
    qsort(group2, second, sizeof(ll), compare);
    for(i = 0; i < first; i++) {
        ll low = lower(group2, T - group1[i], second);
        ll upp = upper(group2, T - group1[i], second);
        result += upp - low;
    }
    printf("%lld", result);
}