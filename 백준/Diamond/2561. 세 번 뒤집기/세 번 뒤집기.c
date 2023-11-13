#include<stdio.h>
#include<stdbool.h>

#define N_MAX 1001

#define min(a, b) ((a) < (b) ? a : b)
#define max(a, b) ((a) > (b) ? a : b)
#define swap(a, b) {int sw_temp = a; a = b; b = sw_temp;}

typedef struct Pair {
    int i, j;
}P;

int tb[N_MAX];
int right[N_MAX];
int left[N_MAX];
P result[3];

P findRange(int s, int e, int* array) {
    P result = (P){.i = s, .j = e};
    while(result.i < result.j && result.i == array[result.i]) result.i++;
    while(result.i < result.j && result.j == array[result.j]) result.j--;
    return result;
}

bool isAnswer(int s, int e, int* array) {
    for(int i = s; i <= e && i == array[i]; i++) 
        if(i == e) return true;
    return false;
}

void flip(int s, int e, int* array) {
    for(; s < e; s++, e--) swap(array[s], array[e]);
}

bool twice_flip(int s, int e, int N, int* arr) {
    for(int i = s; i <= e; i++) {
        tb[arr[i]] = i;
        right[i] = left[i] = arr[i];
    }

    P range = findRange(s, e, arr);
    flip(range.i, tb[range.i], left);

    P next = findRange(range.i, range.j, left);
    flip(next.i, next.j, left);

    if(isAnswer(range.i, range.j, left)) {
        result[1] = (P){.i = range.i, .j = tb[range.i]};
        result[2] = (P){.i = next.i, .j = next.j};
        return true;
    }

    flip(tb[range.j], range.j, right);

    next = findRange(range.i, range.j, right);
    flip(next.i, next.j, right);

    if(isAnswer(range.i, range.j, right)) {
        result[1] = (P){.i = tb[range.j], .j = range.j};
        result[2] = (P){.i = next.i, .j = next.j};
        return true;
    }

    return false;
}

void bruteforce(int N, int* arr) {
    P range = findRange(1, N, arr);
    for(int k = range.i; k <= range.j - 1; k++) {
        for(int i = 1; k - i >= range.i && k + i <= range.j; i++) {
            swap(arr[k - i], arr[k + i]);
            if(twice_flip(range.i, range.j, N, arr)) {
                result[0] = (P){.i = k - i, .j = k + i};
                return;
            }
        }

        for(int i = 1; k - i >= range.i && k + i <= range.j; i++) {
            swap(arr[k - i], arr[k + i]);
        }

        for(int i = 0; k - i >= range.i && k + 1 + i <= range.j; i++) {
            swap(arr[k - i], arr[k + 1 + i]);
            if(twice_flip(range.i, range.j, N, arr)) {
                result[0] = (P){.i = k - i, .j = k + 1 + i};
                return;
            }
        }

        for(int i = 0; k - i >= range.i && k + 1 + i <= range.j; i++) {
            swap(arr[k - i], arr[k + 1 + i]);
        }
    }
}

int arr[N_MAX];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    result[0] = result[1] = result[2] = (P){.i = 1, .j = 1};
    bruteforce(N, arr);

    for(int t = 0; t < 3; t++) {
        printf("%d %d\n", result[t].i, result[t].j);
    }
}