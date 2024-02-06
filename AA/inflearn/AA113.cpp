#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 멀티태스킹
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	queue<pair<int, int> > processes; // 작업 저장

	int processTime; // 작업시간

	for (int i = 1; i < n + 1; i++)
	{
		cin >> processTime; // 1 2 3

		processes.push({ i, processTime }); // (i번째작업, 작업시간) -> (1, 1) (2, 2) (3, 3)
	}

	int k; // K 5
	cin >> k;

	// 작업 처리
	while (k > 0 && !processes.empty())
	{
		// 현재 수행해야 할 작업 꺼냄
		pair<int, int> curProcess = processes.front();
		processes.pop();

		// 꺼낸 작업의 작업시간 감소
		curProcess.second -= 1;

		// k 감소
		k--;

		// 만약 작업시간이 0이면 큐에 넣지않고 continue
		if (curProcess.second == 0)
		{
			continue;
		}

		// 작업시간이 남았다면 다시 큐에 push
		processes.push(curProcess);
	}

	// 큐가 비었으면 더 이상 처리할 작업이 없음
	if (processes.empty())
	{
		cout << -1 << '\n';

		return 0;
	}

	cout << processes.front().first << '\n';

	return 0;
}