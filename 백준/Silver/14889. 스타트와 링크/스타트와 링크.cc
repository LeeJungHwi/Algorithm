#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // N 6
vector<vector<int> > graph(20, vector<int>(20)); // 그래프
vector<bool> vis(20); // 방문체크
int minGap = 2147000000; // 팀의 능력치 차이 최소값

// DFS
void DFS(int L, int cnt)
{
	if (L == n || cnt == n / 2) // 종료조건 : 팀원 수를 넘기거나 절반의 팀원을 뽑은경우
	{
		if (L == n) // 팀원 수를 넘긴경우
		{
			if (cnt != n / 2) // 절반의 팀원을 뽑은경우가 아니면 리턴
			{
				return;
			}
		}

		// 팀의 능력치 차이 구하기
		vector<int> startTeam;
		vector<int> linkTeam;

		for (int i = 0; i < n; i++)
		{
			if (vis[i]) // 뽑은팀원은 스타트팀으로
			{
				startTeam.push_back(i);
			}
			else // 안 뽑은 팀원은 링크팀으로
			{
				linkTeam.push_back(i);
			}
		}

		int startSum = 0;
		int linkSum = 0;

		for (int i = 0; i < startTeam.size(); i++) // 스타트팀, 링크팀 능력치 구하기
		{
			for (int j = 0; j < startTeam.size(); j++)
			{
				if (i != j)
				{
					startSum += graph[startTeam[i]][startTeam[j]];
					linkSum += graph[linkTeam[i]][linkTeam[j]];
				}
			}
		}

		int gap = abs(startSum - linkSum); // 스타트팀, 링크팀 능력치 차이

		// 팀의 능려치 차이 최소값 갱신
		minGap = min(minGap, gap);
	}
	else
	{
		vis[L] = true; // 팀원 뽑음
		DFS(L + 1, cnt += 1);
		vis[L] = false; // 팀원 안 뽑음
		DFS(L + 1, cnt -= 1);
	}
}

// 스타트와 링크
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	//	0 1 2 3 4 5
	//	1 0 2 3 4 5
	//	1 2 0 3 4 5
	//	1 2 3 0 4 5
	//	1 2 3 4 0 5
	//	1 2 3 4 5 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	// DFS
	DFS(0, 0);

	cout << minGap << '\n';

	return 0;
}