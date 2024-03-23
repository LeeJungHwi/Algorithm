#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 이름 궁합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	string jongMinName; // 종민이 영어이름 CJM
	string herName; // 그녀의 영어이름 HER

	cin >> jongMinName;
	cin >> herName;

	string sumName; // 이름궁합을 보기위해 두 이름을 합침 CHJEMR

	for (int i = 0; i < jongMinName.size(); i++)
	{
		sumName += jongMinName[i];
		sumName += herName[i];
	}

	// 각 알파벳에 대해 획수 맵핑
	vector<int> stroke = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 }; // 출제자가 정한 알파벳 획수
	map<char, int> alpha; // (알파벳, 획수) 맵핑

	for (int i = 0; i < 26; i++)
	{
		alpha['A' + i] = stroke[i];
	}

	// 디버깅용
	//for (auto it = alpha.begin(); it != alpha.end(); it++)
	//{
	//	cout << it->first << ' ' << it->second << '\n';
	//}

	// CHJEMR
	// C : 1
	// H : 3
	// J : 2
	// E : 3
	// M : 2
	// R : 2
	// (1 3) (3 2) (2 3) (3 2) (2 2) 4 5 5 5 4
	// (4 5) (5 5) (5 5) (5 4)
	// (9 0) (0 9)
	// (9 9)

	queue<int> calc; // 계산된 획수 저장

	// 일단 처음 획수 저장 1 3 2 3 2 2
	for (int i = 0; i < sumName.size(); i++)
	{
		calc.push(alpha[sumName[i]]);
	}

	// 큐 크기가 두 자리가 아닐때 반복
	while (true)
	{
		int nearAlpha = calc.front(); // 인접한 알파벳 획수 1
		calc.pop();
		int alphaSize = calc.size(); // 큐 크기

		for (int i = 0; i < alphaSize; i++) // 큐 크기만큼 꺼내서 인접한 획수끼리 더해서 다시 큐에 저장
		{
			calc.push((nearAlpha + calc.front()) % 10); // 10을 넘기면 일의자리만 저장
			nearAlpha = calc.front();
			calc.pop();
		}
		
		// 큐 크기가 두 자리가되면 출력하고 종료
		if (calc.size() == 2)
		{
			while (!calc.empty())
			{
				cout << calc.front();
				calc.pop();
			}

			break;
		}
	}

	return 0;
}