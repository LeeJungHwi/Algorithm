#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // N 3
char s[20]; // 괄호문자열
int cnt; // 괄호문자열 개수

// DFS
void DFS(int L, int open, int close)
{
	if (L == n * 2) // 종료조건 : 괄호를 n * 2개 선택한 경우
	{
		// 괄호문자열 출력
		cout << s << '\n';

		// 괄호문자열 개수 증가
		cnt++;
	}
	else
	{
		// 여는 괄호를 추가할 수 있는 경우 : 사용된 여는괄호 개수가 전체 여는괄호 개수보다 작을때
		if (open < n)
		{
			s[L] = '(';
			DFS(L + 1, open + 1, close);
		}

		// 닫는 괄호를 추가할 수 있는 경우 : 사용된 닫는괄호 개수가 사용된 여는괄호 개수보다 작을때
		if (close < open)
		{
			s[L] = ')';
			DFS(L + 1, open, close + 1);
		}
	}
}

// 모든 쌍의 괄호
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	// DFS
	DFS(0, 0, 0);

	cout << cnt;

	return 0;
}
