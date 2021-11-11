/*
	[Programmers] 2018 Summer/Winter Coding > 배달
	https://programmers.co.kr/learn/courses/30/lessons/12978

	양방향
	1번 마을 중에서 K시간 이하로 배달 가능한 마을에서만 주문받음
	
	N: 마을의 갯수
	 K: 음식 배달이 가능한 시간 K
	 road: a출발 b도착 c시간
	 a b를 지나는 도로 여러개가 있을 수 있다.

	 1번 마을에 있는 음식점이 K이하의 시간에 배달이 가능한 마을의 개수를 return
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
	pq.push(make_pair(0, 1));			//1번부터 시작
	dist[1] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;	// 마을간에 경로가 2개 이상인 경우

		
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