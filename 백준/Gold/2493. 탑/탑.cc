#include <bits/stdc++.h>
using namespace std;
int main()
 {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N; // 5
	stack<int> s = {}; // 탑의 높이를 저장할 스택
	stack<int> idx = {}; // 탑의 인덱스를 저장할 스택
	vector<int> ans = {}; // 수신한 탑들의 번호를 저장 할 배열
	int first;
	cin >> first;
	s.push(first); // 첫번째 탑의 높이
	idx.push(1); // 첫번째 탑의 인덱스
	ans.push_back(0); // 첫번째 탑은 수신 할 수 없으므로
	for (int i = 2; i <= N; i++)
	{
		int k;
		cin >> k;
		while (!s.empty())
		{
			if (k < s.top())
			{
				ans.push_back(idx.top());
				break;
			}
			s.pop();
			idx.pop();
		}
		if (s.empty())
		{
			ans.push_back(0);
		}
		s.push(k);
		idx.push(i);
	}
	for (int i : ans)
	{
		cout << i << " ";
	}
}