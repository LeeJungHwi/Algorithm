#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // 9
vector<vector<int>> graph(2187, vector<int>(2187)); // 그래프
int minusCnt, zeroCnt, plusCnt; // -1, 0, 1 종이 개수 저장

// DFS
void DFS(int i, int j, int size)
{
	if (size == 1) // 종료 조건: 현재 사이즈가 1이면 종이 개수 카운팅
	{
		if (graph[i][j] == -1)
		{
			minusCnt++;

			return;
		}
		
		if (graph[i][j] == 0)
		{
			zeroCnt++;

			return;
		}

		plusCnt++;

		return;
	}
	else
	{
		// 모두 같은 수 인지 체크
		int standardPos = graph[i][j];
		bool isEqual = true;

		// 현재 체크 할 사이즈 만큼 돌면서 하나라도 기준위치의 값이랑 다르면 같은 수 아님
		for (int k = i; k < i + size; k++)
		{
			for (int l = j; l < j + size; l++)
			{
				if (graph[k][l] != standardPos)
				{
					isEqual = false;

					break;
				}
			}

			if (!isEqual)
			{
				break;
			}
		}

		// 만약 모두 같은 수면 종이 개수 카운팅
		if (isEqual)
		{
			if (standardPos == -1)
			{
				minusCnt++;

				return;
			}

			if (standardPos == 0)
			{
				zeroCnt++;

				return;
			}

			plusCnt++;

			return;
		}

		// 같은 수가 아니라면 체크 할 사이즈 감소
		for (int k = 0; k < 3; k++)
		{
			for (int l = 0; l < 3; l++)
			{
				DFS(i + k * (size / 3), j + l * (size / 3), (size / 3));
			}
		}
	}
}

// 종이의 개수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	//	0 0 0 1 1 1 - 1 - 1 - 1
	//	0 0 0 1 1 1 - 1 - 1 - 1
	//	0 0 0 1 1 1 - 1 - 1 - 1
	//	1 1 1 0 0 0 0 0 0
	//	1 1 1 0 0 0 0 0 0
	//	1 1 1 0 0 0 0 0 0
	//	0 1 - 1 0 1 - 1 0 1 - 1
	//	0 - 1 1 0 1 - 1 0 1 - 1
	//	0 1 - 1 1 0 - 1 0 1 - 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	// DFS
	DFS(0, 0, n);

	cout << minusCnt << '\n' << zeroCnt << '\n' << plusCnt << '\n';

	return 0;
}
