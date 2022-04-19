#include<stdio.h>
#include<stdlib.h>

#define ll long long

typedef struct jewel {
    int weight;
    int price;
}jewel;

int bag[300000];
jewel Queue[300001];
jewel Jewel[300000];
int pre = 1;

int compare(const void* a, const void* b) {
    jewel num1 = *(jewel*)a;
    jewel num2 = *(jewel*)b;

    if(num1.weight > num2.weight) {
        return 1;
    }

    if(num1.weight < num2.weight) {
        return -1;
    }

    return 0;
}

int compare2(const void* a, const void* b) {
    int num1 = *(int*)a;
    int num2 = *(int*)b;

    if(num1 > num2) {
        return 1;
    }
    
    if(num1 < num2) {
        return -1;
    }

    return 0;
}

void Q_I(jewel* J) {
    int idx = pre++;
    while((idx != 1) && Queue[idx / 2].price < J->price) {
        Queue[idx].price = Queue[idx / 2].price;
        Queue[idx].weight = Queue[idx / 2].weight;
        idx = idx / 2;
    }
    Queue[idx].weight = J->weight;
    Queue[idx].price = J->price;
}

jewel* Q_O() {
    jewel* first = (jewel*)malloc(sizeof(jewel));
    first->weight = Queue[1].weight;
    first->price = Queue[1].price;
    int tempW = Queue[--pre].weight;
    int tempP = Queue[pre].price;
    int child = 2, parent = 1;
    while(child <= pre) {
        if(child + 1 < pre && (Queue[child].price < Queue[child + 1].price || (Queue[child].price == Queue[child + 1].price && Queue[child].weight < Queue[child + 1].weight))) {
            child++;
        }
            
        if(tempP > Queue[child].price || (tempP == Queue[child].price && tempW < Queue[child].weight)) {
            break;
        }

        Queue[parent].price = Queue[child].price;
        Queue[parent].weight = Queue[child].weight;
        parent = child;
        child *= 2;
    }
    Queue[parent].weight = tempW;
    Queue[parent].price = tempP;
    return first;
}

int main() {
    int N, K, W, P;
    ll result = 0;
    jewel* temp = (jewel*)malloc(sizeof(jewel));
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &Jewel[i].weight, &Jewel[i].price);
    }
    for(int i = 0; i < K; i++) {
        scanf("%d", &bag[i]);
    }
    qsort(Jewel, N, sizeof(jewel), compare);
    qsort(bag, K, sizeof(int), compare2);
    for(int i = 0, j = 0; i < K; i++) {

        for(; j < N && bag[i] >= Jewel[j].weight; j++) {
            Q_I(&Jewel[j]);
        }

        if(pre != 1) {
            temp = Q_O();
            result += temp->price;
        }
    }
    printf("%lld", result);
}