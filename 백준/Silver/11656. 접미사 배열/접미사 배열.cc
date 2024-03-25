#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 접미사 배열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 입력문자열을 front부터 하나씩 제거해가면서 벡터에 저장
	// 정렬 후 출력

	vector<string> suffixVec; // 접미사들 저장
	string inputString;
	cin >> inputString;

	// 입력문자열을 front부터 하나씩 제거해가면서 벡터에 저장
	int inputStringSize = inputString.size();

	for (int i = 0; i < inputStringSize; i++)
	{
		suffixVec.push_back(inputString);

		inputString.erase(0, 1);
	}

	// 정렬 후 출력
	sort(suffixVec.begin(), suffixVec.end());

	for (int i = 0; i < suffixVec.size(); i++)
	{
		cout << suffixVec[i] << '\n';
	}

	return 0;
}