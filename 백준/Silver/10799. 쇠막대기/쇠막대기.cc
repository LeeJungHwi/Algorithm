#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0; // 막대 개수
	int ans = 0; // 잘려진 막대 개수
	char pre = 'A'; // 이전괄호를 저장하기위해
	string s = {};
	cin >> s;
	for (auto c : s)
	{
		if (c == '(') // ( 이면
		{
			cnt++; // 막대 증가
		}
		else // ) 이면
		{
			if (pre == '(') // 이전괄호가 ( 이면 레이저
			{
				cnt--; // 막대 감소
				ans += cnt; // 잘려진 막대 증가
			}
			else // 이전괄호가 ) 이면 막대의 끝
			{
				cnt--; // 막대 감소
				ans++; // 잘려진 막대 증가
			}
		}
		pre = c; // 이전괄호 저장
	}
	cout << ans << '\n';
}