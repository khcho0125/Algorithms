#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    for(int i = 0; i < n; i++) {
        if(i % 2) answer.append("박");
        else answer.append("수");
    }
    return answer;
}