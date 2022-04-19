#include<stdio.h>

#define ll long long

int tree[400004];
ll array[100001];
int N;

int compare(int a, int b) {
    if(array[a] == array[b]) return (a < b ? a : b);
    return (array[a] > array[b] ? b : a);
}

int segment(int start, int end, int index) {
    if(start == end) return tree[index] = end;

    int mid = (start + end) / 2;
    int one = segment(start, mid, index * 2);
    int two = segment(mid + 1, end, index * 2 + 1);
    tree[index] = compare(one, two);
    return tree[index];
} 

void update(int start, int end, int i, int index) {
    if(start > i || end < i) return;
    if(start == end) return;  
    int mid = (start + end) / 2;
    update(start, mid, i, index * 2);
    update(mid + 1, end, i, index * 2 + 1);
    tree[index] = compare(tree[index * 2], tree[index * 2 + 1]);
}

int main() {
    ll v;
    int M, num, i;
    scanf("%d", &N);
    for(int n = 1; n <= N; n++) {
        scanf("%lld", &array[n]);
    }
    segment(1, N, 1);
    scanf("%d", &M);
    for(int m = 0; m < M; m++) {
        scanf("%d", &num);
        if(num == 1) {
            scanf("%d %lld", &i, &v);
            array[i] = v;
            update(1, N, i, 1);
        }
        else {
            printf("%d\n", tree[1]);
        }
    }
}