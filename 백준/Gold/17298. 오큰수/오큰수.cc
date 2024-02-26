#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

// 오큰수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 크기가 N인 수열 A
	// Ai에 대해서 오큰수 NGE(i)를 구해야함
	// Ai의 오큰수는 오른쪽에있으면서 Ai보다 큰 수 중 가장 왼쪽에 있는 수, 없으면 -1
	// NGE(1) ~ NGE(N) 출력하기

	int n; // N 4
	cin >> n;

	vector<int> inputNums(n); // 입력숫자 저장
	vector<int> result(n); // 각 숫자의 오큰수 저장
	
	// 3 5 2 7
	for (int i = 0; i < n; i++)
	{
		cin >> inputNums[i];
	}

	stack<int> s;

	// 0(3) push
	// 1(5) -> result[0] = 5, 0 pop, 1 push
	// 2(2) push
	// 3(7)
	// -> result[2] = 7, 2 pop
	// -> result[1] = 7, 1 pop, 3 push

	// 현재숫자의 오른쪽에 있으면서 현재숫자보다 큰 수 중 왼쪽에있는 수 저장
	for (int i = 0; i < n; i++)
	{
		// 현재숫자가 스택탑보다 크면
		// 현재숫자가 스택탑의 오큰수이므로 저장 후 pop
		while (!s.empty() && inputNums[s.top()] < inputNums[i])
		{
			result[s.top()] = inputNums[i];
			s.pop();
		}

		// 현재탑 인덱스 저장
		s.push(i);
	}

	// 오큰수를 전부 찾았는데 오큰수가 0인것은 -1로
	for (int i = 0; i < n; i++)
	{
		if (result[i] == 0)
		{
			result[i] = -1;
		}
	}

	// 수신한 결과 출력
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}

	return 0;
}