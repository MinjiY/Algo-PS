/*
    [BOJ] 16936 나3곱2
    https://www.acmicpc.net/problem/16936
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long arr[101];
vector<long long> map;
vector<long long> adj[101];
vector<long long> list;
//long long arr[101];
bool end_flag=false;
int visit[101];
//adj를 arr의 index로 할 경우에는 visit[101]
//adj를 arr의 변수로 할 경우에는 vector<long long> visit으로 해서 visit처리

void dfs(int indx, int cnt) {
	if (cnt == N - 1) {
		for (int i = 0; i < N; ++i) {
			cout << arr[list[i]] << " ";
		}
		cout << "\n";
		end_flag = true;
		return;
	}

	if (!end_flag) {
		for (int j = 0; j < adj[indx].size(); ++j) {
			int next = adj[indx][j];
		//	cout << "indx: " << indx << "j: " << j << "\n";
			if (!visit[next]) {
				visit[next] = 1;
				list.push_back(adj[indx][j]);
				dfs(next, cnt + 1);
				list.pop_back();
				visit[next] = 0;
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j) continue;
			//각 노드에 대해 뒤에올 수 있는 수를 인접리스트로 만듬
			if ((arr[i] / 3) == arr[j] && arr[i] % 3 == 0)		
			{
				adj[i].push_back(j);
			}
			else if ((arr[i] * 2) == arr[j]) {
				adj[i].push_back(j);
			}

		}
	}

	for (int i = 0; i < N; ++i) {
		visit[i] = 1;
		list.push_back(i);
		dfs(i,0);
		list.pop_back();
		visit[i] = 0;
	}


	return 0;
}