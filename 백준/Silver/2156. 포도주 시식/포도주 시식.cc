#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 포도주 시식
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 포도주 시식 규칙
	// 1. 잔을 선택하면 해당 잔을 모두 마셔야하고 마신 후 원래 자리에 놓는다
	// 2. 연속으로 놓여있는 3잔을 모두 마실 수 없다
	// 마실 수 있는 포도주의 최댓값 구하기

	int n; // N 6
	cin >> n;

	vector<long long> graph(n + 1); // 각 잔의 양 저장, 6 10 13 9 8 1
	for (int i = 1; i < n + 1; i++) cin >> graph[i];
	vector<long long> dp(n + 1); // 각 잔을 마지막 잔으로 했을때 최댓값 저장

	// 3칸 이전 잔 까지 마시고 1칸 이전 잔 마시고 현재 잔 마시거나
	// 2칸 이전 잔 까지 마시고 현재 잔 마시거나
	// 이전 잔 까지 마셨을때 최댓값 중 최댓값
	// 계단 오르기 문제는 연속된 계단을 올라야 하지만
	// 포도주 시식은 연속된 잔을 안 마셔도 됨

	if (n == 1)
	{
		cout << graph[1] << '\n';
		return 0;
	}

	dp[1] = graph[1];
	dp[2] = graph[1] + graph[2];

	long long maxGraph = graph[1] + graph[2];

	for (int i = 3; i < n + 1; i++)
	{
		dp[i] = max({ graph[i] + graph[i - 1] + dp[i - 3], graph[i] + dp[i - 2], dp[i - 1] });
		maxGraph = max(maxGraph, dp[i]);
	}

	cout << maxGraph << '\n';

	return 0;
}
