#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 멀티태스킹
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");
	//freopen("input.txt", "rt", stdin);

	int n; // N 3
	//cin >> n;
	scanf_s("%d", &n);

	vector<int> processTimes(n); // 각 작업을 처리하는데 필요한 시간 저장
	int sumProcessTimes = 0; // 작업시간 총합

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &processTimes[i]); // 1 2 3
		//cin >> processTimes[i]; // 1 2 3
		sumProcessTimes += processTimes[i];
	}

	int k; // K 5
	//cin >> k;
	scanf_s("%d", &k);

	// 첫 작업부터 1초씩 할당
	// 작업 수행을 완료한 작업은 스케쥴링 제외
	// 마지막 작업 수행 후 다시 첫 작업부터 할당
	// k초에 정전 후 몇 번 작업부터 다시 시작해야하는지 구하기
	// 1 2 3
	// 0 2 3
	// 0 1 3
	// 0 1 2
	// 0 0 2
	// 0 0 1

	if (sumProcessTimes <= k) // 프로세스 작업시간 총합이 k 이하면 정전이 풀린 뒤 수행 할 작업이 없음
	{
		//cout << -1 << '\n';
		printf("%d\n", -1);
		return 0;
	}

	while (k > -1) // k초 후 정전이고 정전이 풀린 뒤 다시 시작해야하는 작업은 k가 0일때 수행되므로 k가 0일때도 수행
	{
		for (int i = 0; i < n; i++) // 작업 크기만큼 돌면서
		{
			if (processTimes[i] > 0) // 아직 끝나지 않은 작업만
			{
				if (k == 0) // 정전이 풀린 후 아직 끝나지 않은 작업이 있을때 다시 수행할 작업
				{
					//cout << i + 1 << '\n';
					printf("%d\n", i + 1);
					return 0;
				}

				processTimes[i]--; // 작업 시간 감소
				k--; // k가 0이되면 정전 -> k가 0일때 정전이 풀린 뒤 수행 해야 할 작업
			}

			if (i == n - 1) // 마지막 작업이면 첫 작업으로
			{
				i = -1;
			}
		}
	}
}
// 핵심
// 조세퍼스 문제