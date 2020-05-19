/*
    [BOJ] 1874 스택수열
    https://www.acmicpc.net/problem/1874
*/

#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int list[100000];
vector<int> v;
vector<char> result;
int N;

int stack_check(int check) {
	int cnt = 0;
	if (v.size() == 0) {
		return 0;
	}
	for (int i = v.size() - 1; i >= 0; --i) {
		if (v[i] == check) {
			return cnt + 1;
		}
		cnt++;
	}
	return 0;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> list[i];
	}

	int i = 0;					//list index
	int num = 1;
	while (i < N) {

		if (!v.empty()) {
			if (v.back() == list[i]) {
				v.pop_back();
				result.push_back('-');
			//	cout << "-" << endl;
				++i;
			}
		}
		int cnt = stack_check(list[i]);
		if (cnt) {
			while (cnt) {
				v.pop_back();
				result.push_back('-');
			//	cout << "-" << endl;
				cnt--;
			}
			++i;
		}
		else if (cnt == 0 && num <= N) {
			v.push_back(num);
			//cout << "+" << endl;
			result.push_back('+');
			++num;
		}
		else if (cnt == 0 && num > N) {
				if (i >= N) {
					continue;
				}
				else {
					result.clear();
					cout << "NO" << endl;
					break;
				}
			}

	}
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << endl;
	}

	return 0;
}
