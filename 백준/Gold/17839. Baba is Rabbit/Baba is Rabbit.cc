#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <fstream>
using namespace std;

// Baba is Rabbit
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 3
	cin >> n;

	string p;
	string q;
	bool isBaba = false; // Baba 명령어가 나왔는지 체크
	set<string> Baba; // Baba를 적용 할 사물
	map<string, vector<string> > pqMap;
	set<string> ans;

	for (int i = 0; i < n; i++)
	{
		cin >> p >> q >> q;

		// Baba 명령어가 나왔는지 체크, (p, q) 맵핑
		if (p == "Baba")
		{
			isBaba = true;
			Baba.insert(q);
			ans.insert(q);
		}
		pqMap[p].push_back(q);
	}

	// Baba 명령어가 나오지 않으면 종료
	if (!isBaba) return 0;

	// 맵 돌면서 값이 없을 때 까지 출력
	while (true)
	{
		if (Baba.empty()) break;

		set<string> temp;

		// 어떤 사물 p에 대해 여러번 q를 적용 할 수 있음
		for (auto it = Baba.begin(); it != Baba.end(); it++)
		{
			for (int j = 0; j < pqMap[*it].size(); j++)
			{
				if(ans.insert(pqMap[*it][j]).second) temp.insert(pqMap[*it][j]);
				//ans.insert(pqMap[*it][j]);
				//temp.insert(pqMap[*it][j]);
			}
		}

		Baba = temp;
	}

	for (auto it = ans.begin(); it != ans.end(); it++) cout << *it << '\n';

	return 0;
}