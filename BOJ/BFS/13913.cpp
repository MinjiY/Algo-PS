/*
    [BOJ] 13913 숨바꼭질4
    https://www.acmicpc.net/problem/13913
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;

int visit[100001];
int list[100001];
int index;
vector<int> v;
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ans = 1e9;
	pair<int, int> temp;

	cin >> N >> K;

	q.push(make_pair(N, 0));
	visit[N] = 1;

	while (!q.empty()) {
		temp = q.front();			//first: N second: cnt
		q.pop();

		if (temp.first == K) {
			//cout << "temp.first: " << temp.first<<"\n";
			index = temp.first;
			while (index != N) {
				v.push_back(index);
				index = list[index];
			}
			v.push_back(N);
			
			ans = min(temp.second,ans);
			break;
		}

		if (((temp.first - 1) >= 0) && (!visit[temp.first - 1])) {
		//	cout <<"temp.first - 1: " <<temp.first - 1<<" cnt: "<<temp.second<<"\n";
			visit[temp.first - 1] = 1;
			list[temp.first - 1] = temp.first;
			q.push(make_pair(temp.first - 1, temp.second + 1));
		}
		if (((temp.first + 1) < 100001) && (!visit[temp.first + 1])) {
		//	cout <<"temp.first + 1: " <<temp.first + 1 << " cnt: " << temp.second << "\n";
			visit[temp.first + 1] = 1;
			list[temp.first + 1] = temp.first;
			q.push(make_pair(temp.first + 1, temp.second + 1));
		}
		if (((temp.first * 2) < 100001) && (!visit[temp.first * 2])) {
		//	cout <<"temp.first *2: " <<temp.first *2 << " cnt: " << temp.second << "\n";
			visit[temp.first * 2] = 1;
			list[temp.first*2] = temp.first;
			q.push(make_pair(temp.first * 2, temp.second + 1));
		}

	}

	cout << ans<<"\n";
	for (int i = v.size()-1; i>=0; --i) {
		cout << v[i] << " ";
	}

	return 0;
}