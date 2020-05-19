/*
    [SWEA] 1926 간단한 369게임
 */
#include <iostream>
using namespace std;
int N; // 최대수 
int arr[1000];

int check(int temp) {
	if (temp == 0) {
		return 0;
	}
	else if (temp % 9 == 0) {
		cout << '-';
		return 1;
	}
	else if (temp % 6 == 0) {
		cout << '-';
		return 1;
	}
	else if (temp % 3 == 0) {
		cout << '-';
		return 1;
	}
	return 0;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < N; ++i) {

		int thousand, hundred, ten, one, flag = 0;

		if (arr[i] / 10)                                             //10의 자릿수가 존재할때
		{        
			if ( (arr[i] / 10) / 10) {                               //100의 자릿수가 존재할 때
				if (((arr[i] / 10) / 10) / 10) {					 //1000의 자릿수가 존재할 때
					thousand = (((arr[i] / 10) / 10) / 10);
					if (check(thousand) == 1)
						flag = 1;
				}
				hundred = ((arr[i] / 10) / 10);
				if (check(hundred) == 1)
					flag = 1;
			}
			ten = arr[i] / 10;
			if (check(ten) == 1)
				flag = 1;
			one = arr[i] % 10;
			if (check(one) == 1)
				flag = 1;
			if (flag == 0)
				cout << arr[i];
		}
		else {
			if (!check(arr[i]))
				cout << arr[i];
		}
		cout << " ";
	}
	return 0;
}