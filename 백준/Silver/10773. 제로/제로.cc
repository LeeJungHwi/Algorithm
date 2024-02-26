#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int sum = 0;
	int K;
	cin >> K;
	stack<int> s = {};
	while (K--)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			s.pop();
		}
		else
		{
			s.push(n);
		}
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum;
}