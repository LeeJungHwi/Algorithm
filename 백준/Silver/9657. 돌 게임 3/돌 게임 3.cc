#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 돌 게임 3
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 돌을 1개 또는 3개 또는 4개 가져갈 수 있음
	// 마지막 돌을 가져가는 사람이 이김
	// 상근이가 먼저 시작함
	// 이기는 사람 구하기 => SK or CY

	int n; // N 6
	cin >> n;

	vector<bool> dp(n + 1); // 각 돌의 개수가 i개일 때 상근이가 이길 수 있는지 체크

	// 상근이가 먼저 시작 => 1개, 3개, 4개면 상근이가 이김
	dp[1] = true;
	dp[3] = true;
	dp[4] = true;

	// 돌이 5개일 때 부터
	// 이전 상태에서 상근이가 지는 경우
	// 현재 상태는 상근이가 마지막 돌을 가져감
	for (int i = 5; i < n + 1; i++) if (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) dp[i] = true;

	cout << (dp[n] ? "SK" : "CY") << '\n';

	return 0;
}