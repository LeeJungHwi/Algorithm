#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
#include <fstream>
using namespace std;

// 나는야 포켓몬 마스터 이다솜
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 26, 5
	cin >> n >> m;

	// 맵에 (이름, 번호) (번호, 이름) 저장
	// 번호가들어오면 이름을
	// 이름이들어오면 번호를 출력

	//	Bulbasaur
	//	Ivysaur
	//	Venusaur
	//	Charmander
	//	Charmeleon
	//	Charizard
	//	Squirtle
	//	Wartortle
	//	Blastoise
	//	Caterpie
	//	Metapod
	//	Butterfree
	//	Weedle
	//	Kakuna
	//	Beedrill
	//	Pidgey
	//	Pidgeotto
	//	Pidgeot
	//	Rattata
	//	Raticate
	//	Spearow
	//	Fearow
	//	Ekans
	//	Arbok
	//	Pikachu
	//	Raichu

	map<string, int> keyName; // (이름,번호) 저장
	map<int, string> keyNum; // (번호,이름) 저장
	string name; // 이름

	for (int i = 1; i < n + 1; i++)
	{
		cin >> name;

		keyName[name] = i;
		keyNum[i] = name;
	}

	// 번호가들어오면 이름을
	// 이름이들어오면 번호를 출력

	//	25
	//	Raichu
	//	3
	//	Pidgey
	//	Kakuna

	string inputString; // 입력문자열

	for (int i = 0; i < m; i++)
	{
		cin >> inputString;

		// 번호가들어오면 이름 출력
		if (atoi(inputString.c_str()))
		{
			cout << keyNum[stoi(inputString)] << '\n';
		}
		else // 이름이들어오면 번호 출력
		{
			cout << keyName[inputString] << '\n';
		}
	}

	return 0;
}