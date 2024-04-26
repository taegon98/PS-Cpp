#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int r, c, temp;
deque<int> dq;

void go() {
    while(dq.size() > 1) {
        int a = dq.front(); dq.pop_front();
        int b = dq.front(); dq.pop_front();
        dq.push_back(a^b);
    }
}

bool cmp(vector<int>& a, vector<int>& b) {
    if (a[c] == b[c]) {
        return a[0] > b[0];
    }
    return a[c] < b[c];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    c = col - 1;
    r = data[0].size();
    
    sort(data.begin(), data.end(), cmp);
    
    for (int i = row_begin - 1; i < row_end; i++) {
        for (int j = 0; j < r; j++) {
            temp += (data[i][j] % (i + 1));
        }
        dq.push_back(temp);
        temp = 0;
    }
    
    go();
    
    return dq.front();
}