#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	deque<int> DQ; // 덱 선언
	int n;
	cin >> n; // 명령어 갯수 잊력
	while(n--)
	{
		string q;
		cin >> q; // 명령어 입력
		if(q=="push_back") // push_back이면
		{
			int val;
			cin >> val;
			DQ.push_back(val); // 입력받은 정수를 덱 뒤쪽에 추가
		}
		else if(q=="push_front") // push_front이면
		{
			int val;
			cin >> val;
			DQ.push_front(val); // 입력받은 정수를 덱 앞쪽에 추가
		}
		else if(q=="pop_front") // pop_front이면
		{
			if(DQ.empty())
				cout << -1 << '\n'; // 덱이 비어있으면 -1 출력
			else
			{
				cout << DQ.front() << '\n'; // 덱 앞쪽 요소 출력
				DQ.pop_front(); // 덱 앞쪽 요소 제거
			}
		}
		else if(q=="pop_back") // pop_back이면
		{
			if(DQ.empty())
				cout << -1 << '\n'; // 덱이 비어있으면 -1 출력
			else
			{
				cout << DQ.back() << '\n'; // 덱 뒤쪽 요소 출력
				DQ.pop_back(); // 덱 뒤쪽 요소 제거
			}
		}
		else if(q=="size") // size이면
			cout << DQ.size() << '\n'; // 덱의 사이즈 출력
		else if(q=="empty") // empty이면
			cout << DQ.empty() << '\n'; // 비어있으면 1, 아니면 0 출력
		else if(q=="front") // front이면
		{
			if(DQ.empty()) 
				cout << -1 << '\n'; // 덱이 비어있으면 -1 출력
			else
				cout << DQ.front() << '\n'; // 덱의 앞쪽 요소 출력
		}
		else
		{
			if(DQ.empty())
				cout << -1 << '\n'; // 덱이 비어있으면 -1 출력
			else
				cout << DQ.back() << '\n'; // 덱의 뒤쪽 요소 출력
		}
	}
}