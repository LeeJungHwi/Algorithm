#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // 8
vector<vector<int>> graph(128, vector<int>(128)); // 그래프
int whiteCnt, blueCnt; // 흰색(0), 파란색(1) 종이 개수 저장

// DFS
void DFS(int i, int j, int size)
{
	if (size == 1) // 종료 조건: 현재 사이즈가 1이면 종이 개수 카운팅
	{
		// 흰색 종이
		if (graph[i][j] == 0)
		{
			whiteCnt++;

			return;
		}

		// 파란색 종이
		blueCnt++;

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
			// 흰색 종이
			if (standardPos == 0)
			{
				whiteCnt++;

				return;
			}

			// 파란색 종이
			blueCnt++;

			return;
		}

		// 같은 수가 아니라면 체크 할 사이즈 감소
		for (int k = 0; k < 2; k++)
		{
			for (int l = 0; l < 2; l++)
			{
				DFS(i + k * (size / 2), j + l * (size / 2), (size / 2));
			}
		}
	}
}

// 색종이 만들기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	//	1 1 0 0 0 0 1 1
	//	1 1 0 0 0 0 1 1
	//	0 0 0 0 1 1 0 0
	//	0 0 0 0 1 1 0 0
	//	1 0 0 0 1 1 1 1
	//	0 1 0 0 1 1 1 1
	//	0 0 1 1 1 1 1 1
	//	0 0 1 1 1 1 1 1
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	// DFS
	DFS(0, 0, n);

	cout << whiteCnt << '\n' << blueCnt << '\n';

	return 0;
}
