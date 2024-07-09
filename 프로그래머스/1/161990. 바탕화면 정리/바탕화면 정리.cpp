#include <string>
#include <vector>
#include <iostream>
#define INF 987654321
using namespace std;

int min_y = INF, min_x = INF, max_y = -INF, max_x = -INF;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                min_y = min(i, min_y);
                min_x = min(j, min_x);
                max_y = max(i, max_y);
                max_x = max(j, max_x);
            }
        }
    }
    
    answer.push_back(min_y);
    answer.push_back(min_x);
    answer.push_back(max_y + 1);
    answer.push_back(max_x + 1);
    
    return answer;
}