#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // N 6
vector<pair<int, int> > players1(16); // 선수(횐돌능력치, 검은돌능력치)
vector<bool> vis1(16); // 방문체크 : true면 흰돌선수
int minGap = 2147000000; // 능력치 차 최소값

// DFS
void DFS(int L, int cnt)
{
	if (L == n || cnt == n / 2) // 종료조건 : 마지막 선수까지 가거나 흰돌선수의 수 만큼 뽑았을때
	{
		if (L == n) // 마지막 선수에서 종료된 경우
		{
			if (cnt != n / 2) // 흰돌선수의 수 만큼 뽑지 않은경우는 버림
			{
				return;
			}
		}

		int white = 0;
		int black = 0;

		// abs(흰돌 선수의 능력치 합 - 검은돌 선수의 능력치 합)로 min값 갱신
		for (int i = 0; i < n; i++)
		{
			if (vis1[i])
			{
				// 흰돌 선수 능력치 합
				white += players1[i].first;
				continue;
			}

			// 검은돌 선수 능력치 합
			black += players1[i].second;
		}

		int gap = abs(white - black); // 능력치 차

		if (minGap > gap) // 능력치 차 최소값 갱신
		{
			minGap = gap;
		}
	}
	else
	{
		vis1[L] = true; // 흰돌선수로 뽑음
		DFS(L + 1, cnt += 1); // 뽑은 횟수 증가 DFS
		vis1[L] = false; // 흰돌선수로 안 뽑음 
		DFS(L + 1, cnt -= 1); // 뽑은 횟수 감소 DFS
	}
}

// 바둑대회
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	int white, black; 

	for (int i = 0; i < n; i++)
	{
		cin >> white >> black;

		players1[i] = { white, black };
	}

	// DFS
	DFS(0, 0);

	cout << minGap << '\n';

	return 0;
}