/*
	[Programmers] 2018 Summer/Winter Coding > ���
	https://programmers.co.kr/learn/courses/30/lessons/12978

	�����
	1�� ���� �߿��� K�ð� ���Ϸ� ��� ������ ���������� �ֹ�����
	
	N: ������ ����
	 K: ���� ����� ������ �ð� K
	 road: a��� b���� c�ð�
	 a b�� ������ ���� �������� ���� �� �ִ�.

	 1�� ������ �ִ� �������� K������ �ð��� ����� ������ ������ ������ return
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> adj[52];
int visit[52][52];
int dist[52];
const int INF = 1e9;

void dijkstra() {
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));			//1������ ����
	dist[1] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;	// �������� ��ΰ� 2�� �̻��� ���

		
		for (int i = 0; i < adj[node].size(); ++i) {
			int next = adj[node][i].first;
			int nCost = adj[node][i].second;

			if (dist[next] > dist[node] + nCost ) {
				dist[next] = dist[node] + nCost;
				pq.push(make_pair(-dist[next], next));
			}	
		}

	}
	return;
}

int solution(int N, vector<vector<int> > road, int K)
{

	fill(dist, dist + N + 1, INF);
	for (int i = 0; i < road.size(); ++i) {
		int a = road[i][0];
		int b = road[i][1];
		int c = road[i][2];

		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a, c));
	}
	dijkstra();
	int answer = 0;
	for (int i = 1; i <= N; ++i) {
		if (dist[i] <= K) {
			answer++;
		}
	}
	return answer;
}
int main() {

	
	return 0;
}