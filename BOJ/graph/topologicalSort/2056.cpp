/*
	[BOJ] 2056 �۾�
	https://www.acmicpc.net/problem/2056
	
	�����ؾ��ϴ� �۾� N��
	������ �۾����� �ɸ��� �ð� (1 <= �ð� <= 100)
	K�� �۾��� ���� ���� ���迡 �ִ� �۾����� ��ȣ�� ��� 1�̻� (K-1)�����̴�.
	�۾��� �߿��� ������迡 �ִ� �۾��� �ϳ��� ���� �۾��� �ϳ� �̻� ����
	
	��� �۾��� �Ϸ��ϱ����� �ּ� �ð� ���

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

//�۾��� �ɸ��� �ð�, ���� ���迡 �ִ� �۾����� ����, ������� �۾� ��ȣ
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