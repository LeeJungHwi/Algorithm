#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

// 전투 게임
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 7
	cin >> n;

	vector<pair<char, int> > stuTeam(n + 1); // 각 학생이 속한팀과 공격력 저장
	map<char, vector<int> > atks; // 각 팀에 속해있는 공격력들 저장

	char team; // 팀
	int atk; // 공격력

	for (int i = 1; i < n + 1; i++)
	{
		//a 17
		//b 12
		//a 10
		//c 11
		//b 24
		//a 25
		//b 12
		cin >> team >> atk;

		// (a,17) (b,12) (a,10) (c,11) (b,24) (a,25) (b,12)
		stuTeam[i] = { team,atk };

		//a -> 17 10 25
		//b -> 12 24 12
		//c -> 11
		atks[team].push_back(atk);
	}

	// 팀이 다른경우 공격력 비교 후 점수 누적
	for (int i = 1; i < n + 1; i++)
	{
		int score = 0; // 점수

		// 다른팀만 공격력 비교 후 점수 누적
		for (auto it = atks.begin(); it != atks.end(); it++)
		{
			if (stuTeam[i].first != it->first) // 팀이 다른경우
			{
				for (auto a : it->second) // 각 팀에 속해있는 공격력들을 하나씩 꺼내와서
				{
					if (stuTeam[i].second > a) // 공격력이 더 높다면
					{
						score += a; // 점수 누적
					}
				}
			}
		}

		cout << score << '\n';
	}

	return 0;
}
// 핵심
// map 사용