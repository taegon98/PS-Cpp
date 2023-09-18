#include <string>
#include <vector>

using namespace std;
int tot, l;

bool go(int r, int brown) {
    if ((2 * l) + (2 * r) - 4 == brown) return true;
    else return false;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    tot = brown + yellow;
    l = tot;
    
    while(1) {
        if (tot % l == 0) {
            if (go(tot / l, brown)) {
                answer.push_back(l);
                answer.push_back(tot / l);
                break;
            }
        }
        l--;
    }
    return answer;
}