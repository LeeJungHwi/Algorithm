#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n, m; // N, M 4, 2
vector<int> sequence; // 수열
vector<bool> vis(9); // 방문체크

// DFS
void DFS(int L)
{
	if (L == m) // 종료조건 : N개를 선택
	{
		// 수열 출력
		for (int i = 0; i < sequence.size(); i++)
		{
			cout << sequence[i] << ' ';
		}

		cout << '\n';
	}
	else
	{
		for (int i = 1; i < n + 1; i++)
		{
			if (!vis[i])
			{
				vis[i] = true; // 선택
				sequence.push_back(i); 
				DFS(L + 1);
				sequence.pop_back();
				vis[i] = false; // 미선택
			}
		}
	}
}

// N과 M (1)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	// DFS
	DFS(0);

	return 0;
}