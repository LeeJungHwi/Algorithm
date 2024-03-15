#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

vector<vector<char> > graph(5, vector<char>(5)); // 그래프
vector<pair<int, int> > checkDir = { {-1, 0},{1, 0},{0, -1},{0, 1} }; // 상하좌우
int sevenPrincessCnt; // 소문난 칠공주를 결성하는 경우의 수

// BFS
// 7명의 공주들이 인접하는지 체크
void BFS(int selected[])
{
	queue<int> checkPos; // 체크 할 위치
	vector<char> vis(7, false); // 방문체크

	// 첫번째 공주 선택
	vis[0] = true;
	checkPos.push(selected[0]);

	int cnt = 1; // 총 인접한 수
	int cntS = 0; // 이다솜파 수

	// 큐가 빌때까지
	while (!checkPos.empty())
	{
		// 기준위치 꺼냄
		int standardPos = checkPos.front();
		checkPos.pop();

		// 이다솜파 카운팅
		if (graph[standardPos / 5][standardPos % 5] == 'S')
		{
			cntS++;
		}

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 나머지 공주 인접하는지 체크
			for (int checkSelected = 1; checkSelected < 7; checkSelected++)
			{
				// 방문체크
				if (vis[checkSelected])
				{
					continue;
				}

				// 인접체크
				if (standardPos % 5 + checkDir[i].first != selected[checkSelected] % 5 || standardPos / 5 + checkDir[i].second != selected[checkSelected] / 5)
				{
					continue;
				}
				
				// 인접한 공주임
				vis[checkSelected] = true;
				checkPos.push(selected[checkSelected]);
				cnt++;
			}
		}
	}

	// 인접한 공주가 7명이면서 이다솜파가 4명 이상이면 카운팅
	if (cnt == 7 && cntS >= 4)
	{
		sevenPrincessCnt++;
	}
}

// DFS
// 7명의 공주 선택
void DFS(int selected[], int curSelected, int L, int leftSelected)
{
	// 남은 선택 횟수가 0이면
	// 7명의 공주가 인접한지 체크 후 이다솜파가 4명 이상이면 카운팅
	if (leftSelected == 0)
	{
		BFS(selected);

		return;
	}

	// 선택 가능한 공주 수를 넘긴경우 리턴
	if (L == 25)
	{
		return;
	}

	selected[curSelected] = L;
	DFS(selected, curSelected + 1, L + 1, leftSelected - 1); // 선택
	DFS(selected, curSelected, L + 1, leftSelected); // 미선택
}

// 소문난 칠공주
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	/*
	1. 7명의 여학생들로 구성
	2. 7명의 자리는 가로 또는 세로로 반드시 인접해있어야 함
	3. 이다솜파의 학생들로만 구성될 필요는 없음
	4. 이다솜파가 적어도 4명 이상은 포함되어야 함

	소문난 칠공주를 결성하는 경우의 수 구하기
	*/

	//	YYYYY
	//	SYSYS
	//	YYYYY
	//	YSYYS
	//	YYYYY

	string inputString; // 입력문자열

	for (int i = 0; i < 5; i++)
	{
		cin >> inputString;

		for (int j = 0; j < 5; j++)
		{
			graph[i][j] = inputString[j];
		}
	}

	// DFS
	// 1.25명의 공주 중 7 명 선택 (순서 고려 X)
	// 2.선택된 공주들이 인접하는지 체크
	// 3.이다솜파가 4명 이상인지 체크 후 카운팅
	DFS(new int[7], 0, 0, 7);

	// 소문난 칠공주를 결성하는 경우의 수 출력
	cout << sevenPrincessCnt << '\n';

	return 0;
}