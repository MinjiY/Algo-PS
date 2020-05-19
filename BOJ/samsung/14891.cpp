/*
    [BOJ] 14891 톱니바퀴
    https://www.acmicpc.net/problem/14891
 */
#include <iostream>
#include <cstdio>
#define end "\n"
#define wheel 4
#define N 8
using namespace std;

int map[wheel][N];	//톱니바퀴 갯수 =wheel, 톱니의 갯수 = N
int K;				//회전 횟수
int num, dir;		//회전 시킨 톱니바퀴의 번호, 방향
int wheelpair[3];

//톱니의 2번 인덱스와 6번 인덱스의 결합확인
//시계방향  = arrLen-1;
//반시계방향  = 1;

void rotation(int wheelnum,int dire) {
	int rNum = 0;
	int arr[N] = { 0 };
	if (dire == 1) {		//시계 방향이면?
		rNum = N - 1;
	}
	else if (dire == -1) {
		rNum = 1;
	}
	
	rNum = rNum % 8;
	int j = 0;
	for (int i = rNum; i < 8; ++i){
		arr[j] = map[wheelnum][i];
		++j;
	}
	for (int i = 0; i < rNum; ++i) {
		arr[j] = map[wheelnum][i];
		++j;
	}
	for (int i = 0; i < N; ++i) {
		map[wheelnum][i] = arr[i];
	}
}

void checkwheel(){
	//N극: 0 , S극: 1
	// 1번에 2, 2번에 2 6, 3번에 2 6 ,4번에 6
	if (map[0][2] != map[1][6]) {
		wheelpair[0] = 1;
	}
	if (map[1][2] != map[2][6]) {
		wheelpair[1] = 1;
	}
	if (map[2][2] != map[3][6]) {
		wheelpair[2] = 1;
	}
}
void checkrotation(int wheelnum, int dire) {// rotation한 wheelnum, 방향
	if (wheelnum == 0) {
		if (wheelpair[0]) {				//N극과 S극 이었다면
			wheelpair[0] = 0;
			rotation(wheelnum + 1, dire * (-1));
			checkrotation(wheelnum + 1, dire * (-1));
		}
	}
	if (wheelnum == 1) {
		if (wheelpair[0]){	
			wheelpair[0] = 0;
			rotation(wheelnum - 1, dire * (-1));
			checkrotation(wheelnum - 1, dire * (-1));

		}
		if (wheelpair[1]){
			wheelpair[1] = 0;
			rotation(wheelnum + 1, dire * (-1));
			checkrotation(wheelnum + 1, dire * (-1));
		}

	}
	if (wheelnum == 2){
		if (wheelpair[1]) {
			wheelpair[1] = 0;
			rotation(wheelnum - 1, dire * (-1));
			checkrotation(wheelnum - 1, dire * (-1));
		}
		if (wheelpair[2]) {
			wheelpair[2] = 0;
			rotation(wheelnum + 1, dire * (-1));
			checkrotation(wheelnum + 1, dire * (-1));
		}
	}
	if (wheelnum == 3) {
		if (wheelpair[2]) {
			wheelpair[2] = 0;
			rotation(wheelnum - 1, dire * (-1));
			checkrotation(wheelnum - 1, dire * (-1));
		}
	}
}

void input() {
	for (int i = 0; i < wheel; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%1d", &map[i][j]);
		}
	}
}
void printMap() {
	for (int i = 0; i < wheel; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << map[i][j] << " ";
		}
		cout << end;
	}
}

int main() {
	//K = 회전 횟수
	//num = 회전시킬 톱니바퀴 넘버
	//dir = 회전 방향 -1이면 반시계, 1 시계

	input();
	cin >> K;
	for (int rot = 0; rot < K; ++rot) {
		cin >> num >> dir;
		--num;
		checkwheel();
		rotation(num, dir);
		checkrotation(num, dir);
	}
	int sum = 0;
		if (map[0][0] == 1) {
			sum += 1;
		}
		if (map[1][0] == 1) {
			sum += 2;
		}
		if (map[2][0] == 1) {
			sum += 4;
		}
		if (map[3][0] == 1) {
			sum += 8;
		}

//	printMap();
	cout << sum;

	return 0;
}
