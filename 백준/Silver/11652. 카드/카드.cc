#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 카드
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	map<long long, long long> card; // (숫자, 횟수) 맵핑

	long long num; // 숫자

	// (숫자, 횟수) 맵핑
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		card[num]++;
	}

	// 맵 돌면서 횟수 최대값 갱신
	// 횟수가 같으면 갱신하지않음 -> 처음에 갱신된게 더 최대값임

	long long maxCnt = 0;
	long long maxNum = 0;

	for (auto it = card.begin(); it != card.end(); it++)
	{
		if (it->second > maxCnt)
		{
			maxCnt = it->second;
			maxNum = it->first;
		}
	}

	cout << maxNum << '\n';

	return 0;
}