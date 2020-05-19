/*
    [SWEA] 특이한 자석
    모의 SW 역량테스트
 */
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 8
int T, K;
int tobni[5][MAX];
bool check[5];

void input() {
	for (int i = 1; i <= 4; ++i) {		//톱니바퀴 번호
		for (int j = 0; j < 8; ++j) {	//톱니번호
			cin >> tobni[i][j];
		}
	}
}
void output() {
	for (int i = 1; i <= 4; ++i) {		//톱니바퀴 번호
		for (int j = 0; j < 8; ++j) {	//톱니번호
			cout << tobni[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void func1(int tobni_num, int rot_dir) {
	if (rot_dir == 1) {
		int temp = tobni[tobni_num][MAX - 1];
		for (int j = MAX - 1; j > 0; --j) {
			tobni[tobni_num][j] = tobni[tobni_num][j - 1];
		}
		tobni[tobni_num][0] = temp;
	}
	else if (rot_dir == (-1)) {
		int temp = tobni[tobni_num][0];
		for (int j = 0; j < MAX - 1; ++j) {
			tobni[tobni_num][j] = tobni[tobni_num][j + 1];
		}
		tobni[tobni_num][MAX - 1] = temp;
	}
	return;
}

void rotate(int tobni_num, int rot_dir) {
	switch (tobni_num) {
	case 1:
		if (!check[tobni_num]) {
			check[tobni_num] = 1;
			func1(tobni_num, rot_dir);
			if (rot_dir > 0) {
				if (tobni[tobni_num][3] != tobni[tobni_num + 1][6]) {
					rotate(tobni_num + 1, rot_dir * (-1));
				}
			}
			else if (rot_dir < 0) {
				if (tobni[tobni_num][1] != tobni[tobni_num + 1][6]) {
					rotate(tobni_num + 1, rot_dir * (-1));
				}
			}
		}
		break;
	case 2:
		if (!check[tobni_num]) {
			check[tobni_num] = 1;
			func1(tobni_num, rot_dir);
			if (rot_dir > 0) {
				if (tobni[tobni_num][3] != tobni[tobni_num + 1][6]) {
					rotate(tobni_num + 1, rot_dir * (-1));
				}
				if (tobni[tobni_num][7] != tobni[tobni_num - 1][2]) {
					rotate(tobni_num - 1, rot_dir * (-1));
				}
			}
			else if (rot_dir < 0) {
				if (tobni[tobni_num][1] != tobni[tobni_num + 1][6]) {
					rotate(tobni_num + 1, rot_dir * (-1));
				}
				if (tobni[tobni_num][5] != tobni[tobni_num - 1][2]) {
					rotate(tobni_num - 1, rot_dir * (-1));
				}
			}
		}
		break;
	case 3:
		if (!check[tobni_num]) {
			check[tobni_num] = 1;
			func1(tobni_num, rot_dir);
			if (rot_dir > 0) {
				if (tobni[tobni_num][3] != tobni[tobni_num + 1][6]) {
					rotate(tobni_num + 1, rot_dir * (-1));
				}
				if (tobni[tobni_num][7] != tobni[tobni_num - 1][2]) {
					rotate(tobni_num - 1, rot_dir * (-1));
				}
			}
			else if (rot_dir < 0) {
				if (tobni[tobni_num][1] != tobni[tobni_num + 1][6]) {
					rotate(tobni_num + 1, rot_dir * (-1));
				}
				if (tobni[tobni_num][5] != tobni[tobni_num - 1][2]) {
					rotate(tobni_num - 1, rot_dir * (-1));
				}
			}
		}
		break;
	case 4:
		if (!check[tobni_num]) {
			check[tobni_num] = 1;
			func1(tobni_num, rot_dir);
			if (rot_dir > 0) {
				if (tobni[tobni_num][7] != tobni[tobni_num - 1][2]) {
					rotate(tobni_num - 1, rot_dir * (-1));
				}
			}
			else if (rot_dir < 0) {
				if (tobni[tobni_num][5] != tobni[tobni_num - 1][2]) {
					rotate(tobni_num - 1, rot_dir * (-1));
				}
			}
		}
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	freopen("sample_input_4013.txt", "r", stdin);
	
	cin >> T;

	
	for (int tc = 1; tc <= T; ++tc) {
		memset(check, 0, sizeof(check));
		memset(tobni, 0, sizeof(tobni));
		cin >> K;
		input();
        
		for (int i=0; i < K; ++i) {
			int num, dir;
			cin >> num >> dir;
			memset(check, 0, sizeof(check));
			rotate(num, dir);
		}

		int ans = 0;
		for (int i = 1; i < 5; ++i) {
			if (tobni[i][0]) {
				ans += (1 << i - 1);
			}
		}
		cout << "#" << tc << " " << ans << "\n";

	}
	return 0;
}
