/*
    [BOJ] 12886 돌 그룹
    https://www.acmicpc.net/problem/12886
 */
#include <iostream>
using namespace std;

/*
	각각의 그룹에는 A, B, C개
	모든 그룹에 있는 돌의 개수를 같게하려고 한다
	1 크기가 같지 않은 돌 두개를 고른다
	2 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y
	3 X에 있는 돌의 갯수를 X+X개, Y에 있는 돌의 갯수를 Y-X개로 만든다
	
	A B C가 주어졌을 때 돌을 같은 갯수로 만들 수 있으면 1, 아니면 0을 출력
*/
#include <queue>
#include <vector>
#include <set>
typedef struct {
	long long A, B, C;
}NODE;

NODE info;
set < pair<pair<long long, long long>, long long>> visit;
bool check(long long a, long long b, long long c) {
	if (a == b) {
		if (b == c) {
			return true;
		}
	}
	return false;
}
bool flag = false;
void bfs() {

	queue<NODE> q;
	q.push({ info.A ,info.B , info.C });
	visit.insert(make_pair(make_pair(info.A, info.B), info.C));
	while (!q.empty()) {
		NODE temp = q.front();
		q.pop();
	//	cout << temp.A <<" "<< temp.B <<" "<< temp.C<<"\n";
		
		if (check(temp.A, temp.B, temp.C)) {
			flag = true;
			break;
		}
		
		if (temp.A > temp.B) {			//작은쪽 X+X, 큰쪽 Y-X
			NODE temp2 = { (temp.A - temp.B), (temp.B + temp.B), temp.C };
			if (visit.find(make_pair(make_pair(temp2.A, temp2.B), temp2.C)) == visit.end()) {

				visit.insert(make_pair(make_pair(temp2.A, temp2.B), temp2.C));
				q.push(temp2);
			}
			
		}
		else if (temp.A < temp.B) {
			NODE temp2 = { (temp.A + temp.A), (temp.B - temp.A), temp.C };
			if (visit.find(make_pair(make_pair(temp2.A, temp2.B), temp2.C)) == visit.end()) {

				visit.insert(make_pair(make_pair(temp2.A, temp2.B), temp2.C));
				q.push(temp2);
			}
		}
		if (temp.B > temp.C) {//작은쪽 X+X, 큰쪽 Y-X
			NODE temp2 = { temp.A, (temp.B - temp.C),(temp.C + temp.C) };
			if (visit.find(make_pair(make_pair(temp2.A, temp2.B), temp2.C)) == visit.end()) {

				visit.insert(make_pair(make_pair(temp2.A, temp2.B), temp2.C));
				q.push(temp2);
			}
		}
		else if (temp.B < temp.C) {
			NODE temp2 = { temp.A, (temp.B + temp.B),(temp.C - temp.B) };
			if (visit.find(make_pair(make_pair(temp2.A, temp2.B), temp2.C)) == visit.end()) {

				visit.insert(make_pair(make_pair(temp2.A, temp2.B), temp2.C));
				q.push(temp2);
			}
		}
		if (temp.C > temp.A) {	//작은쪽 X+X, 큰쪽 Y-X
			NODE temp2 = { (temp.A+temp.A),temp.B,(temp.C-temp.A) };
			if (visit.find(make_pair(make_pair(temp2.A, temp2.B), temp2.C)) == visit.end()) {

				visit.insert(make_pair(make_pair(temp2.A, temp2.B), temp2.C));
				q.push(temp2);
			}
		}
		else if (temp.C < temp.A) {
			NODE temp2 = { (temp.A -temp.C),temp.B,(temp.C +temp.C) };
			if (visit.find(make_pair(make_pair(temp2.A, temp2.B), temp2.C)) == visit.end()) {

				visit.insert(make_pair(make_pair(temp2.A, temp2.B), temp2.C));
				q.push(temp2);
			}
		}
	}
	if (flag)
		cout << "1\n";
	else
		cout << "0\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> info.A >> info.B >> info.C;
	bfs();
	return 0;
}