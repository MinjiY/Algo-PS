/*
	[Programmers] 탐욕법(Greedy) > 구명보트
	https://programmers.co.kr/learn/courses/30/lessons/42885

	한번에 최대 2명씩
	구명보트를 최대한 적게 사용하여 모든사람을 구출
	
	사람들의 몸무게 배열 people
	limit
	
	구명보트 개수의 최솟값
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