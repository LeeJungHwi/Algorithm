#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a = "";
	cin >> a;
	stack<char> s = {};
	int ans = 0; // 괄호값
	char pre = 'A'; // 이전괄호 저장
	bool isCorrect = true; // 올바른 괄호인지 체크
	int num = 1; // 곱해질 값
	for (auto c : a)
	{
		if (c == '(')
		{
			s.push(c);
			num *= 2;
		}
		else if (c == '[')
		{
			s.push(c);
			num *= 3;
		}
		else if (c == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				isCorrect = false;
				break;
			}
			if (pre == '(')
				ans += num;
			s.pop();
			num /= 2;
		}
		else
		{
			if (s.empty() || s.top() != '[')
			{
				isCorrect = false;
				break;
			}
			if (pre == '[')
				ans += num;
			s.pop();
			num /= 3;
		}
		pre = c; // 괄호 저장
	}
	if (s.empty() && isCorrect)
	{
		cout << ans;
	}
	else
	{
		cout << 0;
	}
}