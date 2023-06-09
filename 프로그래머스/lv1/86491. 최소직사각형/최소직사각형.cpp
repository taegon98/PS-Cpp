#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int y = -987654321, x = -987654321;
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] < sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
    }
    for (int i = 0; i < sizes.size(); i++) {
        y = max(y, sizes[i][0]);
        x = max(x, sizes[i][1]);
    }
    answer = y * x;
    return answer;
}