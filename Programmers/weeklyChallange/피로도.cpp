/*
	[Programmers] 위클리 챌린지 > 피로도
	https://programmers.co.kr/learn/courses/30/lessons/87946

	일정 피로도를 사용해서 던전탐험가능
	
	각 던전마다 탐험을 하기위한 : 최소 필요 피로도
	탐험 마친을 마쳤을때 소모되는 피로도 : 소모 피로도

	하루에 한번씩 탐험가능한 던전이 여러개 있음
	유저가 이 던전들을 최대한 많이 탐험해야함

	유저의 현재 피로도 k, [최소 필요 피로도, 소모 피로도] => 이차원배열

	유저가 탐험할 수 있는 최대 던전 수
*/
#include <iostream>
#include <vector>
using namespace std;

int selected[10];
int visit[10];
int n;						//수열 최대
int cur;					//주어진 현재 피로도
int answer;
int solve(vector<vector<int>> v) {
	int temp = cur;						// 던전탐험 피로도 업데이트용 temp
	for (int i = 0; i < n; ++i) {
		if (temp >= v[selected[i]][0]) { //최소 필요 피로도 만족?
			temp -= v[selected[i]][1];   // 소모 피로도 깎임
		}
		else {
			//최소 필요 피로도 불만족
			return i;
		}
	}
	return n;
}

void permutation(int cnt, vector<vector<int>> v) {
	if (cnt == n) {
		int cal_term = solve(v);
		if (answer < cal_term) {
			answer = cal_term;
		}
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (visit[i] == 0) {
			visit[i] = 1;
			selected[cnt] = i;
			permutation(cnt + 1, v);
			visit[i] = 0;
		}
	}
}

int solution(int k, vector<vector<int>> v) {
	n = v.size();
	cur = k;
	
	permutation(0,v);
	return answer;
}

int main() {
	//[[80,20],[50,40],[30,10]]
	vector<vector<int>> v;
	vector<int> temp;
	temp.push_back(80);
	temp.push_back(20);
	v.push_back(temp);
	temp.clear();

	temp.push_back(50);
	temp.push_back(40);
	v.push_back(temp);
	temp.clear();

	temp.push_back(30);
	temp.push_back(10);
	v.push_back(temp);
	temp.clear();
	cout << solution(80, v);

	return 0;
}