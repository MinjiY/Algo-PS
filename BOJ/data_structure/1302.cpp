#include <iostream>
#include <map>
using namespace std;

map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (m.find(s) == m.end()) {
			m[s] = 1;
		}
		else {
			m[s]++;
		}
	}

	map<string, int> ::iterator it;
	int max = 0;
	string ans = "";
	for (it = m.begin(); it != m.end(); ++it) {
		if (it->second > max) {
			max = it->second;
			ans = it->first;
		}
	}
	cout << ans << "\n";


	return 0;
}