#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>
using namespace std;
set<int> s;
int psum[1001];

int solution(vector<int> elements) {
    int answer = 0;
    
    for (int i = 1; i <= elements.size(); i++) {
        psum[i] = psum[i - 1] + elements[i - 1];
    }

    for (int i = 1; i <= elements.size(); i++) {
        int l = 0, r = i;
        for (int j = 0; j < elements.size(); j++) {
            if (r < l) s.insert(abs(psum[elements.size()] - psum[l]) + psum[r]);
            else s.insert(abs(psum[r] - psum[l]));
            r = (r + 1) % (elements.size() + 1);
            l = (l + 1) % (elements.size() + 1);
            if (!r) r = 1;
            if (!l) l = 1;
        }
    }
    answer = s.size();
    return answer - 1;
}