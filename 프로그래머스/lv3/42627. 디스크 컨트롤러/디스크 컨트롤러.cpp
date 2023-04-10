#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

bool taskComp(const vector<int> &A, const vector<int> &B) {
    return A[0] < B[0];
}

class Schedule {
    public: bool operator()(const pair<int, int> &A, const pair<int, int> &B) {
        return A.second > B.second;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), taskComp);

    priority_queue<pair<int, int>, vector<pair<int, int>>, Schedule> queue;

    int tasktime = 0, current = 0, temp = 0;
    for(int i = 0; i < jobs.size(); i++) {
        while(temp != jobs.size() && (current >= jobs[temp][0] || queue.empty())) {
            if (current < jobs[temp][0]) current = jobs[temp][0];
            queue.push(make_pair(jobs[temp][0], jobs[temp][1]));
            temp++;
        }

        pair<int, int> value = queue.top();

        current += value.second;
        tasktime += current - value.first;

        queue.pop();
    }
    

    return tasktime / jobs.size();
}