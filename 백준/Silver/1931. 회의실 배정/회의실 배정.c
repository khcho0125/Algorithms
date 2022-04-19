#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int start;
    int end;
}List;

int compare(const void *a, const void *b)
{
    List num1 = *(List *)a;
    List num2 = *(List *)b;

    if(num1.end == num2.end) {
        if(num1.start > num2.start) {
            return 1;
        }
        else if(num1.start < num2.start) {
            return -1;
        }
        else {
            return 0;
        }
    }
    
    if(num1.end > num2.end) {
        return 1;
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    List *newList = (List*)malloc(sizeof(List) * n);
    int temp, pre, epre;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &newList[i].start, &newList[i].end);
    }

    qsort(newList, n, sizeof(List), compare);
    
    int result = 0;
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(m <= newList[i].start) {
            m = newList[i].end;
            result++;
        }
    }
    printf("%d", result);
}