/*
    [BOJ] 1935 후위 표기식 2
    https://www.acmicpc.net/problem/1935
*/

#include <iostream>
#include <cstdio>
using namespace std;

double stack[100];
int T;
int index = 0;

//65 = A
string str;
double list[26];		
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> T >> str;
	for (int i = 0; i < T; ++i) {
		cin >> list[i];
	}

	double num1 = 0, num2 = 0;
	
	
	for (int i = 0; i < str.length(); ++i) {
		// 65 ~ 90 operand
		if (59 < str[i] && str[i] < 91) {	//피연산자
			stack[index++] = list[str[i]-65];		//A:0 B:1 ~~
		}
		else{
			//연산자
			switch (str[i]) {
			case '+':
				num2 = stack[--index];
				num1 = stack[--index];
				stack[index++] = num1 + num2;
				break;
			case '-':
				num2 = stack[--index];
				num1 = stack[--index];
				stack[index++] = num1 - num2;
				break;
			case '*':
				num2 = stack[--index];
				num1 = stack[--index];
				stack[index++] = num1 * num2;
				break;
			case '/':
				num2 = stack[--index];
				num1 = stack[--index];
				stack[index++] = num1 / num2;
				break;
			}
		}
	}
	printf("%.2lf",stack[0]);
	return 0;
}
