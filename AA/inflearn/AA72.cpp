#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// 공주구하기(큐)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, k; // N, K
	cin >> n >> k;

	queue<int> princes; // 왕자들 저장

	for (int i = 0; i < n; i++)
	{
		princes.push(i); // 0 1 2 3 4 5 6 7
	}

	while (princes.size() != 1) // 큐에 왕자가 한명남으면 종료
	{
		// front를 push pop k - 1번
		// front를 pop 1번

		for (int i = 0; i < k - 1; i++)
		{
			princes.push(princes.front());
			princes.pop();
		}

		princes.pop();
	}

	cout << princes.front() + 1 << '\n';

	return 0;
}