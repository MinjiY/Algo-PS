/*
    [SWEA] 2105 디저트 카페
    모의 SW 역량테스트
 */
#include <iostream>
#include <cstring>

using namespace std;

int N;
int ans;
int map[21][21];
int temp_ans, start_y , start_x;
int desert[101];
int cnt[4];
void dfs(int y, int x, int turn) {
	if (y == start_y && x == start_x && turn == 3) {
		if (ans < temp_ans) {
			ans = temp_ans;
		}
		return;
	}
	if (y < 0 || x < 0 || y >= N || x >= N)
		return;

	if (desert[map[y][x]] == 1) return;
	desert[map[y][x]] = 1;
	temp_ans++;

	if (turn == 0) {
		cnt[0]++;
		dfs(y + 1, x + 1, 0);		//오른쪽 아래방향
		cnt[0]--;
		if (cnt[0] != 0) {			//무조건 반대방향으로 한번 돌아보긴 해야하니까(1이상부터) => 마름모,긴 마름모 모양
			cnt[1]++;
			dfs(y + 1, x - 1, 1);	//왼쪽 아래방향
			cnt[1]--;
		}
	}
	else if (turn == 1) {
		cnt[1]++;
		dfs(y + 1, x - 1, 1);		//왼쪽 아래방향 
		cnt[1]--;
		if (cnt[1] != 0)			//무조건 반대방향으로 한번 돌아보긴 해야하니까(1이상부터) => 마름모,긴 마름모 모양
		{							//turn+1 하는거지
			cnt[2]++;
			dfs(y - 1, x - 1, 2);	//왼쪽 위에 방향
			cnt[2]--;
		}
	}
	else if (turn == 2) {
		if (cnt[2] == cnt[0]) {		// 정 마름모 =>만나려면 turn0 이랑 turn2랑 갯수가 같아야함
			cnt[3]++;				
			dfs(y - 1, x + 1, 3);	//오른쪽 위에방향
			cnt[3]--;
		}
		else if (cnt[2] < cnt[0]) {	// 
			cnt[2]++;
			dfs(y - 1, x - 1, 2);	//왼쪽 위 방향
			cnt[2]--;
		}

	}
	else {							//마지막 턴
		cnt[3]++;
		dfs(y - 1, x + 1, 3);		//오른쪽 위 방향
		cnt[3]--;
	}
	desert[map[y][x]]=0; temp_ans--;
}
void solution() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < N-2; ++i) {					//
		for (int j = 1; j < N-1; ++j) {				//
			temp_ans = 0; 
			start_y = i;
			start_x = j;
			dfs(i, j, 0);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;
		ans = -1;
		solution();
		
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}