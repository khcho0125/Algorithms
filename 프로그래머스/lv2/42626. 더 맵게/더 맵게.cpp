#include <string>
#include <iostream>
#include <vector>

using namespace std;

int heap[1000001];
int back = 0;

void In(int num) {
    int pre = ++back;
    while(pre != 1 && num < heap[pre / 2]) {
        heap[pre] = heap[pre / 2];
        pre /= 2;
    }
    heap[pre] = num;
}

int Out() {
    if(back == 0) return -1;
    int result = heap[1];
    int last = heap[back--];
    int child = 2;
    while(child <= back) {
        if(child + 1 <= back && heap[child] > heap[child + 1]) {
            child++;
        }

        if(last < heap[child]) {
            break;
        }

        heap[child / 2] = heap[child];
        child *= 2;
    }
    heap[child / 2] = last;

    return result;
}

int solution(vector<int> scoville, int K) {
    int len = scoville.size();
    int one, two = 0, temp;
    for(int i = 0; i < len; i++) {
        In(scoville[i]);
    }

    for(int turn = 0; two != -1; turn++) {
        one = Out();
        if(one >= K) return turn;
        two = Out();
        temp = one + two * 2;
        In(temp);
    }
    
    return -1;
}