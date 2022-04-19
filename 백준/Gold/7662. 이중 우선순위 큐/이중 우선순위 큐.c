#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000000

typedef struct Data {
    int value;
    int visitidx;
}data;

data min_queue[MAX];
data max_queue[MAX];

int visit[MAX] = {0,};
int cnt = 0;

int idx = 0, min_delete = 0, max_delete = 0;

void Q_I(int n) {
    int i = idx + 1 - min_delete;
    while((i != 1) && n < min_queue[i / 2].value) {
        min_queue[i].value = min_queue[i / 2].value;
        min_queue[i].visitidx = min_queue[i / 2].visitidx;
        i /= 2;
    }
    min_queue[i].value = n;
    min_queue[i].visitidx = idx;

    i = idx + 1 - max_delete;
    while((i != 1) && n > max_queue[i / 2].value) {
        max_queue[i].value = max_queue[i / 2].value;
        max_queue[i].visitidx = max_queue[i / 2].visitidx;
        i /= 2;
    }
    max_queue[i].value = n;
    max_queue[i].visitidx = idx;
    visit[idx] = 0;
}

void minQ_D() {
    int first, firstidx, temp, tempidx, parent, child;
    first = min_queue[1].value;
    firstidx = min_queue[1].visitidx;
    temp = min_queue[idx - min_delete].value;
    tempidx = min_queue[idx - min_delete].visitidx;
    parent = 1;
    child = 2;

    while (child <= idx - min_delete)
    {
        if((child < idx - min_delete) && (min_queue[child].value > min_queue[child + 1].value)) {
            child++;
        }

        if(temp <= min_queue[child].value) {
            break;
        }

        min_queue[parent].value = min_queue[child].value;
        min_queue[parent].visitidx = min_queue[child].visitidx;
        parent = child;
        child *= 2;
    }
    
    min_queue[parent].value = temp;
    min_queue[parent].visitidx = tempidx;
    min_delete++;

    if(!visit[firstidx]) {
        visit[firstidx] = 1;
        cnt++;

    }
    
}

void maxQ_D() {
    int first, firstidx, temp, tempidx, parent, child;
    first = max_queue[1].value;
    firstidx = max_queue[1].visitidx;
    temp = max_queue[idx - max_delete].value;
    tempidx = max_queue[idx - max_delete].visitidx;
    parent = 1;
    child = 2;

    while (child <= idx - max_delete)
    {
        if((child < idx - max_delete) && (max_queue[child].value < max_queue[child + 1].value)) {
            child++;
        }

        if(temp >= max_queue[child].value) {
            break;
        }

        max_queue[parent].value = max_queue[child].value;
        max_queue[parent].visitidx = max_queue[child].visitidx;
        parent = child;
        child *= 2;
    }
    
    max_queue[parent].value = temp;
    max_queue[parent].visitidx = tempidx;
    max_delete++;

    if(!visit[firstidx]) {
        visit[firstidx] = 1;
        cnt++;
    }
}

int main() {
    char str[2];
    int T, k, n, i, j, pt;
    scanf("%d", &T);
    for(i = 0, idx = 0, min_delete = 0, max_delete = 0, cnt = 0; i < T; i++, idx = 0, min_delete = 0, max_delete = 0, cnt = 0) {
        scanf("%d", &k);
        for(int i = 0; i < k; i++) {
            scanf("%s %d", str, &n);
            if(!strcmp(str, "I")) {
                Q_I(n);
                idx++;
            }
            else {
                if(n == -1) {
                    while(visit[min_queue[1].visitidx] && idx != min_delete) {
                        minQ_D();
                    }
                    if(min_delete != idx)
                        minQ_D();
                }
                else {
                    while(visit[max_queue[1].visitidx] && idx != max_delete) {
                        maxQ_D();
                    }
                    if(max_delete != idx)
                        maxQ_D();
                }
            }
        }
    
        while(visit[max_queue[1].visitidx] && idx != max_delete) {
            maxQ_D();
        }

        while(visit[min_queue[1].visitidx] && idx != min_delete) {
            minQ_D();
        }

        if(idx != cnt) {
            printf("%d %d\n", max_queue[1].value, min_queue[1].value);
        }
        else
        {
            printf("EMPTY\n");
        }
        
        memset(min_queue, 0, sizeof(data) * MAX);
        memset(max_queue, 0, sizeof(data) * MAX);
    }
}