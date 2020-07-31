/*
	[BOJ] 5052 전화번호 목록
	https://www.acmicpc.net/problem/5052
*/

#pragma warning (disable: 4996)

#include <cstdio>
#include <cstring>
//한 번호가 다른 번호의 접두어인 경우 => 일관성 x

const int TrieNode = 10;	//0~9

struct Trie {
	Trie* children[TrieNode];
	bool is_terminal;
	
	bool nextChild;				//자식 유무

	Trie() : is_terminal(false) {
		memset(children, 0, sizeof(children));
		is_terminal = nextChild = false;
	}
	~Trie() {
		for (int i = 0; i < TrieNode; ++i) {
			if (children[i])
				delete children[i];
		}
	}

	bool insert(const char* key) {
		if (*key == '\0') {
			is_terminal = true;

			//입력받은 문장은 끝났는데 뒤에 뭔가 있으면, 원래있는 문장은 입력받은 문장의 접두어
			if (nextChild)				//일관성 없
				return 0;
			else
				return 1;				//일관성 있
		}

		int index = (*key - '0');		//현재 문자의 index
		if (children[index] == 0) {		//비어있으면 새로만듬
			children[index] = new Trie();
		}
		
		nextChild = true;
		bool get = children[index]->insert(key + 1);	//조사중인 문자열중에서 현재 문자의 다음문자를 insert호출 
		return (!is_terminal) && get;					//문자열 끝을 만나서 일관성 체크를 반환받고 && 문장이 안끝났을때
	}	
};

int main() {
	int T;
	scanf("%d", &T);
	
	for (int tc = 0; tc < T; ++tc) {
		int n;
		scanf("%d", &n);
		
		Trie* root = new Trie();
		bool check = true;

		while (n--) {
			char num[11];
			scanf("%s", num);
			
			if (root->insert(num) == 0) {
				check = false;
			}
		}
		
		if (check)
			printf("YES\n");
		else
			printf("NO\n");
		
		delete root;
	}
	return 0;
}