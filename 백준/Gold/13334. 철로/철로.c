#include<stdio.h>
#include<stdlib.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

typedef struct vector {
    int first;
    int second;
}vector;

int Queue[100000];
vector input[100000];
int temp = 0;

int compare(const void* a, const void* b) {
    vector num1 = *(vector*)a;
    vector num2 = *(vector*)b;

    if(num1.second != num2.second) return num1.second > num2.second;
    return num1.first > num2.first;
}

void Q_IN(int p) {
    int index = ++temp;
    while(index != 1 && Queue[index / 2] > p) {
        Queue[index] = Queue[index / 2];
        index /= 2;
    }
    Queue[index] = p;
}

void Q_OUT() {
    int one = Queue[temp--];
    int parent = 1;
    int child = 2;
    while(child <= temp) {
        if(child + 1 <= temp && Queue[child] > Queue[child + 1]) {
            child++;
        }
        
        if(one <= Queue[child]) break;

        Queue[parent] = Queue[child];
        parent = child;
        child *= 2;
    }
    Queue[parent] = one;
}

int main() {
    int N, h, o, L, ans = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &h, &o);
        input[i].first = min(h, o);
        input[i].second = max(h, o);
    }
    scanf("%d", &L);
    qsort(input, N, sizeof(vector), compare);
    for(int i = 0; i < N; i++) {
        if(L < input[i].second - input[i].first) continue;
        Q_IN(input[i].first);
        while(temp != 1 && input[i].second > Queue[1] + L) {
            Q_OUT();
        }
        ans = max(temp, ans);
    }

    printf("%d", ans);
}