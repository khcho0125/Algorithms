#include<iostream>
#include<vector>
#include<sstream>
#include<string.h>
#include<map>

#define ll long long
#define MAX 1000000001LL
#define min(a, b) ((a) < (b) ? a : b)
#define impossible -1

using namespace std;

ll weight[100];
map<string, int> parser;
vector<pair<int, vector<string>>> expression;

vector<string> split(string str, char delimiter) {
    vector<string> result;
    istringstream ss(str);
    string temp;

    while(getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }

    return result;
}

int solve() {
    memset(weight, -1, sizeof(weight));

    int N, M;
    string buffer;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> buffer >> weight[i];
        parser[buffer] = i;
    }

    for(int i = 0; i < M; i++) {
        cin >> buffer;

        vector<string> exp = split(buffer, '=');

        if(parser.find(exp[0]) == parser.end()) parser[exp[0]] = N + i;
        int idx = parser[exp[0]];
        expression.push_back(make_pair(idx, split(exp[1], '+')));
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            pair<int, vector<string>> exp = expression[j];

            ll cost = 0;
            for(auto source : exp.second) {
                int w = source[0] - '0';
                string key = source.substr(1);

                if(parser.find(key) == parser.end() || weight[parser[key]] == impossible) {
                    cost = impossible;
                    break;
                }

                ll temp = min(weight[parser[key]] * w, MAX);
                cost = min(cost + temp, MAX);
            }

            if(cost != impossible && (weight[exp.first] == impossible || cost < weight[exp.first])) {
                weight[exp.first] = cost;
            }
        }
    }

    if(parser.find("LOVE") == parser.end()) return impossible;
    return weight[parser["LOVE"]];
}

int main() {
    printf("%d", solve());
}