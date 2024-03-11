#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n, m; // N, M 4, 2
vector<bool> vis(9); // 방문체크

// DFS
void DFS(int L, int cnt)
{
	if (L == n + 1 || cnt == m) // 종료조건 : 선택가능한 수를 넘기거나 M개를 뽑은경우
	{
		// 선택가능한 수를 넘긴경우
		if (L == n + 1)
		{
			if (cnt != m) // M개를 뽑은경우가 아니면 리턴
			{
				return;
			}
		}

		// 선택한 수 출력
		for (int i = 1; i < n + 1; i++)
		{
			if (vis[i])
			{
				cout << i << ' ';
			}
		}

		cout << '\n';
	}
	else
	{
		vis[L] = true; // 선택
		DFS(L + 1, cnt += 1);
		vis[L] = false; // 미선택
		DFS(L + 1, cnt -= 1);
	}
}

// N과 M (2)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	// DFS
	DFS(1, 0);

	return 0;
}