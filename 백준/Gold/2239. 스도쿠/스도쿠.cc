#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

vector<vector<int> > graph(9, vector<int>(9)); // 그래프
vector<pair<int, int> > blankPos; // 빈칸 좌표 저장

// DFS
void DFS(int L)
{
	if (L == blankPos.size()) // 종료 조건 : 빈칸을 모두 채운 경우
	{
		// 완성된 스도쿠 출력 후 프로그램 종료

		for (int i = 0; i < 9; i++)
		{
			string outputString; // 출력문자열

			for (int j = 0; j < 9; j++)
			{
				outputString += graph[i][j] + '0';
			}

			cout << outputString << '\n';
		}

		exit(0);
	}
	else
	{
		// 빈칸위치 꺼냄
		pair<int, int> standardPos = blankPos[L];

		// 행, 열, 사각형 검사
		vector<bool> isCol(10);
		vector<bool> isRow(10);
		vector<bool> isRec(10);

		for (int i = 0; i < 9; i++)
		{
			// 행에 있는 숫자 체크
			if (graph[standardPos.first][i] > 0)
			{
				isCol[graph[standardPos.first][i]] = true;
			}

			// 열에 있는 숫자 체크
			if (graph[i][standardPos.second] > 0)
			{
				isRow[graph[i][standardPos.second]] = true;
			}

			// 사각형에 있는 숫자 체크
			for (int j = standardPos.first / 3 * 3; j < standardPos.first / 3 * 3 + 3; j++)
			{
				for (int k = standardPos.second / 3 * 3; k < standardPos.second / 3 * 3 + 3; k++)
				{
					isRec[graph[j][k]] = true;
				}
			}
		}

		// 가능한 숫자(행, 열, 사각형에 모두 없는 숫자) 찾아서 넣기
		for (int i = 1; i < 10; i++)
		{
			if (!isCol[i] && !isRow[i] && !isRec[i])
			{
				graph[standardPos.first][standardPos.second] = i; // 숫자 넣음
				DFS(L + 1);
				graph[standardPos.first][standardPos.second] = 0; // 숫자 안 넣음
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

	//	103000509
	//	002109400
	//	000704000
	//	300502006
	//	060000050
	//	700803004
	//	000401000
	//	009205800
	//	804000107

	string inputString; // 입력문자열

	for (int i = 0; i < 9; i++)
	{
		cin >> inputString;

		for (int j = 0; j < 9; j++)
		{
			graph[i][j] = inputString[j] - '0';

			if (graph[i][j] == 0)
			{
				blankPos.push_back({ i, j }); // 빈칸 좌표 저장
			}
		}
	}

	// DFS
	DFS(0);

	return 0;
}