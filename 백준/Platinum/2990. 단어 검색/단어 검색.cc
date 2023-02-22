#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

typedef struct Trie {
    int count;
    map<char, Trie*> next;
}Trie;

typedef struct Pair {
    int first, second;
}Pair;

Trie database;
map<string, int> number;

string word[30001];
string keyword[30000];

Pair order[30000];

bool compare(const Pair& a, const Pair& b) {
    return a.first < b.first;
}

void insert(Trie* link, int idx, int depth) {

    link->count++;

    if (word[idx][depth] == '\0') {
        return;
    }

    if (link->next.find(word[idx][depth]) == link->next.end()) {
        link->next.insert(make_pair(word[idx][depth], new Trie()));
    }

    insert(link->next[word[idx][depth]], idx, depth + 1);
}

int count(Trie* link, int idx, int depth, int before) {

    int cost = depth * (before - link->count);

    if (keyword[idx][depth] == '\0' || link->next.find(keyword[idx][depth]) == link->next.end()) {
        return cost + (depth + 1) * link->count;
    }

    return count(link->next[keyword[idx][depth]], idx, depth + 1, link->count) + cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> word[i];
        number.insert(make_pair(word[i], i));
    }

    cin >> Q;
    for(int i = 0; i < Q; i++) {
        cin >> keyword[i];

        order[i].first = (number.find(keyword[i]) != number.end() ? number[keyword[i]] : N);

        order[i].second = i;
    }

    sort(order, order + Q, compare);

    int index = 0;
    for(int i = 0; i < Q; i++) {
        while(index < order[i].first) insert(&database, ++index, 0);
        
        order[i].first = order[i].second;

        order[i].second = count(&database, order[i].first, 0, index);
    }

    sort(order, order + Q, compare);

    for(int i = 0; i < Q; i++) {
        cout << order[i].second << '\n';
    }
}