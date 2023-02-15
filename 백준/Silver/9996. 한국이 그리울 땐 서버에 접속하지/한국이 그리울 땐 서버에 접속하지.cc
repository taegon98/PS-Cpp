#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, idx = 0, flag;
	string pattern, file_name, start, end;

	cin >> N;
	cin >> pattern;

	while (idx != pattern.size() and pattern[idx] != '*') {
		start += pattern[idx++];
	} idx++;

	while (idx != pattern.size() and pattern[idx] != '*') {
		end += pattern[idx++];
	}

	reverse(end.begin(), end.end());

	for (int tc = 0; tc < N; tc++) {
		flag = 0;
		cin >> file_name;

		if (file_name.size() < pattern.size()-1) {
			cout << "NE" << "\n";
			continue;
		}
		
		for (int i = 0; i < start.size(); i++) {
			if (start[i] != file_name[i]) {
				cout << "NE" << "\n";
				flag = 1; break;
			}
		}

		if (flag == 0) {
			for (int i = 0; i < end.size(); i++) {
				if (end[i] != file_name[file_name.size() - i - 1]) {
					cout << "NE" << "\n";
					flag = 1; break;
				}
			}
		}
		
		if (flag == 0)
			cout << "DA" << "\n";
	}
	return 0;
}