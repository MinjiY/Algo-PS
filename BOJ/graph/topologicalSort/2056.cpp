/*
	[BOJ] 2056 작업
	https://www.acmicpc.net/problem/2056
	
	수행해야하는 작업 N개
	각각의 작업마다 걸리는 시간 (1 <= 시간 <= 100)
	K번 작업에 대해 선행 관계에 있는 작업들의 번호는 모두 1이상 (K-1)이하이다.
	작업들 중에는 선행관계에 있는 작업이 하나도 없는 작업이 하나 이상 존재
	
	모든 작업을 완료하기위한 최소 시간 출력

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> adj[10002];
int indeg[10002];
int task_time[10002];

int arr[10002];


int topo_sort() {
	queue<int> q;
	int result = 0;

	for (int i = 1; i <= N; ++i) {
		if (indeg[i] == 0) {
			q.push(i);
			arr[i] = task_time[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			indeg[next]--;
			if (indeg[next] == 0) {
				q.push(next);
			}
			arr[next] = max(arr[next], arr[cur] + task_time[next]);
		}
	}
	for (int i = 1; i <= N; ++i) {
		result = max(result,arr[i]);
	}
	return result;

}

//작업에 걸리는 시간, 선행 관계에 있는 작업들의 갯수, 선행관계 작업 번호
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	for(int i=1; i<=N; ++i){
		int task, num, pretask;
		cin >> task >> num ;
		for (int j = 0; j < num; ++j) {
			cin >> pretask;
			adj[pretask].push_back(i);
			indeg[i]++;
		}
		task_time[i] = task;
	}
	cout<< topo_sort()<<"\n";


	return 0;
}