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

int find(int start, int end, int s, int e, int index) {
    if(end < s || e < start) return -1;
    if(s <= start && end <= e) return tree[index];
    int mid = (start + end) / 2;
    int one = find(start, mid, s, e, index * 2);
    int two = find(mid + 1, end, s, e, index * 2 + 1);
    if(one == -1) return two;
    if(two == -1) return one;
    return compare(one, two);
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
    int M, num, i, j;
    scanf("%d", &N);
    for(int n = 1; n <= N; n++) {
        scanf("%lld", &array[n]);
    }
    segment(1, N, 1);
    scanf("%d", &M);
    for(int m = 0; m < M; m++) {
        scanf("%d %d", &num, &i);
        if(num == 1) {
            scanf("%lld", &array[i]);
            update(1, N, i, 1);
        }
        else {
            scanf("%d", &j);
            printf("%d\n", find(1, N, i, j, 1));
        }
    }
}