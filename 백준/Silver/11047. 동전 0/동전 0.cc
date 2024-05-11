#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 동전 0
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K 10, 4200
	cin >> n >> k;

	vector<long long> coins(n); // 1 5 10 50 100 500 1000 5000 10000 50000
	for (int i = 0; i < n; i++) cin >> coins[i];

	long long minCnt = 0;

	// 최대 가치 동전 부터 나눔
	for (int i = n - 1; i > -1; i--)
	{
		minCnt += k / coins[i];
		k %= coins[i];
	}

	cout << minCnt << '\n';

	return 0;
}