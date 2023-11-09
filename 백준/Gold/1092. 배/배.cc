#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, ret, temp, arr[51];
vector<int> crane, box;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        crane.push_back(temp);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        box.push_back(temp);
    }

    sort(crane.rbegin(), crane.rend());
    sort(box.rbegin(), box.rend());

    while (1) {
        ret++;
        int i = 0, j = 0;
        if (box[box.size() - 1] > crane[0]) {
            cout << -1;
            exit(0);
        }
        for (; i < N; i++) {
            for (; j < box.size(); j++) {
                if (box[j] <= crane[i]) {
                    box.erase(box.begin() + j);
                    break;
                }
            }
            if (!box.size()) {
                cout << ret;
                exit(0);
            }
        }
    }
}