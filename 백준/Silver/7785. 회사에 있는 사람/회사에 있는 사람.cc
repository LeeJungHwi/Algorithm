#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
using namespace std;

// 회사에 있는사람
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	// enter : 출근
	// leave : 퇴근
	// 회사에 남아있는 사람 구하기

	int n; // N 4
	cin >> n;

	map<string, bool> systemLog; // 시스템 로그
	string name; // 이름
	string enter; // 나갔는지

	//	Baha enter
	//	Askar enter
	//	Baha leave
	//	Artem enter
	for (int i = 0; i < n; i++)
	{
		cin >> name >> enter;
		
		// 들어왔으면 체크
		if (enter == "enter")
		{
			systemLog[name] = 1;
		}
		else
		{
			systemLog[name] = 0;
		}
	}

	// 현재 회사에 있는사람 구하기

	vector<string> enterPerson; // 현재 회사에 있는사람

	for (auto it = systemLog.begin(); it != systemLog.end(); it++) // 맵 돌면서
	{
		if (it->second) // enter인 경우만 저장
		{
			enterPerson.push_back(it->first);
		}
	}

	// 사전순의 역순이므로 역순으로 출력
	for (int i = enterPerson.size() - 1; i > -1; i--)
	{
		cout << enterPerson[i] << ' ';
	}

	return 0;
}