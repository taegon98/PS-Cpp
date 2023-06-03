#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0, y = 0;
    
   for (int i = 0; i < s.size(); i++) {
       if (s[i] == 'p' or s[i] == 'P') p++;
       else if (s[i] == 'y' or s[i] == 'Y') y++;
   }
    if (p != y) answer = false;

    return answer;
}