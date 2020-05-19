/*
    [SWEA] 1285 아름이의 돌 던지기
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define endl "\n"
int T,N;	//
int list[1000];
int flag;
vector<int> score;
int cnt[1000];
void input() {
	for (int i = 0; i < N; ++i) {
		cin >> list[i];
	}
}
void printMap() {
	cout << "출력: ";
	for (int i = 0; i < N; ++i) {
		cout << list[i] << " ";
	}
	cout << endl;
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	   cin >> T;
	   for (int tc = 0; tc < T; ++tc) {
		   cin >> N;
		   memset(cnt, 0, sizeof(cnt));
		   memset(list, 0, sizeof(list));
		   score.clear();
		   input();


		   for (int i = 0; i < N; ++i) {
			   score.push_back(abs(0 - list[i]));
		   }
		   sort(score.begin(), score.end());
		   int init = score[0];
		   int index = 0;
		   for (int i = 0; i < N; ++i) {
			   if (init == score[i]) {
				   cnt[index]++;
			   }
			   else {
				   init = score[i];
				   index++;
				   cnt[index]++;
			   }
		   }
		   cout << "#" << tc+1 << " " << score[0] << " " << cnt[0] << endl;
	   }


	return 0;
}
