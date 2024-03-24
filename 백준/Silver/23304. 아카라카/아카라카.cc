#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int cnt; // 길이가 1이 될때까지 팰린드롬이 아닌 횟수

// DFS
bool DFS(string s)
{
	if (s.size() == 1) // 종료조건 : 길이가 1이면 아카라카팰린드롬 akbrbka
	{
		return true;
	}
	else
	{
		int first = 0;
		int last = s.length() - 1;

		while (first < last)
		{
			if (s[first] != s[last])
			{
				cnt++; // 팰린드롬이 아닌 횟수 카운팅

				return false;
			}

			first++;
			last--;
		}

		// 접두사와 접미사에 대해 재귀호출

		string prefix = s.substr(0, s.length() / 2);
		string suffix = s.substr(s.length() - s.length() / 2, s.length() / 2);

		bool isPrefix = DFS(prefix);
		bool isSuffix = DFS(suffix);

		return isPrefix && isSuffix;
	}
}

// 아카라카
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 아카라카 팰린드롬
	// 1. 입력문자열이 팰린드롬임
	// 2. 입력문자열 / 2 하한 길이의 접두사 접미사 둘다 아카라카 팰린드롬임
	// 입력문자열 길이가 1이면 아카라카 팰린드롬임

	// 입력문자열이 아카라카 팰린드롬이면 AKARAKA를 출력함
	// 입력문자열이 아카라카 팰린드롬이 아니면 IPSELENTI를 출력함

	string inputString; // 입력문자열 akaraka
	cin >> inputString;

	// DFS
	DFS(inputString);

	// 팰린드롬이 아닌 횟수가 0이면 AKARAKA
	cout << (cnt == 0 ? "AKARAKA" : "IPSELENTI");

	return 0;
}
