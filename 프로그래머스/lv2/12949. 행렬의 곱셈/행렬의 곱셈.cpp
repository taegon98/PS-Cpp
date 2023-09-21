#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int r = arr2.size();
    int c = arr2[0].size();
    
    for (int i = 0; i < arr1.size(); i++) {
        vector<int> v;
        for (int j = 0; j < c; j++) {
            int temp = 0;
            for (int k = 0; k < r; k++) {
                temp += (arr1[i][k] * arr2[k][j]);
            }
            v.push_back(temp);
        }
        answer.push_back(v);
    }
    return answer;
}