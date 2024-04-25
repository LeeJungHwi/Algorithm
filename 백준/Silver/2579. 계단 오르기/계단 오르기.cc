#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 계단 오르기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 1.계단은 1 or 2 칸씩 오를 수 있음
	// 2.연속된 세 개의 계단을 모두 밟으면 안됨
	// 3.마지막 도착계단은 무조건 밟아야함
	
	// 게임에서 얻을 수 있는 점수의 최댓값 구하기

	int n; // N 6
	cin >> n;

	// 1 => 10 => score[1]
	// 2 => 30 => score[1] + score[2]
	// 3 => 35 => max(score[1] + score[3], score[2] + score[3]);
	// 4 => 55 => max(score[1] + score[2] + score[4], score[1] + score[3] + score[4])
	// 5 => 10 20 25 10, 20 15 10 => 65 => max(score[i] + score[i - 1] + dp[i - 3], score[i] + dp[i - 2])
	// 6 => 20 15 10 20, 10 20 25 20 => 75 => max(score[i] + score[i - 1] + dp[i - 3], score[i] + dp[i - 2])
	// 3칸 이전까지 밟고 1칸 이전 밟고 도착계단 밟거나 
	// 2칸 이전까지 밟고 도착계단 밟은것중 최댓값

	vector<int> score(n + 1); // 10 20 15 25 10 20
	for (int i = 1; i < n + 1; i++) cin >> score[i];
	vector<int> dp(n + 1); // 각 계단을 도착계단으로 했을때 얻을 수 있는 점수 최대값 저장
	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	dp[3] = max(score[1] + score[3], score[2] + score[3]);
	dp[4] = max(score[1] + score[2] + score[4], score[1] + score[3] + score[4]);

	for (int i = 5; i < n + 1; i++)
	{
		dp[i] = max(score[i] + score[i - 1] + dp[i - 3], score[i] + dp[i - 2]);
	}

	cout << dp[n] << '\n';

	return 0;
}