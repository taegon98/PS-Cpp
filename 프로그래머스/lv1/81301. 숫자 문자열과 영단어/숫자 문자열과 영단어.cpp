#include <string>
#include <vector>
#include <iostream>
using namespace std;

string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
string num[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int solution(string s) {
    int answer = 0;
  
    for (int i = 0; i < 10; i++) {
        int idx = s.find(arr[i]);
        while(idx != string::npos) {
            s.erase(idx, arr[i].size());
            s.insert(idx, num[i]);
            idx = s.find(arr[i]);
        }
        cout << s << "\n";
    }
    answer = stoi(s);
    return answer;
}