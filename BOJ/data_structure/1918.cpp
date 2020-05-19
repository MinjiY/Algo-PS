/*
    [BOJ] 1918 후위 표기식
    https://www.acmicpc.net/problem/1918
*/
#include <iostream>
#include <vector>
using namespace std;

string str;
vector<char> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> str;
	int i = 0;
	
	while (1) {
		if (i == str.size()) {				//종료조건
			while(v.size() !=0 ) {			//종료전에 스택에 남아있는 연산자 모두 출력
				char c = v.back();
				if (c != '(') {				// ( 는 빼고
					cout << c;
				}
				v.pop_back();
			}
			break;
		}

		if ((str[i] == '*') || (str[i] == '/') || (str[i] == '-') || (str[i] == '+') || (str[i] == '(')|| (str[i] == ')')) {
			//(면 무조건 push
			if (str[i] == '(') {
				v.push_back(str[i]);
			}
			// ) 면 (가 나올때까지 pop
			else if (str[i] == ')') {
				while (v.back() != '(') {				//(가 )를 만날때까지 
					char c = v.back();
					v.pop_back();
					cout << c;
				}
				v.pop_back();		// 남은 (
			}
			// * / 일때
			else if ((str[i] == '*') || (str[i] == '/')) {
				if (v.size() != 0) {					//vector가 비었을때 v.back()하면 런타임에러
					char c = v.back();
					if ((c == '*') || (c == '/')) {		// 같은 우선순위는 pop하고 현재 연산자 push 
						cout << c;
						v.pop_back();
					}
				}										//낮은 우선순위 연산자 - +일 땐 무시하고 push하니까 걍 if밖 push
				v.push_back(str[i]);

			}
			// - + 일때
			else if ((str[i] == '+') || (str[i] == '-')) {
				if (v.size() != 0) {					//vector가 비었을때 v.back()하면 런타임에러
					/*
					char c = v.back();
					if (c == '(') {						//(면 무조건 push
						v.push_back(str[i]);
					
					}
					else {
						while ((v.size() != 0) && (v.back() != '(')) {
							char c = v.back();
							cout << c;
							v.pop_back();
							//++i;
						}
						v.push_back(str[i]);
					}*/
					while ((v.size() != 0) && (v.back() != '(')) {
						char c = v.back();
						cout << c;
						v.pop_back();
						//++i;
					}
					v.push_back(str[i]);
				}
				else {
					v.push_back(str[i]);
					//++i;
				}
			}
			// 공통: vector.back() 같은 우선순위 일때 front빼기	
			++i;

		}
		else {
			cout << str[i++];
		}
	}

	return 0;
}
