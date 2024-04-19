#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;
vector<pair<int, int>> o, x;
int arr[10][10];
int answer, visited_1[10], visited_2[10];

bool check_o() {
    if (arr[0][0] == 0 and arr[0][1] == 0 and arr[0][2] == 0) return true;
    if (arr[1][0] == 0 and arr[1][1] == 0 and arr[1][2] == 0) return true;
    if (arr[2][0] == 0 and arr[2][1] == 0 and arr[2][2] == 0) return true;
    
    if (arr[0][0] == 0 and arr[1][0] == 0 and arr[2][0] == 0) return true;
    if (arr[0][1] == 0 and arr[1][1] == 0 and arr[2][1] == 0) return true;
    if (arr[0][2] == 0 and arr[1][2] == 0 and arr[2][2] == 0) return true;
    
    if (arr[0][0] == 0 and arr[1][1] == 0 and arr[2][2] == 0) return true;
    if (arr[0][2] == 0 and arr[1][1] == 0 and arr[2][0] == 0) return true;
    
    return false;
}

bool check_x() {
    
    if (arr[0][0] == 1 and arr[0][1] == 1 and arr[0][2] == 1) return true;
    if (arr[1][0] == 1 and arr[1][1] == 1 and arr[1][2] == 1) return true;
    if (arr[2][0] == 1 and arr[2][1] == 1 and arr[2][2] == 1) return true;
    
    if (arr[0][0] == 1 and arr[1][0] == 1 and arr[2][0] == 1) return true;
    if (arr[0][1] == 1 and arr[1][1] == 1 and arr[2][1] == 1) return true;
    if (arr[0][2] == 1 and arr[1][2] == 1 and arr[2][2] == 1) return true;
    
    if (arr[0][0] == 1 and arr[1][1] == 1 and arr[2][2] == 1) return true;
    if (arr[0][2] == 1 and arr[1][1] == 1 and arr[2][0] == 1) return true;
    
    return false;
}

void go(int f, int s, int t) {
    if (f == o.size()) {
        if (s + 1 == x.size() and !check_o()) answer = 1;
        if (s == x.size()) answer = 1;
        cout << "hello1 " <<answer<<"\n";
        return;
    }
    if (s == x.size()) {
        if (f + 1 == o.size() and !check_x()) answer = 1;
        if (f == o.size()) answer = 1;
        cout <<"hello2  " <<answer<<"\n";
        return;
    }
    
    if (t == 0) {
        for (int i = 0; i < o.size(); i++) {
            if (visited_1[i]) continue;
            visited_1[i] = 1;
            arr[o[i].first][o[i].second] = 0;
            go(f + 1, s, 1);
            if (answer == 1) return;
            visited_1[i] = 0;
            arr[o[i].first][o[i].second] = -1;
        }
    }
    else if(t == 1) {
        for (int i = 0; i < x.size(); i++) {
            if (visited_2[i]) continue;
            visited_2[i] = 1;
            arr[x[i].first][x[i].second] = 1;
            go(f, s + 1, 0);
            if (answer == 1) return;
            visited_2[i] = 0;
            arr[x[i].first][x[i].second] = -1;
        }
    }
}

int solution(vector<string> board) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O') o.push_back({i, j});
            else if (board[i][j] == 'X') x.push_back({i, j});
        }
    }
    
    if (o.size() < x.size()) return 0;
    
    memset(arr, -1, sizeof(arr));
    go(0, 0, 0);
    
    if (answer == 1) return answer;
    
    return answer;
}