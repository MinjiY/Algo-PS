/*
	[BOJ] 14425 문자열 집합
	https://www.acmicpc.net/problem/14425
*/
//N개의 줄에 집합 S에 속하는 문자열 입력
//M개의 줄에 집합 S에 속하는지 확인해야하는 문자열 입력
#pragma warning (disable: 4996)
#include <cstdio>
#include <cstring>
#define ALPHABET 26
//const int ALPHABET = 26;

struct Trie {
	bool is_terminal;
	Trie * children[ALPHABET];

	Trie() : is_terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~Trie() {
		for (int i = 0; i < ALPHABET; ++i) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			is_terminal = true;
		}
		else {
			int index = (*key - 'a');

			if (children[index] == 0)
				children[index] = new Trie();
			children[index]->insert(key + 1);
		}
	}

	Trie* find(const char* key) {
		if (*key == 0) {				//key가 0이면 ? => root 가 보통 0
			return this;
		}
		int index = (*key - 'a');
		if (children[index] == 0) {
			return NULL;
		}
		return children[index]->find(key + 1);
	}
	bool string_exist(const char* key) {
		if (*key == 0 && is_terminal) {	//root거나 문장의 끝인경우
			return true;
		}
		
		int index = (*key - 'a');
		if (children[index] == 0) {		//비어있으면 0
			return false;
		}
		return children[index]->string_exist(key + 1);
	}
};

int N,M;

int main() {
	int cnt = 0;
	scanf("%d %d", &N, &M);
	
	Trie* root = new Trie();

	for (int i = 0; i < N; ++i) {
		char str[500];
		scanf("%s",str);
		root->insert(str);
	}
	for (int i = 0; i < M; ++i) {
		char str[500];
		scanf("%s", str);
		bool check = root->string_exist(str);
		if (check) {
			cnt++;
		}
	}
	printf("%d\n", cnt);

	delete root;
	return 0;
}


/*
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<string> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  sort(all(v));
  int ret = 0;
  while(q--) {
	string s;
	cin >> s;
	auto it = lower_bound(all(v), s);
	ret += it != v.end() && *it == s;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  solve();
}


*/