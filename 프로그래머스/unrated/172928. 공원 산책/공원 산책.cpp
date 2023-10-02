#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
int row, col, cur_y, cur_x;
int visited[51][51];
char arr[51][51];

void go(int n, int cnt) {

    int ny = cur_y, nx = cur_x;
    while (cnt) {
        ny += dy[n];
        nx += dx[n];

        if (ny < 0 or nx < 0 or ny >= row or nx >= col or arr[ny][nx] == 'X') return;
        cnt--;
    }
    cur_y = ny;
    cur_x = nx;
    
    return;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    row = park.size();
    col = park[0].size();
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            arr[i][j] = park[i][j];
            if(arr[i][j] == 'S') {
                cur_y = i; cur_x = j;
            }
        }
    }
 
    for (auto var : routes) {
        int temp = var[2] - '0';
        
        if (var[0] == 'E') go(3, temp);
        else if (var[0] == 'W') go(2, temp);
        else if (var[0] == 'S') go(1, temp);
        else if (var[0] == 'N') go(0, temp);
    }
    
    answer.push_back(cur_y);
    answer.push_back(cur_x);
    
    return answer;
}