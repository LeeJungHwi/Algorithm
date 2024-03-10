#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <cmath>
using namespace std;

int n; // N 8
int cnt; // 퀸 N개가 서로 공격할수없게 놓여지는 경우의 수 92
vector<int> queen(15, -1); // 각 행에 놓인 퀸의 열 저장

// 퀸을 놓을수있는 위치인지 체크 
bool IsQueen(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		// 같은 열 또는 대각선에 퀸이 있는지 확인
		if (queen[i] == col || abs(row - i) == abs(col - queen[i]))
		{
			return false;
		}
	}

	return true;
}

// DFS
void DFS(int row)
{
	if (row == n) // 종료조건 : 모든 퀸을 놓은경우
	{
		cnt++;

		return;
	}
	else
	{
		// 현재 행에 대해 가능한 모든 열에 퀸을 놓아봄
		for (int col = 0; col < n; col++)
		{
			// 퀸을 놓을수 있는 위치라면 퀸을 놓고 다음 열 검사
			if (IsQueen(row, col))
			{
				queen[row] = col;
				DFS(row + 1);
			}
		}
	}
}

// N-Queen
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	// DFS
	DFS(0);

	// 퀸 N개가 서로 공격할수없도록 놓는 경우의 수 출력
	cout << cnt << '\n';

	return 0;
}
