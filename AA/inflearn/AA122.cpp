#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <fstream>
using namespace std;

// 중복된 문자 제거
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string inputString; // 입력문자열 CbDBEaCEb
	cin >> inputString;

	map<char, int> alphaCnt; // 알파벳 개수
	map<char, bool> vis; // 문자 방문체크

	string result = ""; // 결과 문자열

	for (int i = 0; i < inputString.size(); i++)
	{
		// 입력문자열을 대문자로
		if (islower(inputString[i]))
		{
			inputString[i] = toupper(inputString[i]); // CBDBEACEB
		}

		alphaCnt[inputString[i]]++; // 각 문자의 개수 카운트
	}

	for (int i = 0; i < inputString.size(); i++)
	{
		if (!vis[inputString[i]]) // 방문하지 않은 문자인 경우
		{
			// 결과문자열이 비어있지않으면서
			// 결과문자열의 마지막문자가 현재문자보다 사전적으로 뒤에 있으면서
			// 제거해도 뒤에 같은 문자가 적어도 1개는 남아있는경우
			// 결과문자열의 마지막문자 방문체크 해제 후 제거
			while (!result.empty() && result.back() > inputString[i] && alphaCnt[result.back()] > 0)
			{
				vis[result.back()] = false;
				result.pop_back();
			}

			// 현재문자 결과문자열에 추가 후 방문체크
			result.push_back(inputString[i]);
			vis[inputString[i]] = true;
		}

		// 처리한 문자의 개수 감소
		alphaCnt[inputString[i]]--;
	}

	cout << result; // BDACE

	return 0;
}
