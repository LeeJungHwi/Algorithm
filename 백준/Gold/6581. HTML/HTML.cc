#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// HTML
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// 1.일단 벡터에 모든 단어 저장
	// 2.저장된 단어 돌면서
	// <br>이면 개행
	// <hr>이면 해당 줄에 단어가 있으면 개행 -80 개행, 해당 줄에 단어가 없으면 -80 개행
	// 나머지 단어는 해당 줄에 있는 단어의 길이 + 현재 쓸 단어의 길이가 80을 넘으면 개행 후 출력

	// 1.일단 벡터에 모든 단어 파싱해서 저장

	vector<string> words;
	string word;

	while (true)
	{
		if (!(cin >> word)) // 더 이상 단어가 없으면 break
		{
			break;
		}

		words.push_back(word);
	}

	// 2.저장된 단어 돌면서
	// <br>이면 개행
	// <hr>이면 해당 줄에 단어가 있으면 개행 -80 개행, 해당 줄에 단어가 없으면 -80 개행
	// 나머지 단어는 해당 줄에 있는 단어의 길이 + 현재 쓸 단어의 길이가 80을 넘으면 개행
	// 해당 줄에 단어가 있으면 공백 출력 후 단어 출력, 아니면 그냥 출력

	int charCnt = 0; // 글자 개수

	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == "<br>") // <br>이면
		{
			// 개행
			cout << '\n';

			charCnt = 0;
		}
		else if (words[i] == "<hr>") // <hr>이면
		{
			// 해당 줄에 단어가 있으면 개행
			if (charCnt > 0)
			{
				cout << '\n';

				charCnt = 0;
			}

			// -80 개행
			cout << "--------------------------------------------------------------------------------\n";
		}
		else // 나머지 단어면
		{
			// 해당 줄에 있는 단어의 길이 + 현재 쓸 단어의 길이가 80을 넘으면
			if (charCnt + words[i].size() + 1 > 80)
			{
				// 개행
				cout << '\n';

				charCnt = 0;
			}

			// 해당 줄에 단어가 있으면 공백 출력 후 단어 출력
			if (charCnt > 0)
			{
				cout << ' ';
				charCnt++;
			}

			cout << words[i];
			charCnt += words[i].size();
		}
	}

	return 0;
}
