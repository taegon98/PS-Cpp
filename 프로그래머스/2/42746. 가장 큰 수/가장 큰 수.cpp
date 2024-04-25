#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

bool cmp(string& a, string& b) {
    int num_a = stoi(a+b);
    int num_b = stoi(b+a);
    return num_a > num_b;
}

string solution(vector<int> numbers) {
    string answer = "";
    for (auto var : numbers) v.push_back(to_string(var));
    sort(v.begin(), v.end(), cmp);
    for (auto var : v) answer += var;
    
    if (answer[0] == '0') return "0";
    return answer;
}