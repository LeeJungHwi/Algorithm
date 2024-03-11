#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n, m; // N, M 4, 2
vector<int> nums; // 수열

// DFS
void DFS(int L)
{
	if (L == m) // 종료조건 : N개를 선택
	{
		// 수열 출력
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << ' ';
		}

		cout << '\n';
	}
	else
	{
		// 중복허용 : vis 없앰
		for (int i = 1; i < n + 1; i++)
		{
			nums.push_back(i);
			DFS(L + 1);
			nums.pop_back();
		}
	}
}

// N과 M (3)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	// DFS
	DFS(0);

	return 0;
}