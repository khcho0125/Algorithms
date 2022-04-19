#include<stdio.h>
#include<stdlib.h>

int heap[100000] = {0,};

void push(int input, int *cnt) {

    int i = 0;
    i = ++(*cnt);

    while((i != 1) && input > heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = input;
}

int pop(int *cnt) {
    int first, temp, parent, child;
    first = heap[1];
    temp = heap[(*cnt)--];
    parent = 1;
    child = 2;

    while(child <= *cnt) {
        if((child < *cnt) && (heap[child] < heap[child + 1])) {
            child++;
        }

        if(temp >= heap[child]) {
            break;
        }

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }

    heap[parent] = temp;
    return first;
}

int main() {
    
    int n, m;
    int cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        if(m == 0) {
            if(cnt == 0) {
                printf("0\n");
            }
            else printf("%d\n", pop(&cnt));
        }
        else {
            push(m, &cnt);
        }
    }
    return 0;
}