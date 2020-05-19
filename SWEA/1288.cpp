/*
    [SWEA] 1288 새로운 불면증 치료법
 */
#include <iostream>
#include <cstring>
#include <math.h>
#define endl "\n"
using namespace std;

int score[10];
int T, num;
int flag;

bool check() {
	int cnt=0;
	for (int i = 0; i < 10; ++i) {
		if (score[i] == 1)
		{
			cnt++;
		}
	}
	if (cnt == 10) {
		return true;
	}
	else
		return false;
}

bool zero(int check_num,int operand,int num) {
	if (!check_num) {
		//num이 0이면
		if ( (num - operand) < 0) {	//나누는 숫자보다 num이 작은거지
			return false;
		}
		else {
			return true;			//나누는 숫자보다 num이 크면
		}
	}
	else {
		return true;
	}
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		memset(score, 0, sizeof(score));
		cin >> num;
		int pre = num;
		int post = num;
		int index = 1;

		while (!check()) {
			num = pre * index;
			post = num;

			int first = num / 1000000;
			num = num % 1000000;
			if (zero(first, 1000000, pre)) {
				score[first] = 1;
			}

			int second = num / 100000;
			num = num % 100000;
			if (zero(second, 100000, pre)) {
				score[second] = 1;
			}
			int third = num / 10000;
			num = num % 10000;
			if (zero(third, 10000, pre)) {
				score[third] = 1;
			}

			int thousand = num / 1000;
			num = num % 1000;
			if (zero(thousand, 1000, pre)) {
				score[thousand] = 1;
			}

			int hundred = num / 100;
			num = num % 100;
			if (zero(hundred, 100, pre)) {
				score[hundred] = 1;
			}

			int ten = num / 10;
			num = num % 10;
			if (zero(ten, 10, pre)) {
				score[ten] = 1;
			}

			score[num] = 1;

			index++;
		}
		cout<<"#"<<tc<<" "<< post << endl;
	}
	return 0;
}
