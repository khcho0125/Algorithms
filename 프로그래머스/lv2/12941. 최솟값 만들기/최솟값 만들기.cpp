#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int& a, int& b) {
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(begin(A), end(A));
    sort(begin(B), end(B), compare);
    
    int size = A.size();
    for(int i = 0; i < size; i++) {
        answer += A[i] * B[i];
    }
    
    return answer;
}