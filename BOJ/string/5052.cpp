/*
	[BOJ] 5052 ��ȭ��ȣ ���
	https://www.acmicpc.net/problem/5052
*/

#pragma warning (disable: 4996)

#include <cstdio>
#include <cstring>
//�� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��� => �ϰ��� x

const int TrieNode = 10;	//0~9

struct Trie {
	Trie* children[TrieNode];
	bool is_terminal;
	
	bool nextChild;				//�ڽ� ����

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

			//�Է¹��� ������ �����µ� �ڿ� ���� ������, �����ִ� ������ �Է¹��� ������ ���ξ�
			if (nextChild)				//�ϰ��� ��
				return 0;
			else
				return 1;				//�ϰ��� ��
		}

		int index = (*key - '0');		//���� ������ index
		if (children[index] == 0) {		//��������� ���θ���
			children[index] = new Trie();
		}
		
		nextChild = true;
		bool get = children[index]->insert(key + 1);	//�������� ���ڿ��߿��� ���� ������ �������ڸ� insertȣ�� 
		return (!is_terminal) && get;					//���ڿ� ���� ������ �ϰ��� üũ�� ��ȯ�ް� && ������ �ȳ�������
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