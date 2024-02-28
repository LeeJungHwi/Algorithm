#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// 카드2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 6
	cin >> n;

	queue<int> q; 

	// 큐에 1~N 저장
	for (int i = 1; i < n + 1; i++)
	{
		q.push(i); // 1 2 3 4 5 6
	}

	// 큐에 카드가 한장이면 종료
	while (true)
	{
		// 큐에 카드가 한장이면 종료
		if (q.size() == 1)
		{
			break;
		}
		
		// 가장 위에있는 카드를 삭제
		q.pop();

		// 큐에 카드가 한장이면 종료
		if (q.size() == 1)
		{
			break;
		}

		// 가장 위에있는 카드를 저장
		q.push(q.front());
		q.pop();
	}

	// 마지막 남은 카드 출력
	cout << q.front() << '\n';

	return 0;
}