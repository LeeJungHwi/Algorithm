#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 걸그룹 마스터 준석이
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 3, 4
	cin >> n >> m;

	map<string, string> girlGroup; // (이름, 팀이름)
	string team; // 팀 이름
	int memberCnt; // 멤버 수
	string name; // 이름

	while (n--)
	{
		cin >> team >> memberCnt; // twice, 9

		while (memberCnt--)
		{
			//	jihyo
			//	dahyeon
			//	mina
			//	momo
			//	chaeyoung
			//	jeongyeon
			//	tzuyu
			//	sana
			//	nayeon
			cin >> name;

			girlGroup[name] = team;
		}
	}

	// 첫줄에 팀이름 또는 멤버이름이 주어짐
	// 둘째줄에 퀴즈의 종류가 주어짐, 0은 팀멤버 사전순으로 출력, 1은 해당 멤버가 속한 팀이름 출력

	string inputName; // 팀이름 또는 멤버이름
	int quizType; // 퀴즈 종류

	while (m--)
	{
		cin >> inputName >> quizType; // sana, 1

		// 0은 입력된 팀의 멤버 사전순으로 출력
		if (quizType == 0)
		{
			for (auto it = girlGroup.begin(); it != girlGroup.end(); it++)
			{
				if (it->second == inputName) // 같은팀이면 출력
				{
					cout << it->first << '\n';
				}
			}
		}
		else // 1은 해당 멤버가 속한 팀이름 출력 
		{
			cout << girlGroup[inputName] << '\n';
		}
	}

	return 0;
}