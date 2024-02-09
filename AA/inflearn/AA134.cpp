#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int l, n; // L, N 6, 4
vector<pair<int, int> > pipes(20); // 파이프 : (길이,용량) 쌍 저장
vector<bool> vis(20); // 방문체크
int maxCap; // 송수관의 최대용량 : 문제에서 송수관의 용량은 송수관을 구성하는 파이프 중 가장 작은 파이프의 용량이라함

void DFS(int L, int pipeLen)
{
	if (L == n || pipeLen == l) // 종료조건 : 파이프 수를 넘어가거나 길이 l인 파이프를 만든경우
	{
		// 파이프 수를 넘긴경우 길이가 l인 파이프를 만든경우가 아니면 리턴
		if (L == n)
		{
			if (pipeLen != l)
			{
				return;
			}
		}

		// 가장 작은 파이프의 용량 갱신
		int minPipeCap = 2147000000;

		for (int i = 0; i < n; i++)
		{
			if (vis[i])
			{
				if (minPipeCap > pipes[i].second)
				{
					minPipeCap = pipes[i].second;
				}
			}
		}

		// 송수관의 최대용량 갱신
		if (maxCap < minPipeCap)
		{
			maxCap = minPipeCap;
		}
	}
	else
	{
		vis[L] = true; // 파이프를 선택함
		DFS(L + 1, pipeLen += pipes[L].first); // 선택한 파이프의 길이 누적
		vis[L] = false; // 파이프를 안 선택함
		DFS(L + 1, pipeLen -= pipes[L].first); // 선택한 파이프의 길이 다시 빼줌
	}
}

// 사막의 벼농사
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> l >> n;

	int len; // 길이
	int cap; // 용량

	//	3 6
	//	2 7
	//	4 8
	//	1 5
	for (int i = 0; i < n; i++)
	{
		cin >> len >> cap;

		pipes[i] = { len, cap };
	}

	// DFS
	DFS(0, 0);

	cout << maxCap;

	return 0;
}