#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

typedef struct Data {
    int value;
    int idx;
}data;

data arr[MAX];
int Rank[MAX] = {0,};

int compare(const void *a, const void *b) {

    data num1 = *(data *)a;
    data num2 = *(data *)b;

    if(num1.value < num2.value) {
        return -1;
    }

    if(num1.value > num2.value) {
        return 1;
    }

    return 0;
}

int main() {
    int n, pre, temp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].idx = i;
    }
    qsort(arr, n, sizeof(data), compare);
    for(int i = 1; i < n; i++) {
        if(arr[i].value == arr[i - 1].value) {
            Rank[arr[i].idx] = Rank[arr[i - 1].idx];
        }
        else {
            Rank[arr[i].idx] = Rank[arr[i - 1].idx] + 1;
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", Rank[i]);
    }
}