/*
	[Programmers] Ž���(Greedy) > ����Ʈ
	https://programmers.co.kr/learn/courses/30/lessons/42885

	�ѹ��� �ִ� 2��
	����Ʈ�� �ִ��� ���� ����Ͽ� ������� ����
	
	������� ������ �迭 people
	limit
	
	����Ʈ ������ �ּڰ�
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());
	int front = 0;
	int back = people.size() - 1;


	while (front <= back) {
		if (people[front] + people[back] <= limit) {
			front++;
			back--;
		}
		else {
			back--;
		}
		answer++;
	}
	return answer;
}

int main() {
	//[70, 50, 80, 50]
	//[70, 80, 50]
	vector<int> v;
	v.push_back(70);
	v.push_back(50);
	v.push_back(80);
	v.push_back(50);

	cout << solution(v,3) << "\n";
	return 0;
}