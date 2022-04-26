#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    for(int i : numbers) {
        answer -= i;
    }
    return answer;
}