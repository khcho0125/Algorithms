#include <string>
#include <vector>

#define MAX 10000000

using namespace std;

int result = 0;
bool sosu[MAX] = {1, 1, 0};
string str;
int len;
bool visit[7] = {0,};

void tracking(int sum, int next) {
    if(!sosu[sum]) {
        result++;
        sosu[sum] = true;
    }
    for(int i = 0; i < len; i++) {
        if(!visit[i]) {
            visit[i] = true;
            tracking(sum + next * (str[i] - '0'), next * 10);
            visit[i] = false;
        }
    }
}

int solution(string numbers) {
    int temp;
    len = numbers.length();
    str = numbers;
    for(int i = 2; i < MAX; i++) {
        if(!sosu[i]) {
            temp = i + i;
            while(temp < MAX) {
                sosu[temp] = true;
                temp += i;
            }
        }
    }
    
    for(int i = 0; i < len; i++) {
        visit[i] = true;
        tracking(str[i] - '0', 10);
        visit[i] = false;
    }
    
    return result;
}