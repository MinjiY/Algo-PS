/*
    [BOJ] 1525 퍼즐
    https://www.acmicpc.net/problem/1525
 */
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int TARGET = 123456789;

const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int start = 0;		//index

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int num;
			cin >> num;

			if (num == 0)
				num = 9;
			start = start * 10 + num;

		}
	}
	//시작 하는 숫자리스트 start

	queue<int> q;
	map<int, int> visit;
	q.push(start);
	visit[start] = 0;

	while (!q.empty()) {
		int cur = q.front();
		string s = to_string(cur);
		q.pop();

		if (cur == TARGET)
			break;

		//9가 있는 인덱스를 찾고
		int z = s.find('9');
		
		//좌표계산
		int y = z / 3;
		int x = z % 3;

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
			{
				string temp = s;
				swap(temp[y * 3 + x], temp[ny * 3 + nx]);

				int next = stoi(temp);
				if (!visit.count(next)) {		//next라는 key값에 해당하는 원소들의 갯수반환
					visit[next] = visit[cur] + 1;
					q.push(next);
				}
			}
		}
	}

	if (!visit.count(TARGET)) {
		cout << "-1\n";
	}
	else {
		cout << visit[TARGET] << "\n";
	}

	return 0;
}