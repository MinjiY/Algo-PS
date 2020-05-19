/*
    [SWEA] 1204 최빈수 구하기
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int T,N=10;
int list[1000];
vector<pair<int,int>> score;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T;
	pair<int, int> temp;
	for (int tc = 0; tc < T; ++tc) {
		int num;
		score.clear();
		memset(list, 0, sizeof(list));
		cin >> num;
		for (int i = 0; i < 1000; ++i) {
			cin >> list[i];
		}
		for (int i = 0; i < 101; ++i) {
			temp.first = 0;
			temp.second = i;
			score.push_back(make_pair(temp.first, temp.second));
		}
		for (int i = 0; i < 1000; ++i) {
			score[list[i]].first++;
		}
		sort(score.begin(),score.end());

		cout <<"#"<<tc+1<<" "<< score[100].second <<"\n";	
	}
	return 0;
}