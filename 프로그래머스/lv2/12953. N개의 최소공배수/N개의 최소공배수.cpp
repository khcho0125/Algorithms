#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(b) return gcd(b, a % b);
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int len = arr.size(), answer = arr[0];
    for(int i = 1; i < len; i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}