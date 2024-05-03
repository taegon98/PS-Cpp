#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int arr[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for (int i = 0; i <= 200; i++) {
        for (int j = 0; j <= 200; j++) {
            arr[i][j] = INF;
        }
    }
    
    for (auto var : fares) {
        arr[var[0]][var[1]] = var[2];
        arr[var[1]][var[0]] = var[2];
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    
    answer = min(answer, arr[s][b] + arr[b][a]);
    answer = min(answer, arr[s][a] + arr[a][b]);
    answer = min(answer, arr[s][a] + arr[s][b]);
    
    for (int i = 1; i <= n; i++) {
        if (i == s or i == a or i == b) continue;
        if (arr[s][i] == INF or arr[i][a] == INF or arr[i][b] == INF) continue;
        answer = min(answer, arr[s][i] + arr[i][a] + arr[i][b]);
    }

    return answer;
}