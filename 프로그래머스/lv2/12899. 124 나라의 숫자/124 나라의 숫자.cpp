#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n) {
    string s = "";
    string arr[] = {"4", "1", "2"};
    
    while(n) {
        int temp = n % 3;
        n /= 3;
        if (temp == 0) {
            s += arr[0];
            n -= 1;
        }
        else {
            s += arr[temp];
        }
    }
    reverse(s.begin(), s.end());
    
    return s;
}