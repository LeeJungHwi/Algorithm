#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// 가방문제(냅색)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int jewelCnt; // 보석종류 4
	int bagWeight; // 가방 최대수용 무게 11

	cin >> jewelCnt >> bagWeight;

	vector<pair<int, int> > jewels(jewelCnt); // 보석
	vector<int> values(bagWeight + 1); // 가방의 무게에 따라 담을수있는 최대가치 저장

	int weight; // 보석 무게
	int value; // 보석 가치

	//	5 12
	//	3 8
	//	6 14
	//	4 8
	for (int i = 0; i < jewelCnt; i++)
	{
		cin >> weight >> value;

		jewels[i] = { weight, value };
	}

	// 보석종류만큼 돌면서 values 갱신
	for (int i = 0; i < jewelCnt; i++)
	{
		for (int j = jewels[i].first; j < bagWeight + 1; j++) // 보석 무게 ~ 가방 무게 까지 돌면서 최대가치 갱신
		{
			if (values[j] < values[j - jewels[i].first] + jewels[i].second)
			{
				values[j] = values[j - jewels[i].first] + jewels[i].second;
			}
		}
	}

	cout << values[bagWeight] << '\n';

	return 0;
}