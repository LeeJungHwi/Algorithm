#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 이동순서를 저장 할 큐
queue<pair<int, int> > q;

// 하노이탑 이동순서 출력하는 함수
int Hanoi(int n, int from, int temp, int to)
{
	if (n == 1) // 원판이 1개일때 바로감
	{
		q.push({ from, to });
		return 1; // 1 개 옮김
	}
	else // 아니면 
	{
		int cnt1 = Hanoi(n - 1, from, to, temp); // 나머지 원판을 from에서 임시막대로 이동함
		q.push({ from, to });
		int cnt2 = Hanoi(n - 1, temp, from, to); // 나머지 원판을 임시막대에서 to로 이동함
		return cnt1 + 1 + cnt2; // cnt1 + 1 + cnt2 개 옮김
	}
}

// 하노이탑 이동 순서 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	int cnt = Hanoi(n, 1, 2, 3); // 하노이탑 이동횟수

	cout << cnt << '\n';

	// 하노이탑 이동순서 출력
	while (!q.empty())
	{
		cout << q.front().first << ' ' << q.front().second << '\n';
		q.pop();
	}

	return 0;
}