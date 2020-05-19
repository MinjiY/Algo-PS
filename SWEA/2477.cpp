/*
    [SWEA] 2477 차량 정비소
    모의 SW 역량테스트
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K, A, B;
//접수창구의 개수 N
//정비창구의 개수 M
//차량 정비소를 방문한 고객 K
//지갑 두고간 고객이 이용한 접수창구번호 A
//지갑 두고간 고객이 이용한 정비창구번호 B

typedef struct {
	int time;	//처리 경과시간
	int num;	//고객넘버
}NODE;
typedef struct {
	int A;
	int B;
}info;
int ai[11];		//접수창구 처리시간
int bj[11];		//정비창구 처리시간
int tk[1002];	//고객k의 도착시간 tk

info ans[1002];
queue<int>  rec_wait;	// 접수 대기줄
queue<int>  rep_wait;	// 정비 대기줄
//대기줄에서 num = 고객넘버, time = 대기줄 선 시간
NODE reception[11];		//queue로 안만든이유: 접수창구에 고객들어오면 처리시간 카운트해야함(수정) / 창구는 한명씩사용
NODE repair[11];
int totally_time;
int cnt;
int ans_cnt;
void output() {
	for (int i = 1; i <= N; ++i) {
		cout << ai[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= M; ++i) {
		cout << bj[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= K; ++i) {
		cout << tk[i] << " ";
	}
	cout << "\n";
}
void input() {
	cin >> N >> M >> K >> A >> B;

	for (int i = 1; i <= N; ++i) {
		cin >> ai[i];
	}
	for (int i = 1; i <= M; ++i) {
		cin >> bj[i];
	}
	for (int i = 1; i <= K; ++i) {
		cin >> tk[i];
	}
}
void clearQueueINT(queue<int> &q) {
	queue<int> temp;
	swap(temp, q);
}

int main() {
	int T;
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	
	for (int tc = 1; tc <= T; ++tc) {
		totally_time=0;
		cnt=0;
		ans_cnt=0;
		memset(tk, 0, sizeof(tk));
		memset(ai, 0, sizeof(ai));
		memset(bj, 0, sizeof(bj));
		memset(ans, 0, sizeof(ans));
		input();
		//output();

		while (1) {	
			//고객 접수대기
			for (int i = 1; i <= K; ++i) {
				if (tk[i] == totally_time) {
					rec_wait.push(i);
				}
			}

			//접수창구 => 정비대기
			for(int i=1; i<=N; ++i){	//ai[i]: i번째 창구의 처리시간
				// 접수창구 고객넘버가 있고, 경과 시간이 해당 창구 처리시간이랑 같으면
				if ((reception[i].num != 0)&&(reception[i].time == ai[i])) {
					if (i == A) {
					//	cout << "1: " << i << " " << A << "\n";

						ans[reception[i].num].A = i;
					}
					rep_wait.push(reception[i].num);
					reception[i].time = 0;
					reception[i].num = 0;
				}
			}
			
			//정비 => exit
			for (int i = 1; i <= M; ++i) {
				if (repair[i].time == bj[i]) {
					if (i == B) {
					//	cout << "2: " << i << " " << B << "\n";
						ans[repair[i].num].B = i;
					}
					repair[i].num = 0;
					repair[i].time = 0;
					cnt++;
				}
			}

			//접수대기=> 접수창구
				//도착시간이 현재시간보다 작아야 대기중인거,
			for (int i = 1; i <= N; ++i) {
				if (rec_wait.size() == 0) break;
				if (tk[rec_wait.front()] < totally_time) {
					if (reception[i].num == 0) {
						reception[i].num = rec_wait.front();
						reception[i].time = 0;
						rec_wait.pop();
					}
				}
			
			}

			//정비대기=> 정비창구
			for (int i = 1; i <= M; ++i) {
				if (rep_wait.size()==0) break;
				if (repair[i].num == 0) {
					repair[i].num = rep_wait.front();
					repair[i].time = 0;
					rep_wait.pop();
				}
			}

			
			
			if (cnt >= K) {
				break;
			}

			totally_time++;
			for (int i = 1; i <= N; ++i) {
				if(reception[i].num)
					reception[i].time++;
			}
			for (int i = 1; i <= M; ++i) {
				if (repair[i].num)
					repair[i].time++;
			}

			
		}



		for (int i = 1; i <=K; ++i) {
			if ((ans[i].A == A) && (ans[i].B == B)) {
				ans_cnt += i;
			}
		}
		if (ans_cnt == 0)
			ans_cnt = -1;
		cout << "#" <<tc << " "<< ans_cnt<< "\n";
	}
	
	return 0;
}