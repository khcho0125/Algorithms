#include<iostream>
#include<vector>
#include<string.h>

#define max(a, b)(((a) > (b)) ? a : b)

using namespace std;

int t1[4] = {1, 3, 4, 5};
int t2[5] = {3, 1, 2, 4, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one = 0, two = 0, three = 0, MAX = -1;
    for(int i = 0, c1 = 0, c2 = 0; i < answers.size(); i++) {
        if(i % 5 + 1 == answers[i]) {
            one++;
        }
        if(i % 2 != 1 && answers[i] == 2) {
            two++;
        }
        else if(i % 2 != 0 && answers[i] == t1[c1]) {
            two++;
        }
        if(answers[i] == t2[c2]) {
            three++;
        }
        if(i % 2 == 1) {
            c1++;
            if(c1 == 4) c1 = 0;
            c2++;
            if(c2 == 5) c2 = 0;
        }
    }
    MAX = max(one, max(two, max(three, MAX)));
    if(one == MAX) answer.push_back(1);
    if(two == MAX) answer.push_back(2);
    if(three == MAX) answer.push_back(3);
    return answer;
}