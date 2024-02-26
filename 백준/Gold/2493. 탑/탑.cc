#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

// 탑
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<int> heights(n); // 각 탑의 높이 저장
	vector<int> result(n); // 각 탑의 레이저를 수신한 탑의 인덱스 저장

	// 6 9 5 7 4
	for (int i = 0; i < n; i++)
	{
		cin >> heights[i];
	}

	stack<int> s;

	// 현재탑의 레이저를 최초로 수신하는 탑의 인덱스 저장
	for (int i = 0; i < n; i++)
	{
		// 현재탑이 스택탑보다 크거나같으면 pop
		// 즉 현재탑보다 높은탑이 나올때까지 pop
		// 현재탑보다 높은탑이 현재탑의 레이저를 최초로 수신함
		while (!s.empty() && heights[s.top()] <= heights[i])
		{
			s.pop();
		}

		// 수신할수있는 탑이없으면 0으로 냅두고
		// 최초로 수신할수있는 탑이 있으면 탑의번호 인덱스 + 1 저장
		if (!s.empty())
		{
			result[i] = s.top() + 1;
		}

		// 현재탑 인덱스 저장
		s.push(i);
	}

	// 수신한 결과 출력
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <stack>
//#include <fstream>
//using namespace std;
//
//// 탑
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int n; // N 5
//	cin >> n;
//
//	vector<int> heights(n); // 탑들의 높이 저장
//	vector<int> result(n); // 수신한 탑의 인덱스 저장
//
//	// 6 9 5 7 4
//	for (int i = 0; i < n; i++)
//	{
//		cin >> heights[i];
//	}
//
//	stack<int> s;
//
//	// 스택에 현재탑의 인덱스를 저장
//	// 스택이 비어있지않으면서
//	// n이거나 현재탑의 높이가 스택 탑보다 작거나같으면 
//	// 현재탑을 기준으로 왼쪽탑을 처리
//	// 0 push
//	// 1 push
//	// 2 ->
//	// height 9, 1 - 1부터0까지 9보다 큰탑의 인덱스 저장, 1 pop
//	// height 6, 0 - 1부터0까지 6보다 큰탑의 인덱스 저장, 0 pop, 2 push
//	// 3 push
//	// 4 ->
//	// height 7, 3부터0까지 7보다 큰탑의 인덱스 저장, 3 pop
//	// height 5, 2부터0까지 5보다 큰탑의 인덱스 저장, 2 pop, 4 push
//	// 5 ->  height 4, 4부터0까지 4보다 큰탑의 인덱스 저장, 5 push
//
//	// n까지 돌아야 모든탑 체크 가능 
//	for (int i = 0; i <= n; i++)
//	{
//		// 스택이 비어있지않으면서 현재탑의 높이가 스택 탑보다 작거나같으면 
//		while (!s.empty() && (i == n || heights[i] <= heights[s.top()]))
//		{
//			int idx = s.top(); // 왼쪽탑 인덱스
//			int height = heights[idx]; // 왼쪽탑 높이
//			bool isFind = false; // 자기보다 높은탑을 찾았는지 체크
//
//			// 왼쪽탑 인덱스 이전인덱스부터 0까지 돌면서
//			for (int j = idx - 1; j > -1; j--)
//			{
//				// 자기보다 높은 탑을 찾으면
//				// 수신결과에 해당탑의 인덱스 저장
//				if (heights[j] > height)
//				{
//					result[idx] = j + 1;
//					isFind = true;
//					break;
//				}
//			}
//
//			// 스택 pop 여기서해줘야함
//			s.pop();
//
//			// 찾았으면 0 출력못하게 continue
//			if (isFind)
//			{
//				continue;
//			}
//
//			// 만약 자신보다 높은탑을 찾지못했으면
//			// 수신결과에 0 저장
//			result[idx] = 0;
//		}
//
//		// 스택에 현재탑의 인덱스 저장
//		s.push(i);
//	}
//
//	// 수신한 결과 출력
//	for (int i = 0; i < n; i++)
//	{
//		cout << result[i] << ' ';
//	}
//
//	return 0;
//}