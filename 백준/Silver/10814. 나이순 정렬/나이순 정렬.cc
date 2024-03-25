#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 나이순 정렬
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	map<int, vector<string> > member; // 회원들

	int age; // 나이 21
	string name; // 이름 Junkyu

	// (나이, 이름들) 맵핑
	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;

		member[age].push_back(name);
	}

	// 맵 돌면서 출력
	for (auto it = member.begin(); it != member.end(); it++)
	{
		for (int i = 0; i < it->second.size(); i++)
		{
			cout << it->first << ' ' << it->second[i] << '\n';
		}
	}

	return 0;
}