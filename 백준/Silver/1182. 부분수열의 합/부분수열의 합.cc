#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n, s; // N, M 5, 0
vector<int> nums; // 정수 저장 -7 -3 -2 5 8
vector<bool> vis(20); // 방문체크
int cnt; // 부분수열합이 s가되는 개수

// DFS
void DFS(int L)
{
	if (L == n) // 종료조건 : 선택할수있는 정수 개수를 넘긴경우
	{
		// sum이 s가 되면 개수 카운팅

		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			if (vis[i])
			{
				sum += nums[i];
			}
		}

		if (sum == s)
		{
			cnt++;
		}

		return;
	}
	else
	{
		vis[L] = true; // 선택
		DFS(L + 1);
		vis[L] = false; // 미선택
		DFS(L + 1);
	}
}

// 부분수열 합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> s;

	// -7 -3 -2 5 8

	int num; // 숫자

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		nums.push_back(num);
	}

	// DFS
	DFS(0);
	
	// s가 0이면 cnt - 1 출력
	// 아니면 cnt 출력

	if (s == 0)
	{
		cout << cnt - 1 << '\n';

		return 0;
	}

	cout << cnt << '\n';

	return 0;
}