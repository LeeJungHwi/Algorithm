#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 가장 큰 정사각형
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 그래프에서 1로 이루어진 가장 큰 정사각형 크기 구하기

	int n, m; // N, M 4, 4
	cin >> n >> m;

	vector<vector<long long> > graph(n + 1, vector<long long>(m + 1)); // 그래프
	string inputString;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> inputString;

		for (int j = 1; j < inputString.size() + 1; j++)
		{
			graph[i][j] = inputString[j - 1] - '0';
		}
	}
	vector<vector<long long> > dp(n + 1, vector<long long>(m + 1)); // i,j를 우하로 했을 때 만들 수 있는 정사각형 한 변의 최대길이 저장

	//for (auto a : graph)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	// 1행 및 1열 : 그래프값으로 채움
	// 단일 행 및 단일 열 고려
	long long maxLen = 0;
	for (int i = 1; i < n + 1; i++)
	{
		dp[i][1] = graph[i][1];
		maxLen = max(maxLen, dp[i][1]);
	}
	for (int i = 1; i < m + 1; i++)
	{
		dp[1][i] = graph[1][i];
		maxLen = max(maxLen, dp[1][i]);
	}

	// 2,2 부터 : 현재 dp값을 좌, 상, 좌상 중 최솟값 + 1로 저장
	for (int i = 2; i < n + 1; i++)
	{
		for (int j = 2; j < m + 1; j++)
		{
			if (graph[i][j] == 1)
			{
				dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] }) + 1;
				maxLen = max(maxLen, dp[i][j]);
			}
		}
	}

	//for (auto a : dp)
	//{
	//	for (auto b : a)
	//	{
	//		cout << b << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << maxLen * maxLen << '\n';

	return 0;
}