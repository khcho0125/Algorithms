#include <string>
#include <vector>

#define min(a, b) (a < b ? a : b)

using namespace std;

int Xcnt[10], Ycnt[10];

string solution(string X, string Y) {
    string answer = "";
    
    int len = X.size();
    for(int i = 0; i < len; i++) {
        Xcnt[X[i] - '0']++;
    }
    
    len = Y.size();
    for(int i = 0; i < len; i++) {
        Ycnt[Y[i] - '0']++;
    }
    
    for(int i = 0; i < 9; i++) {
        answer.insert(answer.size(), min(Xcnt[9 - i], Ycnt[9 - i]), '9' - i);
    }
    
    int zero = min(Xcnt[0], Ycnt[0]), size = answer.size();
    if(size) {
        answer.insert(size, zero, '0');
    }
    else {
        answer = (zero ? "0" : "-1");
    }
    
    return answer;
}