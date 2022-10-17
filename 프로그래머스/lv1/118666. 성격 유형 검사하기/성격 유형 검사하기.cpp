#include <string>
#include <vector>

using namespace std;

int list[27];
string element[4] = {"RT","CF","JM","AN"};

bool compare(const char& a, const char& b) {
    if (list[a - 'A'] != list[b - 'A']) return list[a - 'A'] > list[b - 'A'];
    return a < b;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int len = choices.size();
    for(int i = 0; i < len; i++) {
        if(choices[i] < 4) list[survey[i][0] - 'A'] += 4 - choices[i];
        else list[survey[i][1] - 'A'] += choices[i] - 4;
    }

    for(string s : element) {
        if(compare(s[0], s[1])) answer += s[0];
        else answer += s[1];
    }

    return answer;
}