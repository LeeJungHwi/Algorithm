#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 집
struct House
{
	int costR; // 빨강 비용
	int costG; // 초록 비용
	int costB; // 파랑 비용

	// 생성자
	House() {}
	House(int r, int g, int b) : costR(r), costG(g), costB(b) {}
};

// RGB 거리
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 1번 집의 색은 2번 집의 색과 달라야함
	// N번 집의 색은 N - 1번 집의 색과 달라야함
	// i번 집의 색은 i - 1번, i + 1번 집의 색과 달라야함
	
	// 모든 집을 칠하는 비용의 최솟값 구하기

	int n; // N 3
	cin >> n;

	vector<House> house(n + 1); // (26, 40, 83) (49, 60, 57) (13, 89, 99)
	int r, g, b;
	for (int i = 1; i < n + 1; i++)
	{
		cin >> r >> g >> b;

		house[i] = House(r, g, b);
	}
	vector<vector<int> > dp(n + 1, vector<int>(3)); // 각 집을 각 색으로 칠했을때 최소비용 저장
	dp[1][0] = house[1].costR;
	dp[1][1] = house[1].costG;
	dp[1][2] = house[1].costB;

	for (int i = 2; i < n + 1; i++)
	{
		// 현재 집을 빨강으로 칠했을때
		dp[i][0] = house[i].costR + min(dp[i - 1][1], dp[i - 1][2]);

		// 현재 집을 초록으로 칠했을때
		dp[i][1] = house[i].costG + min(dp[i - 1][0], dp[i - 1][2]);

		// 현재 집을 파랑으로 칠했을때
		dp[i][2] = house[i].costB + min(dp[i - 1][0], dp[i - 1][1]);
	}

	// 마지막 집을 각 색으로 칠한것 중 최소비용 출력
	cout << min({ dp[n][0], dp[n][1], dp[n][2] }) << '\n';

	return 0;
}