#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <cmath>
using namespace std;

// 패턴 저장
void Pattern(vector<vector<char>>& pattern, int curN, int i, int j)
{
	if (curN == 3) // 패턴크기가 3by3인경우 기본패턴 저장
	{
		pattern[j][i] = '*';
		pattern[j + 1][i - 1] = '*';
		pattern[j + 1][i + 1] = '*';
		pattern[j + 2][i - 2] = '*';
		pattern[j + 2][i - 1] = '*';
		pattern[j + 2][i] = '*';
		pattern[j + 2][i + 1] = '*';
		pattern[j + 2][i + 2] = '*';

		return;
	}
	else // 패턴크기가 3보다 크면 이전패턴
	{
		Pattern(pattern, curN / 2, i, j);
		Pattern(pattern, curN / 2, i - curN / 2, j + curN / 2);
		Pattern(pattern, curN / 2, i + curN / 2, j + curN / 2);
	}
}

// 별찍기 11
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 24
	cin >> n;

	vector<vector<char>> pattern(n, vector<char>(2 * n - 1, ' ')); // 그래프

	// 패턴 저장
	Pattern(pattern, n, n - 1, 0);

	// 패턴 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout << pattern[i][j];
		}

		cout << '\n';
	}

	return 0;
}
