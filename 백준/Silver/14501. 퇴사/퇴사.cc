#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 퇴사
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 최대수입 상담 스케줄링하기

	int n; // N 7
	cin >> n;

	vector<pair<long long, long long> > consultant(n + 1); // (걸리는일수, 수입) (3,10) (5,20) (1,10) (1,20) (2,15) (4,40) (2,200)
	for (int i = 1; i < n + 1; i++) cin >> consultant[i].first >> consultant[i].second;
	vector<long long> dp(n + 2); // 각 i번째 상담을 선택하는경우와 선택하지않는경우 중 최대수입 저장
	long long maxIncome = 0;

	// 마지막 상담부터 역순으로 돌면서(각 상담은 한 번 밖에 못 함)
	for (int i = n; i > 0; i--)
	{
		// 상담이 종료된 다음 날
		int endNextDay = i + consultant[i].first;

		// 퇴사일 이내에 상담을 끝낼 수 있는 경우
		// 현재 상담을 선택하는 경우와 선택하지 않는 경우 중 큰 값을 선택
		// 종료일이 n + 1일까지는 상담이 가능함
		if (endNextDay < n + 2) dp[i] = max(dp[endNextDay] + consultant[i].second, dp[i + 1]);
		// 퇴사일 이후에 상담을 끝낼 수 있는 경우
		// 현재 상담을 선택하지않고 이전 최대수입을 그대로 가져감
		else dp[i] = dp[i + 1];

		// 최대수입 갱신
		maxIncome = max(maxIncome, dp[i]);
	}

	cout << maxIncome << '\n';

	return 0;
}