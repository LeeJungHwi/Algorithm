#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 문서 검색
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string docu; // 문서 문자열 ababababa
	string word; // 찾고자하는 단어 aba

	getline(cin, docu);
	getline(cin, word);

	// 문서를 읽으면서 뒤에서 찾고자하는 단어 크기만큼 뽑아내서
	// 찾고자하는 단어와 같으면 찾은횟수 카운팅 하고
	// 중복 카운팅 방지를 위해 문자를 1로 바꿈

	int findCnt = 0; // 단어를 찾은 횟수

	for (int i = word.size() - 1; i < docu.size(); i++)
	{
		if (docu.substr(i - word.size() + 1, word.size()) == word)
		{
			findCnt++;
			
			for (int j = i - word.size() + 1; j < i + 1; j++)
			{
				docu[j] = 1;
			}
		}
	}

	cout << findCnt << '\n';

	return 0;
}