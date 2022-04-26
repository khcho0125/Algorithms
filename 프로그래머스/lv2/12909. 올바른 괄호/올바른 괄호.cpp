#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int result = 0;
    
    for(int i = 0; i < s.length() && result >= 0; i++) {
        if(s[i] == '(') {
            result++;
        }
        else {
            result--;
        }
    }

    answer = result != 0 ? false : true;

    return answer;
}