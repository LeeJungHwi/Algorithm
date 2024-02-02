#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// 동전교환(냅색)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int coinType; // 동전종류 3

	cin >> coinType;
	
	vector<int> coins(coinType); // 동전 1 2 5
	
	for (int i = 0; i < coinType; i++)
	{
		cin >> coins[i];
	}

	int money; // 거슬러줘야할 돈 15

	cin >> money;

	vector<int> coinCnts(money + 1, 2147000000); // 거슬러줘야할 돈에 따라 동전 최소개수 저장
	coinCnts[0] = 0; // 거슬러줘야할 돈이 0일때 동전 개수 0개

	for (int i = 0; i < coinType; i++) // 동전 개수만큼 돌면서
	{
		for (int j = coins[i]; j < money + 1; j++) // 동전가치 ~ 거슬러줘야할 돈 까지 돌면서 최소개수 갱신
		{
			if (coinCnts[j] > coinCnts[j - coins[i]] + 1)
			{
				coinCnts[j] = coinCnts[j - coins[i]] + 1;
			}
		}
	}

	cout << coinCnts[money] << '\n';

	return 0;
}