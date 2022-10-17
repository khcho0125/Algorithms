#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool idx = true;
    for(int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            idx = true;
            continue;
        }
        
        if(s[i] >= 'A' && s[i] <= 'Z' && !idx) s[i] += 32;
        if(s[i] >= 'a' && s[i] <= 'z' && idx) s[i] -= 32;
        idx = !idx;
    }
    return s;
}