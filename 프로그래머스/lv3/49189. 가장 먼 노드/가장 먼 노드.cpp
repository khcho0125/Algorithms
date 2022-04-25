#include <string>
#include <vector>
#include <iostream>

#define INF 987654321

using namespace std;

typedef struct Queue {
    int v, w;
}Q;

int dist[20001];
vector<int> E[20001];
Q PriorityQueue[100000];
int pre = 0;

void Q_I(int v, int w) {
    int temp = ++pre;
    while(temp != 1 && PriorityQueue[temp].w < PriorityQueue[temp / 2].w) {
        PriorityQueue[temp] = PriorityQueue[temp / 2];
        temp /= 2;
    }
    PriorityQueue[temp] = {v, w};
}

Q Q_O() {
    Q first = PriorityQueue[1];
    Q temp = PriorityQueue[pre--];
    int child = 2, parent = 1;
    while(child <= pre) {
        if(child + 1 <= pre && PriorityQueue[child].w > PriorityQueue[child + 1].w) {
            child++;
        }

        if(temp.w < PriorityQueue[child].w) {
            break;
        }

        PriorityQueue[parent] = PriorityQueue[child];
        parent = child;
        child *= 2;
    }
    PriorityQueue[parent] = temp;
    return first;
}

int dijkstra(int n) {
    Q element;
    int result = 0, cnt = 0, v, w;
    while(pre != 0) {
        element = Q_O();
        v = element.v;
        w = element.w;
        for(int i = 0; i < E[v].size(); i++) {
            if(dist[E[v][i]] > w + 1) {
                dist[E[v][i]] = w + 1;
                Q_I(E[v][i], w + 1);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(cnt < dist[i]) {
            cnt = dist[i];
            result = 1;
        }
        else if(cnt == dist[i]) {
            result++;
        }
    }
    return result;
}

int solution(int n, vector<vector<int>> edge) {
    int result = 0, a, b, len = edge.size();
    vector<int> v;
    for(int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    for(int i = 0; i < len; i++) {
        v = edge[i];
        a = v.front();
        b = v.back();
        E[a].push_back(b);
        E[b].push_back(a);
    }
    Q_I(1, 0);
    dist[1] = 0;
    result = dijkstra(n);
    return result;
}