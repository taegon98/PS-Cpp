#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int p1 = 0, p2 = 0;
    bool ok = true;
    for (auto var : goal) {
        if (p1 < cards1.size() and var == cards1[p1]) p1++;
        else if (p2 < cards2.size() and var == cards2[p2]) p2++;
        else {
            ok = false;
            break;
        }
    }
    if (ok) answer = "Yes";
    else answer = "No";
    
    return answer;
}