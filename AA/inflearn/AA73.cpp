#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

// 최대힙
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	priority_queue<int> maxHeap;

	int num; // 숫자

	while (true)
	{
		cin >> num;

		if (num == -1) // -1 입력시 종료
		{
			return 0;
		}

		if (num != 0) // 0이 아니면 자연수 push
		{
			maxHeap.push(num);
		}
		else // 0이면 최대값 출력, 큐가 비었으면 -1 출력
		{
			if (maxHeap.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << maxHeap.top() << '\n';
				maxHeap.pop();
			}
		}
	}
}
// 핵심
// 우선순위 큐