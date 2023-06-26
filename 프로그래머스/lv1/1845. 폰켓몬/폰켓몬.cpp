#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> mp;
    for (auto var : nums) mp[var]++;
    if (mp.size() <= nums.size() / 2) answer = mp.size();
    else answer = nums.size() / 2;
    return answer;
}