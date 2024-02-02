#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ������ȯ(����)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int coinType; // �������� 3

	cin >> coinType;
	
	vector<int> coins(coinType); // ���� 1 2 5
	
	for (int i = 0; i < coinType; i++)
	{
		cin >> coins[i];
	}

	int money; // �Ž�������� �� 15

	cin >> money;

	vector<int> coinCnts(money + 1, 2147000000); // �Ž�������� ���� ���� ���� �ּҰ��� ����
	coinCnts[0] = 0; // �Ž�������� ���� 0�϶� ���� ���� 0��

	for (int i = 0; i < coinType; i++) // ���� ������ŭ ���鼭
	{
		for (int j = coins[i]; j < money + 1; j++) // ������ġ ~ �Ž�������� �� ���� ���鼭 �ּҰ��� ����
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