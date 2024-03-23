#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 여우는 어떻게 울지?
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int tc; // TC 1
	cin >> tc;
	cin.ignore(); // tc 입력 이후 남은 개행 문자 무시

	// 테케만큼 돌면서
	while (tc--)
	{
		// 1.일단 울음소리 전부 읽음
		// toot woof wa ow ow ow pa blub blub pa toot pa blub pa pa ow pow toot ' '
		string allCry; // 모든 울음소리
		getline(cin, allCry);
		allCry += ' '; // 마지막 울음소리까지 체크하기위해

		// 2.각 동물의 울음소리를 맵핑함
		//	dog goes woof
		//	fish goes blub
		//	elephant goes toot
		//	seal goes ow
		//	what does the fox say ?
		map<string, int> cryMap; // 각 동물 울음소리 맵핑
		string inputString; // 입력문자열

		while (true)
		{
			getline(cin, inputString);

			if (inputString == "what does the fox say?") // 마지막 줄이면 break
			{
				break;
			}

			cryMap[inputString.substr(inputString.find("goes ") + 5)]++; // 각 동물의 울음소리 맵핑
		}

		// 3.모든 울음소리 돌면서 맵핑되지않은 울음소리만 출력함

		string cry; // 울음소리

		for (int i = 0; i < allCry.size(); i++)
		{
			if (allCry[i] == ' ') // 공백을 만나면 울음소리 맵핑되지않은 울음소리만 출력
			{
				if (cryMap[cry] == 0)
				{
					cout << cry << ' ';
				}

				cry = "";

				continue;
			}

			cry += allCry[i];
		}

		cout << '\n';
	}

	return 0;
}