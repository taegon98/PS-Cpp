#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int N, M, ret;
unordered_map<string, int> mp;
vector<string> v;
string s;

void split(string str) {
    v.clear();
    char delimiter = ',';
    int idx;

    while ((idx = str.find(delimiter)) != string::npos) {
        v.push_back(str.substr(0, idx));
        str = str.substr(idx + 1);
    }
    v.push_back(str);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    ret = N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        mp[s]++;
    }

    for (int i = 0; i < M; i++) {
        cin >> s;
        split(s);

        for (auto var : v) {
            if (mp.find(var) != mp.end()) {
                mp.erase(var);
                ret--;
            }
        }
        cout << ret << "\n";
    }
}