#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <fstream>
using namespace std;

// 서로 다른 부분 문자열 개수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 입력 문자열 ababc
	string inputString;
	cin >> inputString;

	// 중복되지 않는 부분 문자열 저장
	set<string> subString;

	// 중복되지 않는 부분 문자열 생성
	// a
	// ab
	// aba
	// abab
	// ababc
	// b
	// ba
	// bab
	// babc
	// a
	// ab
	// abc
	// b
	// bc
	// c
	for (int i = 0; i < inputString.size(); i++)
	{
		string temp = "";

		for (int j = i; j < inputString.size(); j++)
		{
			temp += inputString[j];
			subString.insert(temp);
		}
	}

	// 중복되지 않는 부분 문자열 개수 출력
	cout << subString.size() << '\n';

	return 0;
}
