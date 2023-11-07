#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;
char temp;
vector<char> v;

bool check(string s) {
    bool flag1 = false, flag2 = false;
    int cnt = 0;
    for (int i = 0; i < L; i++) {
        if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') {
            flag1 = true;
            break;
        }
    }

    for (int i = 0; i < L; i++) {
        if (s[i] != 'a' and s[i] != 'e' and s[i] != 'i' and s[i] != 'o' and s[i] != 'u') {
            cnt++;
        }
        if (cnt == 2) {
            flag2 = true;
            break;
        }
    }
    if (flag1 and flag2) return true;
    else return false;
}

void go(int depth, int idx, string s) {

    if (depth == L) {
        string temp = s;
        sort(temp.begin(), temp.end());

        if (s == temp) {
            if (check(s))
                cout << s << "\n";
        }
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        go(depth + 1, i + 1, s + v[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    go(0, 0, "");
}