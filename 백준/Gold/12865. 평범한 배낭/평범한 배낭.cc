#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 평범한 배낭
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int thingCnt; // 물건종류 4
	int bagWeight; // 가방 최대수용 무게 7

	cin >> thingCnt >> bagWeight;

	vector<pair<int, int> > things(thingCnt); // 물건 (무게, 가치) 저장
	vector<int> values(bagWeight + 1); // 가방의 무게에 따라 담을수있는 최대가치 저장

	int weight; // 물건 무게
	int value; // 물건 가치

	//	6 13
	//	4 8
	//	3 6
	//	5 12
	for (int i = 0; i < thingCnt; i++)
	{
		cin >> weight >> value;

		things[i] = { weight, value };
	}

	// 물건종류만큼 돌면서 values 갱신
	// 물건은 하나씩만 있으므로 여러번이 아닌 하나만 사용해야함
	// 물건을 담았을때의 가치를 갱신할때 현재물건을 사용하지않는 경우를 고려해야함
	for (int i = 0; i < thingCnt; i++)
	{
		for (int j = bagWeight; j >= things[i].first; j--) // 가방 무게부터 현재 물건 무게까지 돌면서 최대가치 갱신
		{
			values[j] = max(values[j], values[j - things[i].first] + things[i].second);
		}
	}

	cout << values[bagWeight] << '\n';

	return 0;
}