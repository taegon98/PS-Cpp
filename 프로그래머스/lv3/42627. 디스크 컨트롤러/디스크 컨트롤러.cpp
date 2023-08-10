#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
struct compare {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second) return a.first > b.first;
        else return a.second > b.second;
    }
};

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), cmp);
    int answer = 0, pre = jobs[0][0], cur = 1;
    pq.push({jobs[0][0], jobs[0][1]});

    while(pq.size()) {
        int s = pq.top().first;
        int e = pq.top().second;
        pq.pop();
        
        if (s <= pre) {
            answer = answer + e + (pre - s);
            pre = pre + e;
        }
        else {
            answer = answer + e;
            pre = s + e;
        }
        for(;cur < jobs.size(); cur++) {
            if (jobs[cur][0] <= pre) pq.push({jobs[cur][0], jobs[cur][1]});
            else break;
        }
        if (cur < jobs.size() and !pq.size()) {
            pq.push({jobs[cur][0], jobs[cur][1]});
            cur++;
        }
    }
   
    return answer / jobs.size();
}