#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 단어 뒤집기 2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 1. 소문자, 숫자, 공백, 특문 으로 이루어짐
	// 2. 문자열의 시작과 끝은 공백이 아님
	// 3. <> 내부 문자열은 단어가 아님

	// 입력문자열 내부 단어를 뒤집어서 출력하기

	string inputString; // 입력문자열 <problem>17413<is hardest>problem ever<end>
	getline(cin, inputString);
	inputString += ' '; // 마지막 단어도 처리하기위해

	// 입력문자열 돌면서 추가하다가
	// >를 만나면 그냥 출력
	// <를 만나면 뒤집어서 출력
	// 태그 내부 상태가 아니면서 공백을 만나면 뒤집어서 출력

	string reverseString; // 뒤집어서 출력할 문자열
	bool isTag = false; // 현재 태그안에 있는 상태인지 체크

	// <problem>31471<is hardest>melborp reve<end>
	for (int i = 0; i < inputString.size(); i++)
	{
		if (inputString[i] == '>') // >를 만나면 그냥 출력
		{
			reverseString += inputString[i];
			cout << reverseString;
			reverseString = "";
			isTag = false;

			continue;
		}
		else if (inputString[i] == '<') // <를 만나면 뒤집어서 출력
		{
			reverse(reverseString.begin(), reverseString.end());
			cout << reverseString;
			reverseString = "";
			reverseString += inputString[i];
			isTag = true;

			continue;
		}
		else if (!isTag && inputString[i] == ' ') // 태그 내부 상태가 아니면서 공백을 만나면 뒤집어서 출력
		{
			reverse(reverseString.begin(), reverseString.end());
			reverseString += inputString[i];
			cout << reverseString;
			reverseString = "";

			continue;
		}

		reverseString += inputString[i];
	}

	return 0;
}