#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 회장뽑기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	int v1, v2; // 정점

	vector<vector<int> > scores(n + 1, vector<int>(n + 1, 100)); // 중간회원이 몇명인지에 따라 최소점수 갱신
	vector<int> result(n + 1); // 다이나믹 후 각 행의 최대점수 저장

	//  연결정보가 저장(중간회원 없이 친구), i == j는 0, 나머지는 max값으로 초기화
	/*
	Input : 1 2
			2 3
			3 4
			4 5
			2 4
			5 3
			- 1 - 1

	graph : 0 1 0 0 0
			0 0 1 1 0
			0 0 0 1 0
			0 0 0 0 1
			0 0 1 0 0
	*/
	while (true)
	{
		cin >> v1 >> v2;

		if (v1 == -1 && v2 == -1) // 마지막 줄 종료
		{
			break;
		}

		// 양방향 연결
		scores[v1][v2] = 1;
		scores[v2][v1] = 1;
	}

	for (int i = 1; i < n + 1; i++)
	{
		scores[i][i] = 0;
	}

	// 중간회원이 몇명인지에 따라 최소점수 갱신 : 바로친구 1, 친구의 친구 2, 친구의 친구의 친구 3, ....
	for (int k = 1; k < n + 1; k++)
	{
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				if (scores[i][j] > scores[i][k] + scores[k][j])
				{
					scores[i][j] = scores[i][k] + scores[k][j];
				}
			}
		}
	}

	// 각 행(회원점수)의 최대점수 저장
	for (int i = 1; i < n + 1; i++)
	{
		int maxScore = 0;

		for (int j = 1; j < n + 1; j++)
		{
			if (scores[i][j] > maxScore)
			{
				maxScore = scores[i][j];
			}
		}

		result[i] = maxScore; // 3 2 2 2 3
	}

	// 회원점수가 가장 작은 사람이 회장후보
	int minScore = 100;

	for (int i = 1; i < n + 1; i++)
	{
		if (minScore > result[i])
		{
			minScore = result[i]; // 2
		}
	}

	// 회장후보 점수 출력
	cout << minScore << ' ';

	// 회장후보 오름차순 저장 및 몇명인지 카운팅
	int candidateCnt = 0;
	vector<int> candidates;

	for (int i = 1; i < n + 1; i++)
	{
		if (result[i] == minScore)
		{
			candidateCnt++;
			candidates.push_back(i);
		}
	}

	// 회장후보 지원자 수 출력
	cout << candidateCnt << '\n';

	// 회장후보 오름차순 출력
	for (int i = 0; i < candidates.size(); i++)
	{
		cout << candidates[i] << ' ';
	}

	return 0;
}