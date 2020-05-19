/*
    [BOJ] 17281 야구(이모티콘)
    https://www.acmicpc.net/problem/17281
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

int ining[51][9];			
bool visit[9];
int selected1[9];		//team1 순열
//team1에 들어오는 1번 타자는 무조건 4번째
int ground[4];	// 0: home;

int total_point;//ans
int Max = 0;
void solution() {
	for (int i = 0; i < 3; ++i) {
		selected1[i] = selected1[i + 1];
	}
	selected1[3] = 0;

	
	int i=0;
	int ining_count = 0;
	int	out_count = 0;
	total_point = 0;

	bool end_flag = true;
		while (ining_count <N ) {
				switch ( ining[ining_count][selected1[i%9]] ) {
				case 1:							//안타 : 모든 주자 한루씩 진루
					ground[0] = ground[3];
					ground[3] = ground[2];
					ground[2] = ground[1];
					ground[1] = 1;

					if (ground[0] > 0) {
						total_point++;
					}
					ground[0] = 0;
					break;
				case 2:							//2루타: 두 루씩
					
					
					if (ground[3] > 0)
						total_point++;
					if (ground[2] > 0)
						total_point++;
					
					ground[3] = ground[1];
					ground[2] = 1;
					
					ground[1] = 0;
					ground[0] = 0;
					break;
				case 3:							//3루씩 : 세 루씩
					if (ground[3] > 0)
						total_point++;
					if (ground[2] > 0)
						total_point++;
					if (ground[1] > 0)
						total_point++;

					memset(ground, 0, sizeof(ground));
					ground[3] = 1;
					break;
				case 4:						//홈런 : 타자와 모든 주자가 홈까지 진루
					
					for (int k = 1; k < 4; ++k) {
						if (ground[k])
							total_point++;
					}total_point++;
					memset(ground, 0, sizeof(ground));

					break;
				case 0:							//아웃 : ㅇㄹ
					
					out_count++;
					if (out_count >= 3)
					{
						ining_count++;
						out_count = 0;
						memset(ground, 0, sizeof(ground));
					}

					break;
				}
			
			i++;
		}

	for (int i = 3; i > 0; --i) {
		selected1[i] = selected1[i - 1];
	}
	selected1[0] = 0;
	memset(ground, 0, sizeof(ground));
	return;
}

void permutation(int cnt) {
	if (cnt == 9) {
		
	
		solution();
		if (Max < total_point)
			Max = total_point;
		return;
	}

	for (int i = 1; i < 9; ++i) {
		if (visit[i] == 0) {
			visit[i] = 1;
			selected1[cnt] = i;
			permutation(cnt + 1);
			selected1[cnt] = 0;
			visit[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> ining[i][j];
		}
	}
	permutation(1);

	cout << Max << "\n";

	return 0;
}