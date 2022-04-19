#include<stdio.h>

int heap[100001] = {0,};
int pre = 0;

int abs(int a) {
    return a > 0 ? a : a * -1;
}

void insert(int N) {
    pre++;
    int parent = pre / 2;
    int child = pre;
    int value = abs(N);
    while((parent != 0) && abs(heap[parent]) >= value) {
        if(value == abs(heap[parent]) && N >= heap[parent]) {
            break;
        }
        heap[child] = heap[parent];
        parent /= 2;
        child /= 2;
    }
    heap[child] = N;
}

void pop() {
    printf("%d\n", heap[1]);
    if(pre == 0) {
        return;   
    }
    if(pre == 1) {
        heap[pre--] = 0;
        return;
    }
    int prevalue = heap[pre];
    heap[pre--] = 0;
    int temp = 1;
    int test = 2;
    while(test <= pre) {
        
        if(test + 1 <= pre && (abs(heap[test]) > abs(heap[test + 1])) || (abs(heap[test]) == abs(heap[test + 1]) && heap[test] > heap[test + 1])) {
            test++;
        }

        if(abs(prevalue) < abs(heap[test]) || (abs(prevalue) == abs(heap[test]) && prevalue <= heap[test])) {
            break;
        }

        heap[temp] = heap[test];
        temp = test;
        test = temp * 2;
    }
    heap[temp] = prevalue;
}

int main() {
    int N, input;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input != 0) {
            insert(input);
        }
        else {
            pop();
        }
    }
}