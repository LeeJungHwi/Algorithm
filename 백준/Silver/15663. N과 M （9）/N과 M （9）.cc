#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n, m; // N, M 4, 2
map<int, int> nums; // 처음 N개의 자연수 저장
vector<int> sequence; // 수열 저장

// DFS
void DFS(int L)
{
	if (L == m) // 종료조건 : M개를 뽑은 경우
	{
		// 선택한 수 출력
		for (int i = 0; i < sequence.size(); i++)
		{
			cout << sequence[i] << ' ';
		}

		cout << '\n';
	}
	else
	{
		// 맵 돌면서 
		for (auto it = nums.begin(); it != nums.end(); it++)
		{
			if (it->second > 0) // 등장횟수가 남아있다면
			{
				it->second--; // 선택
				sequence.push_back(it->first);
				DFS(L + 1); // 다음 숫자 재귀호출
				sequence.pop_back();
				it->second++; // 미선택
			}
		}
	}
}

// N과 M (9)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int num; // 숫자

	// 9 7 9 1
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		nums[num]++; // (자연수, 등장횟수) 맵핑 -> (1, 1) (7, 1) (9, 2)
	}

	// DFS
	DFS(0);

	return 0;
}
