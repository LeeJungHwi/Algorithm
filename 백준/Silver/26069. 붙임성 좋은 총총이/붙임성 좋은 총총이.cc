#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

// 붙임성 좋은 총총이
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 12
	cin >> n;

	set<string> danceSet; // 무지개댄스 추는 중인 사람 저장
	danceSet.insert("ChongChong");
	string name1, name2;

	for (int i = 0; i < n; i++)
	{
		cin >> name1 >> name2;

		if(danceSet.find(name1) != danceSet.end()) danceSet.insert(name2);
		if(danceSet.find(name2) != danceSet.end()) danceSet.insert(name1);
	}

	cout << danceSet.size() << '\n';

	return 0;
}