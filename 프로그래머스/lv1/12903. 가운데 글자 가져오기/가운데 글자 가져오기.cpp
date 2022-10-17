#include <string>
#include <vector>
#include <string>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    if(len % 2 == 0) answer += s[len / 2 - 1];
    answer += s[len / 2];
    return answer;
}