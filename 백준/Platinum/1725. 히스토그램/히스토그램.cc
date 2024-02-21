#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

// 히스토그램
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<long long> heights(n); // 막대그래프 높이 저장

	for (int i = 0; i < n; i++)
	{
		cin >> heights[i]; // 2 1 4 5 1 3 3
	}

	stack<long long> s;
	long long maxRec = 0; // 직사각형 최대넓이

	// 히스토그램에서 가장 큰 직사각형의 넓이 구하기
	// 스택의 탑보다 작거나같은 막대를 만나면
	// 현재막대를 기준으로 왼쪽을 보면서 직사각형 최대값 갱신
	// 0 push
	// 1 -> height 2, 0 pop, width 1, maxRec 2, 1 push
	// 2 push
	// 3 push
	// 4 ->
	// height 5, 3 pop, width 4 - 2 - 1 = 1, maxRec 5
	// height 4, 2 pop, width 4 - 1 - 1 = 2, maxRec 8, 4 push
	// 5 push
	// 6 -> height 3, 5 pop, width 6 - 4 - 1 = 1, maxRec 8, 6 push
	// 7(i==n) -> height 3, 6 pop, width 7 - 4 - 1 = 2, maxRec 8, 7 push
	
	for (int i = 0; i < n + 1; i++) // 각 막대를 돌면서 : 마지막 막대까지 처리하기위해 n까지 돌음
	{
		// 1.현재 막대 높이가 스택 탑보다 크면 막대의 인덱스만 저장
		// 2.현재 막대 높이가 스택 탑보다 작거나같다면 스택에서 막대를 빼면서 직사각형 만듬
		// 2-1.빼낸 막대의 높이를 이 직사각형의 높이로하고 해당막대의 너비를 계산함
		//     이때 너비는 현재막대의 인덱스와 스택 탑의 인덱스를 이용해 계산함
		// 2-2.스택이 비었다면 너비는 현재막대의 인덱스가됨
		//     비어있지않다면 스택 탑의 인덱스를 이용해 계산함
		// 2-3.각 직사각형의 넓이를 계산하면서 최대값 갱신

		// 일단 스택이 비어있지 않아야 하고
		// n번째 막대거나 현재 막대 높이가 스택 탑보다 작거나같다면
		while (!s.empty() && (i == n || heights[i] <= heights[s.top()]))
		{
			// 빼낸 막대의 높이를 직사각형의 높이로함
			long long height = heights[s.top()];
			s.pop();

			// 너비는 스택이 비어있으면 현재막대의 인덱스로
			// 스택이 비어있지않다면 현재막대 인덱스 - 스택 탑 - 1
			long long width = s.empty() ? i : i - s.top() - 1;

			// 직사각형 최대넓이 갱신
			maxRec = max(maxRec, height * width);
		}

		s.push(i); // 막대의 인덱스 저장
	}

	cout << maxRec << '\n';

	return 0;
}
