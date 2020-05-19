/*
    [BOJ] 17140 이차원 배열과 연산
    https://www.acmicpc.net/problem/17140
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[102][102];
struct NODE{
	int cnt;
	int num;
};
void printMap() {
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
bool cmp(NODE p1, NODE p2) {
	if (p1.cnt < p2.cnt) {
		return true;
	}
	else if (p1.cnt == p2.cnt) {
		if (p1.num < p2.num) {
			return p1.num<p2.num;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

int maxM() {		//최대 열의 갯수
	int MAX = 0;
	int cnt = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (map[i][j]) {
				cnt++;
			}
			else {
				break;
			}
		}
		if (MAX < cnt) {
			MAX = cnt;
		}
		cnt = 0;
	}
	return MAX;
}
int maxN() {		//최대 행의 갯수
	int MAX = 0;
	int cnt = 0;
	for (int j = 0; j < 100; ++j) {
		for (int i = 0; i < 100; ++i) {
			if (map[i][j]) {
				cnt++;
			}
			else {
				break;
			}
		}
		if (MAX < cnt) {
			MAX = cnt;
		}
		cnt = 0;
	}
	return MAX;
}
void calR(int n , int m) {					//행의 갯수, 열의 갯수
	for (int i = 0; i < n; ++i) {
		bool check[102] = { 0, };
		vector<NODE> temp;
		int cnt = 1;
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 0) {
				continue;
			}
			if (check[map[i][j]] == 0 ) {
				
				check[map[i][j]] = 1;
				for (int k = 0; k < m; ++k) {
					if (j == k) continue;
					if (map[i][j]== map[i][k]) {
						check[map[i][k]] = 1;
						cnt++;
					}
				}
				temp.push_back({ cnt,map[i][j] });
				cnt = 1;
			}
		}
		int indx = 0;
		sort(temp.begin(), temp.end(), cmp);
		while (1) {
			for (int j = 0; j < temp.size(); ++j) {
				map[i][indx++] = temp[j].num;
				map[i][indx++] = temp[j].cnt;
				if (indx >= 100) {
					break;
				}
			}
			while (indx < m) {
				map[i][indx++] = 0;
			}
			break;
		}

	}
}
void calL(int n, int m) {	//행의 갯수, 열의 갯수
	for (int j = 0; j < m; ++j) {
		bool check[102] = { 0, };
		vector<NODE> temp;
		int cnt = 1;
		for (int i = 0; i < n; ++i) {
			if (map[i][j] == 0) {
				continue;
			}
			if (check[map[i][j]] == 0) {

				check[map[i][j]] = 1;
				for (int k = 0; k < n; ++k) {
					if (i == k) continue;
					if (map[i][j] == map[k][j]) {
						check[map[k][j]] = 1;
						cnt++;
					}
				}
				temp.push_back({ cnt,map[i][j] });
				cnt = 1;
			}
		}
		int indx = 0;
		sort(temp.begin(), temp.end(), cmp);

		while (1) {
			for (int i = 0; i < temp.size(); ++i) {
				map[indx++][j] = temp[i].num;
				map[indx++][j] = temp[i].cnt;
				if (indx >= 100) {
					break;
				}
			}
			while (indx < n) {
				map[indx++][j] = 0;
			}
			break;
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int r, c, k;
	cin >> r >> c >> k;
	r -= 1;
	c -= 1;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> map[i][j];
		}
	}
	int cnt = 0;
	while (cnt <= 100) {
		if (map[r][c] == k) {
			break;
		}
		//R연산인지 C연산인지 결정
		//행 사이즈부터 비교
		int n = maxN();				//최대 행의 갯수
		int m = maxM();				//최대 열의 갯수
		if (n < m) {
		//	cout << "C연산\n";
			calL(n, m);
		//	printMap();
		}
		else if (n >= m) {
		//	cout << "R연산\n";
			calR(n,m);
		//	printMap();
		}
		cnt++;
	}
	if (cnt <= 100) {
		cout << cnt << "\n";
	}
	else {
		cout << "-1\n";
	}
	return 0;
}