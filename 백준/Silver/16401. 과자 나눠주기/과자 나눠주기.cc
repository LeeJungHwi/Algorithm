#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 과자 나눠주기
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int m, n; // M, N 3, 10
	cin >> m >> n;

	// 과자 길이 1 2 3 4 5 6 7 8 9 10
	vector<int> snacks(n);

	for (int i = 0; i < n; i++)
	{
		cin >> snacks[i];
	}

	sort(snacks.begin(), snacks.end());

	// 이진탐색

	int first = 1; // 처음
	int last = snacks.back(); // 마지막
	int maxLen = 0; // 최대길이

	while (first <= last) // 역전되면 종료
	{
		int standard = (first + last) / 2; // 기준값

		bool isLen = false; // 기준값 길이의 과자를 m 명에게 나눠줄수있는지 체크

		long long cnt = 0; // 나눠준 횟수

		// 각 과자길이 돌면서 몇명에게 나눠줄수있는지 체크
		for (int i = 0; i < snacks.size(); i++)
		{
			cnt += snacks[i] / standard;

			// m명 이상 나눠줄수있으면 break
			if (cnt >= m)
			{
				isLen = true;

				break;
			}
		}

		// 나눠줄수있다면
		if (isLen)
		{
			maxLen = standard; // 최대길이 갱신
			first = standard + 1; // 처음 갱신
		}
		else // 나눠줄수없다면
		{
			last = standard - 1; // 마지막 갱신
		}
	}

	cout << maxLen << '\n'; // 최대 길이 출력

	return 0;
}