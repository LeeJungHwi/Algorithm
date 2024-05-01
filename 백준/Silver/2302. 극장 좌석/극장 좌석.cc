#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 극장 좌석
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 자기 번호 좌우 까지 앉을 수 있음
	// VIP 회원은 자기 번호만 앉을 수 있음
	// 사람들이 좌석에 앉을 수 있는 방법의 수 구하기

	int n, m; // N, M 9, 2
	cin >> n >> m;

	vector<long long> vip(n + 1); // vip 회원 체크
	int vipNum; // 4, 7
	for (int i = 0; i < m; i++)
	{
		cin >> vipNum;

		vip[vipNum]++;
	}
	vector<long long> dp(n + 1); // i번 좌석 까지 앉을 수 있는 방법 수 저장
	dp[0] = 1; // 아무도 앉지 않는 경우
	dp[1] = 1; // 1번 사람이 앉는 경우

	// 현재 좌석에 이전 dp값 넣어놓고
	// 현재 좌석과 이전 좌석 모두 vip 좌석이 아니면 i - 2 좌석 까지 dp값 누적
	for (int i = 2; i < n + 1; i++)
	{
		dp[i] = dp[i - 1];
		if(vip[i] == 0 && vip[i - 1] == 0) dp[i] += dp[i - 2];
	}

	cout << dp[n] << '\n';

	return 0;
}