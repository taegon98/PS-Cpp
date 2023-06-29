#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for (int i = 1; i < food.size(); i++) {
        if (food[i] <= 1) continue;
        for (int j = 0; j < food[i] / 2; j++) 
            temp += to_string(i);
    } 
    answer = temp + "0" + temp;
    reverse(answer.begin() + temp.size() + 1, answer.end());
    return answer;
}