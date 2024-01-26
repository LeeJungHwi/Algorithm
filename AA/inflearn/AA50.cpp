#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���� ����(small)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int groundH, groundW; // ��ü�� ���� ���� 6 7

	cin >> groundH >> groundW;

	vector<vector<int> > ground(groundH, vector<int>(groundW)); // ��ü ��

	for (int i = 0; i < groundH; i++)
	{
		for (int j = 0; j < groundW; j++)
		{
			cin >> ground[i][j];
		}
	}

	int territoryH, territoryW; // ������ �ϻ���� �� ���� ���� 2 3
	cin >> territoryH >> territoryW;

	// ���� �����ϱ�
	// 3 5 1 3 1 3 2
	// 1 2 1 3 1 1 2
	// 1 3 1 5 1 3 4
	// 5 1 1 3 1 3 2
	// 3 1 1 3 1 1 2
	// 1 3 1 3 1 2 2

	int maxOrangeTreeCnt = 0; // ������ ���� �ִ� ����

	for (int i = 0; i < groundH - territoryH + 1; i++)
	{
		for (int j = 0; j < groundW - territoryW + 1; j++)
		{
			int orangeTreeCnt = 0; // ������ ���� ����

			for (int k = i; k < territoryH + i; k++) // ���� �� ������ ���� ���� ��
			{
				for (int l = j; l < territoryW + j; l++)
				{
					orangeTreeCnt += ground[k][l];
				}
			}

			if (maxOrangeTreeCnt < orangeTreeCnt) // ������ ������ �ִ��� ���� ����
			{
				maxOrangeTreeCnt = orangeTreeCnt;
			}
		}
	}

	cout << maxOrangeTreeCnt << '\n';

	return 0;
}