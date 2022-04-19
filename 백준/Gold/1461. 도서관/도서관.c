#include<stdio.h>

void Sort(int Array[], int len);
int Group(int Array[], int len, int M);

int main() {
    int arr[50] = {};
    int minarr[50] = {};
    int N, M, idx = 0, minidx = 0;
    int input;
    int result = 0;
    int temp = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        if(input < 0) { // 음수배열에 저장
            input = input * -1;
            minarr[minidx] = input;
            minidx++;
        }
        else { // 양수배열에 저장
            arr[idx] = input;
            idx++;
        }
        if(input > temp) { // 인덱스가 가장 큰 수를 기억
            temp = input;
        }
    }
    Sort(minarr, minidx);
    Sort(arr, idx);

    result += Group(minarr, minidx - 1, M);
    result += Group(arr, idx - 1, M);

    printf("%d", result - temp);
}

void Sort(int Array[], int len) {
    int sup, j;
    for(int i = 1; i < len; i++) {
        sup = Array[i];
        j = i;
        while(sup < Array[j - 1] && j != 0) {
            Array[j] = Array[j - 1];
            j = j - 1;
        }
        Array[j] = sup;
    }
}

int Group(int Array[], int len, int M) {
    int result = 0;
    while(len >= 0) {
        result += Array[len] * 2;
        len -= M;
    }
    return result;
}