#include<stdio.h>
#include<stdlib.h>

#define swap(a, b, T) {T _value = a; a = b; b = _value;}

typedef struct Array {
    int value, cnt;
}Array;

int arr[1000];
int N;

Array set[1000];
int temp = 0;

int compare(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;

    if(A > B) return 1;
    if(A < B) return -1;
    return 0;
}

int order(int idx) {
    for(int i = idx + 1; i < N; i++) {
        if(set[temp].value == arr[i]) {
            set[temp].cnt++;
            idx++;
            continue;
        }

        set[++temp] = (Array){.value = arr[i], .cnt = 1};
        swap(set[temp], set[temp - 1], Array);
        return i;
    }

    swap(set[temp], set[temp - 1], Array);
    return idx;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    set[temp] = (Array){.value = arr[0], .cnt = 1};
    for(int i = 1; i < N; i++) {
        if (set[temp].value == arr[i]) {
            set[temp].cnt++;
            continue;
        }

        set[++temp] = (Array){.value = arr[i], .cnt = 1};
        if(set[temp - 1].value + 1 == set[temp].value) i = order(i);
    } 

    for(int i = 0; i <= temp; i++) {
        for(int j = 0; j < set[i].cnt; j++) {
            printf("%d ", set[i]);
        }
    }
}