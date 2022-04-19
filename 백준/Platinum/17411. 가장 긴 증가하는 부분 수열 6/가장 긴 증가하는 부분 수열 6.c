#include<stdio.h>
#include<stdlib.h>

typedef struct backjoon
{
    long long idx;
    long long val;
}tree;

tree seg[4000004] = {0,};
tree input[1000001] = {0,};

int compare(const void* a, const void* b) {
    tree num1 = *(tree*)a;
    tree num2 = *(tree*)b;

    if(num1.val == num2.val) {
        if(num1.idx < num2.idx) {
            return 1;
        }
        else {
            return -1;
        }
    }

    if(num1.val > num2.val) {
        return 1;
    }

    return -1;
}

int compare2(const void* a, const void* b) {
    tree num1 = *(tree*)a;
    tree num2 = *(tree*)b;

    if(num1.idx > num2.idx) {
        return 1;
    }
    else {
        return -1;
    }
}

tree update_sum(tree a, tree b) {
    if(a.val > b.val) return a;
    else if(a.val < b.val) return b;
    else {
        a.idx += b.idx;
        return a;
    }
}

tree update(long long idx, tree k, long long s, long long e, long long node) {
    if(idx < s || idx > e) return seg[node];
    if(s == e) return seg[node] = k;
    long long m = (s + e) / 2;
    tree a = update(idx, k, s, m, node * 2);
    tree b = update(idx, k, m + 1, e, node * 2 + 1);
    seg[node] = update_sum(a, b);
    return seg[node];
}

tree find(long long R, long long s, long long e, long long node) {
    tree x = {0, 0};
    if(R < s || e < 0) return x;
    if(0 <= s && e <= R) return seg[node];
    long long m = (s + e) / 2;
    tree a = find(R, s, m, node * 2);
    tree b = find(R, m + 1, e, node * 2 + 1);
    x = update_sum(a, b);
    return x;
}

int main() {
    long long N, i;
    scanf("%lld", &N);
    for(i = 0; i < N; i++) {
        scanf("%lld", &input[i].val);
        input[i].idx = i + 1;
    }
    qsort(input, N, sizeof(tree), compare);
    for(i = 0; i < N; i++) input[i].val = i + 1;
    qsort(input, N, sizeof(tree), compare2);
    tree temp = {1, 0};
    update(0, temp, 0, N, 1);
    for(i = 0; i < N; i++) {
        temp = find(input[i].val, 0, N, 1);
        temp.val++;
        temp.idx %= 1000000007;
        update(input[i].val, temp, 0, N, 1);
    }
    printf("%lld %lld", seg[1].val, seg[1].idx % 1000000007);
}
