#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 영어단어 복구
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	string input; // 입력 단어
	getline(cin, input); // 공백 포함 읽음

	string result; // 정상 단어

	// 소문자는 그대로 append
	// 대문자는 소문자로 append
	int gap = 'A' - 'a'; // 대문자 소문자 차이

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'a' && input[i] <= 'z') // 소문자
		{
			result.append(1, input[i]);
		}
		else if (input[i] >= 'A' && input[i] <= 'Z') // 대문자
		{
			result.append(1, input[i] - gap);
		}
	}

	cout << result << '\n';

	return 0;
}

// 핵심
// getling(cin, string) -> 공백을 포함한 string을 읽음
// string.append(n, 'a') -> string 뒤에 n개의 a를 붙임