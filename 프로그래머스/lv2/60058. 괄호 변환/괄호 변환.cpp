#include <string>
#include <vector>

using namespace std;

string func(string str) {
    int len = str.length();
    if(len == 0) return "";
    int one = 0, two = 0, cnt = 0;
    bool T = true;
    string temp = "", next = str;
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') {
            one++;
            cnt++;
        }
        else {
            two++;
            cnt--;
        }

        temp += str[i];

        if(cnt < 0) {
            T = false;
        }

        if(one == two) {
            next = next.substr(i + 1, len);
            break;
        }
    }

    if(T) {
        return temp + func(next);
    }
    else {
        string pre = "";
        for(int i = 1; i < temp.length() - 1; i++) {
            if(temp[i] == ')') {
                pre += '(';
            }
            else {
                pre += ')';
            }
        }
        return "(" + func(next) + ")" + pre;
    }
}

string solution(string p) {
    return func(p);
}

