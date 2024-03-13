#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n, m; // N, M 4, 2
vector<int> nums; // 처음 N개의 자연수 저장
vector<bool> vis(9); // 방문체크

// DFS
void DFS(int L, int cnt)
{
	if (L == n || cnt == m) // 종료조건 : 뽑을수있는 수를 넘기거나 M개를 뽑은경우
	{
		if (L == n) // 뽑을수있는 수를 넘긴 경우
		{
			if (cnt != m) // M개를 뽑은경우가 아니면 리턴
			{
				return;
			}
		}
		// 선택한 수 출력
		for (int i = 0; i < nums.size(); i++)
		{
			if (vis[i])
			{
				cout << nums[i] << ' ';
			}
		}

		cout << '\n';
	}
	else
	{
		vis[L] = true; // 선택
		DFS(L + 1, cnt += 1);
		vis[L] = false; // 미선택
		DFS(L + 1, cnt -= 1);
	}
}

// N과 M (6)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int num; // 숫자

	// 9 8 7 1
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		nums.push_back(num);
	}

	// sort
	sort(nums.begin(), nums.end());

	// DFS
	DFS(0, 0);

	return 0;
}
