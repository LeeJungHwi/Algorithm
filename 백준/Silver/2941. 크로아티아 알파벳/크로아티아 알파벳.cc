#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 크로아티아 알파벳
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// ljes=njak
	string word;
	cin >> word;

	// 단어를 읽으면서
	// c를 만나면 1.다음문자가 = 또는 - 이면 건너뜀
	// d를 만나면 1.다음문자가 - 이면 건너뜀 2.다음문자가 z= 이면 두번 건너뜀
	// l 또는 n을 만나면 1.다음문자가 j 이면 건너뜀
	// s 또는 z를 만나면 1.다음문자가 = 이면 건너뜀
	// 나머지 문자는 그냥 카운팅

	int alphaCnt = 0; // 알파벳 개수

	for (int i = 0; i < word.size(); i++) // 단어 읽으면서
	{
		if (word[i] == 'c') // c를 만나면
		{
			if (i < word.size() - 1 && (word[i + 1] == '=' || word[i + 1] == '-')) // 다음문자가 = 또는 - 이면 건너뜀
			{
				i++;
			}
		}
		else if (word[i] == 'd') // d를 만나면
		{
			if (i < word.size() - 1)
			{
				if (word[i + 1] == '-') // 다음문자가 - 이면 건너뜀
				{
					i++;
				}
				else if (i < word.size() - 2 && word[i + 1] == 'z' && word[i + 2] == '=') // 다음문자가 z= 이면 두번 건너뜀
				{
					i++;
					i++;
				}
			}
		}
		else if (word[i] == 'l' || word[i] == 'n') // l 또는 n을 만나면
		{
			if (i < word.size() - 1 && word[i + 1] == 'j') // 다음문자가 j이면 건너뜀
			{
				i++;
			}
		}
		else if (word[i] == 's' || word[i] == 'z') // s 또는 z를 만나면
		{
			if (i < word.size() - 1 && word[i + 1] == '=') // 다음문자가 =이면 건너뜀
			{
				i++;
			}
		}

		alphaCnt++; // 나머지는 그냥 카운팅
	}

	cout << alphaCnt << '\n';

	return 0;
}