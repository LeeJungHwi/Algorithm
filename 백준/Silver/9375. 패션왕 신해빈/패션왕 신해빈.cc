#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 패션왕 신해빈
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int tc; // 테케 2
	cin >> tc;

	// 테케 만큼 돌면서
	while (tc--)
	{
		int n; // N 3
		cin >> n;

		map<string, int> wear; // (타입, 개수)
		string name, type;

		//	hat headgear
		//	sunglasses eyewear
		//	turban headgear
		for (int i = 0; i < n; i++)
		{
			cin >> name >> type;

			wear[type]++;
		}

		// 의상 조합 수, 초기값은 모두 안 입는 경우 1
		int caseCnt = 1;

		// 맵 돌면서 의상 조합 수 *= 해당 타입의 의상 개수 + 1
		for (auto it = wear.begin(); it != wear.end(); it++)
		{
			caseCnt *= it->second + 1;
		}

		// 초기값으로 설정한 모두 안 입는 경우 --
		caseCnt--;

		// 의상 조합 수 출력
		cout << caseCnt << '\n';
	}

	return 0;
}
