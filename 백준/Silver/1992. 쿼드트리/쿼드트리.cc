#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n; // 8
vector<vector<int>> graph(64, vector<int>(64)); // 그래프

// DFS
void DFS(int i, int j, int size)
{
	if (size == 1) // 종료 조건: 현재 사이즈가 1이면 압축결과 출력
	{
		// 0
		if (graph[i][j] == 0)
		{
			cout << 0;
			return;
		}

		// 1
		cout << 1;
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

		// 만약 모두 같은 수면 압축결과 출력
		if (isEqual)
		{
			// 0
			if (standardPos == 0)
			{
				cout << 0;
				return;
			}

			// 1
			cout << 1;
			return;
		}

		// 같은 수가 아니라면 체크 할 사이즈 감소
		// 같은 수가 아니라면 압축결과를 (압축결과) 로 표현함
		cout << '(';
		for (int k = 0; k < 2; k++)
		{
			for (int l = 0; l < 2; l++)
			{
				DFS(i + k * (size / 2), j + l * (size / 2), (size / 2));
			}
		}
		cout << ')';
	}
}

// 쿼드트리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	//	11110000
	//	11110000
	//	00011100
	//	00011100
	//	11110000
	//	11110000
	//	11110011
	//	11110011

	string inputString;

	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		for (int j = 0; j < n; j++)
		{
			graph[i][j] = inputString[j] - '0';
		}
	}

	// DFS
	DFS(0, 0, n);

	return 0;
}
