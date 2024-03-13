#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n, m; // N, M 4, 2
vector<int> sequence; // 수열 저장

// DFS
void DFS(int L, int start)
{
	if (L == m) // 종료조건 : M개를 뽑은 경우
	{
		// 수열 출력
		for (int i = 0; i < sequence.size(); i++)
		{
			cout << sequence[i] << ' ';
		}

		cout << '\n';
	}
	else
	{
		for (int i = start; i < n + 1; i++)
		{
			sequence.push_back(i); // 숫자 선택
			DFS(L + 1, i); // 다음자리 재귀호출
			sequence.pop_back(); // 숫자 미선택
		}
	}
}

// N과 M (4)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	// DFS
	DFS(0, 1);

	return 0;
}
