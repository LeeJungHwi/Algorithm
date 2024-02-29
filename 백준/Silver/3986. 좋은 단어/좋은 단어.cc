#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <fstream>
using namespace std;

// 좋은 단어
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	string inputString; // 입력문자열

	//	ABAB
	//	AABB
	//	ABBA

	int goodWordCnt = 0; // 좋은단어 개수

	for (int i = 0; i < n; i++)
	{
		cin >> inputString;

		stack<char> curChar; // 현재문자

		// 스택이 비었으면 그냥 push
		// 스택에 요소가 있으면
		// 탑과 같은문자면 pop만하고 push는 ㄴ
		// 탑과 다른문자면 push
		for (int j = 0; j < inputString.size(); j++)
		{
			if (curChar.empty())
			{
				curChar.push(inputString[j]);
			}
			else
			{
				if (inputString[j] == curChar.top())
				{
					curChar.pop();
				}
				else
				{
					curChar.push(inputString[j]);
				}
			}
		}

		// 스택이 비었으면 좋은단어 카운팅
		if (curChar.empty())
		{
			goodWordCnt++;
		}
	}

	cout << goodWordCnt << '\n';

	return 0;
}