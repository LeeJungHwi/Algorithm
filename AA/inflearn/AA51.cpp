#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���� ����(large)
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

	// ó�� ������ ������ ���� ���� �� ���ϱ�
	// ������������ : ���� ������ ������ ���� ���� �� - ù�� ������ ���� ���� �� + ���� ������ �������� ������ ���� ���� ��

	// ���� - (0,0) (1,0) + (0,3) (1,3)
	// ���� - (0,1) (1,1) + (0,4) (1,4)
	// ���� - .... + ....
	// ���� - (0,3) (1,3) + (0,6) (1,6)
	// ���� - (1,0) (2,0) + (1,3) (2,3)
	// ���� - (1,1) (2,1) + (1,4) (2,4)
	// ���� - .... + ....
	// ���� - (1,3) (2,3) + (1,6) (2,6)

	int maxOrangeTreeCnt = 0; // ������ ���� �ִ� ����

	for (int i = 0; i < groundH - territoryH + 1; i++) // ������������ : ���� ������ ������ ���� ���� �� - ù�� ������ ���� ���� �� + ���� ������ �������� ������ ���� ���� ��
	{
		int orangeTreeCnt = 0;
		int standardOrangeTreeCnt = 0;

		for (int j = 0; j < groundW - territoryW + 1; j++)
		{
			// ���� ���� ������ �� ���ϱ�
			if (orangeTreeCnt == 0)
			{
				// ���� ���ذ��� ������ ��ü �� ���ϱ�
				if (standardOrangeTreeCnt == 0)
				{
					for (int k = i; k < territoryH + i; k++) // ���� �� ������ ���� ���� ��
					{
						for (int l = j; l < territoryW + j; l++)
						{
							orangeTreeCnt += ground[k][l];
						}
					}

					standardOrangeTreeCnt = orangeTreeCnt;
				}
				else // ���� ���ذ��� ������ �����ؼ� ���ϱ�
				{
					for (int k = j; k < territoryW + j; k++) // ���� �� ������ ���� ���� ��
					{
						orangeTreeCnt = orangeTreeCnt - ground[k - 1][j] + ground[k + territoryH - 1][j];
					}
				}
			}
			else // ���� ���� ������ �����ؼ� ���ϱ�
			{
				for (int k = i; k < territoryH + i; k++) // ���� �� ������ ���� ���� ��
				{
					orangeTreeCnt = orangeTreeCnt - ground[k][j - 1] + ground[k][j + territoryW - 1];
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
// �ٽ�
// ���� �� ����