#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// 최소힙
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	priority_queue<int, vector<int>, greater<int>> minHeap; // 큐는 front로 뻄 -> 오름차순 정렬

	int num; // 숫자

	while (true)
	{
		cin >> num;

		if (num == -1) // -1 입력시 종료
		{
			return 0;
		}
		
		if (num != 0) // 0이 아니면 최소힙에 push
		{
			minHeap.push(num);
		}
		else // 0 입력시 최소값 출력, 큐가 비었으면 -1 출력
		{
			if (minHeap.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << minHeap.top() << '\n';
				minHeap.pop();
			}
		}
	}
}
// 핵심
// 최소힙 : 오름차순 정렬
// push 할때 -num을 push하면 작은값이 루트로 가게되고 출력시 -minHeap.top()을 출력하면 최소힙이 구현됨