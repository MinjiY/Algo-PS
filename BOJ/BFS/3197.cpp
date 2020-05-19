/*
    [BOJ] 3197 백조의 호수
    https://www.acmicpc.net/problem/3197
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAX = 1500;

typedef struct
{
	int y, x;
}Dir;

Dir moveDir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int R, C;
string lake[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	cin >> R >> C;

	vector<pair<int, int>> swan;
	queue<pair<int, int>> waterQ;
	for (int i = 0; i < R; i++)
	{
		cin >> lake[i];

		for (int j = 0; j < C; j++)
		{
			if (lake[i][j] == 'L')
			{
				swan.push_back({ i, j });
			}

			if (lake[i][j] == '.' || lake[i][j] == 'L')
			{
				waterQ.push({ i, j });
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(swan[0]);

	bool visited[MAX][MAX] = { false, };
	visited[swan[0].first][swan[0].second] = true;
	
	int day = 0;
	while (1)
	{
		queue<pair<int, int>> nextQ;

		bool flag = false;
		while (!q.empty())
		{
            //백조 0 이 백조1 찾는 bfs 
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			if (y == swan[1].first && x == swan[1].second)
			{
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int nextY = y + moveDir[i].y;
				int nextX = x + moveDir[i].x;

				if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C || visited[nextY][nextX])
					continue;

				visited[nextY][nextX] = true;

				if (lake[nextY][nextX] == 'X')
				{
					nextQ.push({ nextY, nextX });
					continue;
				}

				q.push({ nextY, nextX });
			}
		}
		
		if (flag)
			break;

		q = nextQ;

		// 얼음녹이는 bfs
		int waterQSize = waterQ.size();
		while (waterQSize--)
		{
			int y = waterQ.front().first;
			int x = waterQ.front().second;
			waterQ.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextY = y + moveDir[i].y;
				int nextX = x + moveDir[i].x;

				if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
				{
					continue;
				}

				if (lake[nextY][nextX] == 'X')
				{
					lake[nextY][nextX] = '.';
					waterQ.push({ nextY, nextX });
				}
			}
		}

		day++;
	}

	cout << day << "\n";
	return 0;
}