#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 돌다리 건너기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<int> rocks(n); // 돌다리 저장
	int minCost = 2147000000; // 최소비용 갱신

	// 2 2 50 2 3 50 5
	for (int i = 0; i < n; i++)
	{
		cin >> rocks[i];
	}

	// 1. 첫번째 돌다리 부터 시작하는 경우

	int cost = rocks[0]; // 돌다리 비용
	int standardPos = 0; // 기준위치

	while (true)
	{
		// 종료조건 : n - 2일때 두칸점프하면 밟을돌 없음, n - 1일때 한칸점프하면 밟을돌 없음
		if (standardPos == n - 1 || standardPos == n - 2)
		{
			break;
		}

		// 한칸앞이 더 크거나 같으면 두칸앞이 다음 돌다리 위치
		if (rocks[standardPos + 1] >= rocks[standardPos + 2])
		{
			cost += rocks[standardPos + 2];
			standardPos += 2;
		}
		else // 두칸앞이 더 큰 경우 한칸앞이 다음 돌다리 위치
		{
			cost += rocks[standardPos + 1];
			standardPos += 1;
		}
	}

	// 최소비용 갱신
	minCost = min(minCost, cost);

	// 2. 두번째 돌다리 부터 시작하는 경우

	cost = rocks[1]; // 돌다리 비용
	standardPos = 1; // 기준위치

	while (true)
	{
		// 종료조건 : n - 2일때 두칸점프하면 밟을돌 없음, n - 1일때 한칸점프하면 밟을돌 없음
		if (standardPos == n - 1 || standardPos == n - 2)
		{
			break;
		}

		// 한칸앞이 더 크거나 같으면 두칸앞이 다음 돌다리 위치
		if (rocks[standardPos + 1] >= rocks[standardPos + 2])
		{
			cost += rocks[standardPos + 2];
			standardPos += 2;
		}
		else // 두칸앞이 더 큰 경우 한칸앞이 다음 돌다리 위치
		{
			cost += rocks[standardPos + 1];
			standardPos += 1;
		}
	}

	// 최소비용 갱신
	minCost = min(minCost, cost);

	cout << minCost;

	return 0;
}