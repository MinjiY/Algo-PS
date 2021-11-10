/*
	[Programmers] ��Ŭ�� ç���� > �Ƿε�
	https://programmers.co.kr/learn/courses/30/lessons/87946

	���� �Ƿε��� ����ؼ� ����Ž�谡��
	
	�� �������� Ž���� �ϱ����� : �ּ� �ʿ� �Ƿε�
	Ž�� ��ģ�� �������� �Ҹ�Ǵ� �Ƿε� : �Ҹ� �Ƿε�

	�Ϸ翡 �ѹ��� Ž�谡���� ������ ������ ����
	������ �� �������� �ִ��� ���� Ž���ؾ���

	������ ���� �Ƿε� k, [�ּ� �ʿ� �Ƿε�, �Ҹ� �Ƿε�] => �������迭

	������ Ž���� �� �ִ� �ִ� ���� ��
*/
#include <iostream>
#include <vector>
using namespace std;

int selected[10];
int visit[10];
int n;						//���� �ִ�
int cur;					//�־��� ���� �Ƿε�
int answer;
int solve(vector<vector<int>> v) {
	int temp = cur;						// ����Ž�� �Ƿε� ������Ʈ�� temp
	for (int i = 0; i < n; ++i) {
		if (temp >= v[selected[i]][0]) { //�ּ� �ʿ� �Ƿε� ����?
			temp -= v[selected[i]][1];   // �Ҹ� �Ƿε� ����
		}
		else {
			//�ּ� �ʿ� �Ƿε� �Ҹ���
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