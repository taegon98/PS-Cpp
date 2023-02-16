#include <iostream>
#include <unordered_map>

using namespace std;

string str[100001];
unordered_map<string, int> name;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	string s;

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> str[i];
		name.insert(make_pair(str[i], i));
	}
	
	for (int i = 1; i <= M; i++) {
		cin >> s;
		if (atoi(s.c_str())) cout << str[atoi(s.c_str())] << "\n";
		else cout << name[s] << "\n";
	}
	return 0;
}