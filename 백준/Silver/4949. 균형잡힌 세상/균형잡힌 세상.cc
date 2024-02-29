#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(true)
	{
		string a;
		getline(cin, a); // 공백을 포함한 문자열을 입력받는다
		if(a==".") // .이면
			break; // 입력 종료
		stack<char> s; // 스택 선언
		bool isValid = true; // 올바른 괄호 쌍인지 체크하는 변수
		for(auto c : a)
		{
			if(c=='(' || c=='[') // ( 이거나 [ 이면
				s.push(c); // 스택에 여는 괄호 추가
			else if(c==')') // ) 이면
			{
				if(s.empty() || s.top() != '(') // 스택이 비어있거나 스택의 top이 ( 가 아닌경우
				{
					isValid = false; // 올바르지 않은 괄호 쌍
					break;
				}
				s.pop(); // 스택의 top이 짝이 맞는 괄호일경우 pop
			}
			else if(c==']') // ] 이면
			{
				if(s.empty() || s.top() != '[') // 스택이 비어있거나 스택의 top이 [ 가 아닌경우
				{
					isValid = false; // 올바르지 않은 괄호 쌍
					break;
				}
				s.pop(); // 스택의 top이 짝이 맞는 괄호일경우 pop
			}
		}
		if(!s.empty()) // 스택에 괄호가 남아있으면
			isValid = false; // 올바르지 않은 괄호 쌍
		if(isValid) // 스택이 올바른 괄호 쌍이면
			cout << "yes\n";
		else
			cout << "no\n";
	}
}