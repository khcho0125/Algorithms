#include <string>
#include <vector>
#include<iostream>

using namespace std;

bool sosu[1000000] = {0,};

int solution(int n) {
    int answer = 0, temp;
    for(int i = 2; i <= n; i++) {
        if(!sosu[i]) {
            answer++;
            temp = i + i;
            while(temp <= n) {
                sosu[temp] = true;
                temp += i;
            }
        }
    }
    return answer;
}