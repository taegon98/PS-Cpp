#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        char temp1[16], temp2[16];
        for (int j = n - 1; j >= 0; j--) {
            temp1[j] = (arr1[i] % 2) + '0';
            temp2[j] = (arr2[i] % 2) + '0';
            arr1[i] /= 2; arr2[i] /= 2;
        }
        string temp = "";
        for (int k = 0; k < n; k++) {  
            if (temp1[k] == '1' or temp2[k] == '1') temp += "#";
            else if (temp1[k] == '0' and temp2[k] == '0') temp += " ";
        }
        
        answer.push_back(temp);
    }
    return answer;
}