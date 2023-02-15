#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int N;
	string pattern, file_name, prefix, suffix;

	cin >> N;
	cin >> pattern;

	int pos = pattern.find('*');
	prefix = pattern.substr(0, pos);
	suffix = pattern.substr(pos + 1, pattern.size());

	for (int i = 0; i < N; i++) {
		cin >> file_name;

		if (prefix.size() + suffix.size() > file_name.size()) {
			cout << "NE" << "\n";
		}
		else {
			if (prefix == file_name.substr(0, prefix.size()) and
				suffix == file_name.substr(file_name.size() - suffix.size(), file_name.size()))
				cout << "DA" << "\n";
			else cout << "NE" << "\n";
		}
	}
	
	return 0;
}