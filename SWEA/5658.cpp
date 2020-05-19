/*
    [SWEA] 5658 보물상자 비밀번호
    모의 SW 역량테스트
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int T, N, K;			//테케, 문자열길이, 번째

char list[28];
char ans[7];

vector<int> v;
int bitmask(int num, int offset) {
	int temp = 0;
	for (int i = 0; i < 4; ++i) {
		
		if ((num << (offset * 4)) & (1 <<( i+(offset*4)))) {
			temp += (1 << (i+(offset*4)));
		}
	}
	return temp;
}
//정수변환
int transformation(char * parameter) {
	int temp = 0;
	int cnt = 0;
	for (int i = 0; i < (N/4); ++i) {
		if (parameter[i] < 65) {	//숫자
			parameter[i] -= '0';
		}
		else {						//알파벳
			parameter[i] = (parameter[i] - 'A') + 10;
		}
	}

	
	for (int i = (N/4)-1; i >=0; --i) {
		temp+=bitmask(parameter[i], cnt);
		cnt++;
	}
	
	return temp;
}

void rotate() {
	int rot = (N / 4);
	while (rot--) {
		
		for (int i = 0; i < N + 1; ++i) {
			if ((i != 0) && (i % (N / 4) == 0)) {
				int num = transformation(ans);
				//printf("%d ", num);
				v.push_back(num);
				//printf("\n");
			}
			
			ans[i % (N / 4)] = list[i];
		}

		char temp = list[N-1];
		for (int i = N-1; i > 0; --i) {
			list[i] = list[i - 1];
		}
		list[0] = temp;
	}
}

int main() {

	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		memset(ans, 0, sizeof(0));
        memset(list, 0, sizeof(0));
		v.clear();
		scanf("%d %d ", &N, &K);

		for (int i = 0; i < N; ++i) {
			scanf(" %c", &list[i]);
		}
		
		
		rotate();

		
		sort(v.begin(), v.end(),greater<int>());
		v.erase(unique(v.begin(), v.end()),v.end());
		printf("#%d %d\n", tc, v[K-1]);
	}


	return 0;
}