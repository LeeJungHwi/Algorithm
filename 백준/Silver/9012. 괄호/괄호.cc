#include <bits/stdc++.h>
using namespace std;
int main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//int N; // 큐의 크기
	//int M; // 뽑아내려고 하는 수의 개수
	//cin >> N >> M;

	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		string a;
		cin >> a;
		stack<char> s; // 스택 선언
		bool isValid = true; // 올바른 괄호 쌍인지 체크하는 변수
		for (auto c : a)
		{
			if (c == '(') // ( 이면
				s.push(c); // 스택에 여는 괄호 추가
			else if (c == ')') // ) 이면
			{
				if (s.empty() || s.top() != '(') // 스택이 비어있거나 스택의 top이 ( 가 아닌경우
				{
					isValid = false; // 올바르지 않은 괄호 쌍
					break;
				}
				s.pop(); // 스택의 top이 짝이 맞는 괄호일경우 pop
			}
		}
		if (!s.empty()) // 스택에 괄호가 남아있으면
			isValid = false; // 올바르지 않은 괄호 쌍
		if (isValid) // 스택이 올바른 괄호 쌍이면
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}