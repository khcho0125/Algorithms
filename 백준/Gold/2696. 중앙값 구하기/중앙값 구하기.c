#include<stdio.h>

int center = 0;
int L_heap[5002];
int R_heap[5002];
int L_back = 0;
int R_back = 0;

void L_in(int value) {
    int temp = ++L_back;
    while(temp != 1 && L_heap[temp / 2] < value) {
        L_heap[temp] = L_heap[temp / 2];
        temp /= 2;
    }
    L_heap[temp] = value;
}

void R_in(int value) {
    int temp = ++R_back;
    while(temp != 1 && R_heap[temp / 2] > value) {
        R_heap[temp] = R_heap[temp / 2];
        temp /= 2;
    }
    R_heap[temp] = value;
}

void in(int value) {
    if(value < center) {
        L_in(value);
        return;
    }
    R_in(value);
}

int L_out() {
    int first = L_heap[1];
    int last = L_heap[L_back--];
    int child = 2, parent = 1;
    while(child <= L_back) {
        if(child + 1 <= L_back && L_heap[child + 1] > L_heap[child]) {
            child++;
        }

        if(L_heap[child] < last) {
            break;
        }

        L_heap[parent] = L_heap[child];
        parent = child;
        child *= 2;
    }
    L_heap[parent] = last;
    return first;
}

int R_out() {
    int first = R_heap[1];
    int last = R_heap[R_back--];
    int child = 2, parent = 1;
    while(child <= R_back) {
        if(child + 1 <= R_back && R_heap[child + 1] < R_heap[child]) {
            child++;
        }

        if(R_heap[child] > last) {
            break;
        }

        R_heap[parent] = R_heap[child];
        parent = child;
        child *= 2;
    }
    R_heap[parent] = last;
    return first;
}

int update() {
    if(L_back > R_back) {
        R_in(center);
        center = L_out();
    }

    if(L_back < R_back) {
        L_in(center);
        center = R_out();
    }

    return center;
}

int main() {
    int T, M, value;
    scanf("%d", &T);
    for(int tc = 0; tc < T; tc++) {
        scanf("%d", &M);
        printf("%d\n", M / 2 + 1);
        for(int i = 1; i <= M; i++) {
            scanf("%d", &value);
            if(i == 1) center = value; 
            else in(value);

            if(i % 20 == 0) printf("\n");
            if(i % 2) {
                printf("%d ", update());
            }
        }
        printf("\n");

        R_back = 0;
        L_back = 0;
    }
}