#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool num[200] = {0,};

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(!num[numbers[i] + numbers[j]]) {
                num[numbers[i] + numbers[j]] = true;
                answer.push_back(numbers[i] + numbers[j]);
            }
        }
    }
    sort(begin(answer), end(answer));
    return answer;
}