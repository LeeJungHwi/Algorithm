#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// 문자열 압축 해제
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString; // 입력문자열 2(ab)(k)3(bc)
	cin >> inputString;

	stack<char> s; // 스택

	string result = ""; // 압축해제 문자열

	for (int i = 0; i < inputString.size(); i++)
	{
		// 스택에 닫는괄호 전까지 저장
		// 스택에서 여는괄호까지 꺼내서 괄호를 제외한 문자를 문자열에 저장
		// 숫자횟수만큼 문자열 추가(숫자가 없다면 한번만 추가)

		if (inputString[i] == ')') // 닫는괄호를 만나면
		{
			string temp = ""; // 임시 문자열

			while (s.top() != '(') // 여는괄호가 나올 때까지 스택의 요소를 문자열에 저장 ab
			{
				temp = s.top() + temp;
				s.pop();
			}

			s.pop(); // 여는괄호 스택에서 제거

			// 숫자 확인 후 해당 문자열을 숫자만큼 반복해서 문자열에 저장

			string repeatCntStr = ""; // 반복횟수 문자열

			// 숫자를 모두 꺼내 문자열 저장 2
			while (!s.empty())
			{
				repeatCntStr = s.top() + repeatCntStr;
				s.pop();
			}

			int repeatCnt = 0; // 반복횟수

			if (!repeatCntStr.empty()) // 반복횟수가 있다면 문자열을 정수로 변환 2
			{
				repeatCnt = stoi(repeatCntStr);
			}
			else // 숫자가 없다면 한번만 반복
			{
				repeatCnt = 1;
			}

			// 반복횟수만큼 압축해제 문자열에 저장 abab
			for (int j = 0; j < repeatCnt; j++)
			{
				result.append(temp);
			}
		}
		else // 닫는괄호를 만나기전까지 스택에 저장 2(ab
		{
			s.push(inputString[i]);
		}
	}

	// 압축해제 문자열 출력
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
	}

	return 0;
}
