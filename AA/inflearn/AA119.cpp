#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

vector<vector<int> > graph(9, vector<int>(9)); // 스도쿠 판
vector<pair<int, int> > blankPos; // 빈칸 좌표

// 현재 빈칸위치의 숫자가 유효한지 체크
bool isValid(int row, int col, int num)
{
	// 같은 행에 이미 num이 있는지 확인
	for (int i = 0; i < 9; ++i)
	{
		if (graph[row][i] == num)
		{
			return false;
		}
	}

	// 같은 열에 이미 num이 있는지 확인
	for (int i = 0; i < 9; ++i)
	{
		if (graph[i][col] == num)
		{
			return false;
		}
	}

	// 같은 상자에 이미 num이 있는지 확인
	int startRow = row - row % 3;
	int startCol = col - col % 3;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (graph[startRow + i][startCol + j] == num)
			{
				return false;
			}
		}
	}

	return true;
}

// DFS
void DFS(int L)
{
	if (L == blankPos.size()) // 종료조건 : 모든 빈칸을 채운경우
	{ 
		// 스도쿠 출력 후 프로그램 종료
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << graph[i][j] << " ";
			}

			cout << '\n';
		}

		exit(0);
	}
	else
	{
		// 빈칸 좌표 꺼냄
		int row = blankPos[L].first;
		int col = blankPos[L].second;

		// 1부터 10까지 넣어봄
		// 같은행 같은열 같은상자에 같은숫자가 있으먼 안됨
		for (int num = 1; num < 10; num++)
		{
			// 가능한 숫자일 경우
			if (isValid(row, col, num))
			{
				graph[row][col] = num; // 숫자를 넣음
				DFS(L + 1);
				graph[row][col] = 0; // 숫자를 지움
			}
		}
	}
}

// 스도쿠
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	//	0 2 3 0 5 0 7 8 9
	//	0 5 6 0 8 9 1 0 3
	//	0 8 9 1 0 3 0 5 6
	//	0 1 0 0 6 0 8 9 0
	//	3 0 5 0 9 7 0 1 4
	//	0 9 7 0 1 0 0 6 5
	//	5 3 0 6 0 2 9 7 8
	//	6 0 2 9 0 8 5 3 1
	//	9 0 8 0 3 0 6 0 2
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> graph[i][j];

			// 빈칸 좌표 저장
			if (graph[i][j] == 0)
			{
				blankPos.push_back({ i, j });
			}
		}
	}

	// DFS
	DFS(0);

	return 0;
}
