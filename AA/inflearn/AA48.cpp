#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

// �� ���� ��հ� ���� ����� ��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	vector<vector<float> > mat(9, vector<float>(9)); // 9by9�� �ڿ��� ����

	for (int i = 0; i < 9; i++)
	{
		float columnSum = 0; // �� ���� ��
		float columnAvg = 0; // �� ���� ���� ���
		float gapMin = 100; // ���� �ּҰ�
		float closeElement = 0; // ��հ� ���� ����� ��

		for (int j = 0; j < 9; j++)
		{
			cin >> mat[i][j];
			columnSum += mat[i][j]; // �� ���� ��
		}

		columnAvg = round(floor((columnSum / 9.0f) * 10) / 10); // �� ���� ���� ���

		for (int j = 0; j < 9; j++) // ���� �ּҰ� �� ��հ� ���� ����� �� ����
		{
			if (abs(columnAvg - mat[i][j]) < gapMin)
			{
				gapMin = abs(columnAvg - mat[i][j]);
				closeElement = mat[i][j];
			}
			else if (abs(columnAvg - mat[i][j]) == gapMin) // ���� �ּҰ��� ������ ū ���� ��
			{
				if (closeElement < mat[i][j])
				{
					closeElement = mat[i][j];
				}
			}
		}

		cout << columnAvg << ' ' << closeElement << '\n';
	}

	return 0;
}

// �ٽ�
// round -> �Ҽ��� ù ° �ڸ����� �ݿø�
// floor -> ����
// ceil -> �ø�
// �ݿø� �Ϸ��� �ڸ��� ���� 10�� �ŵ������� ���ϰ� floor ���� �� 10�� �ŵ������� ���Ѹ�ŭ �����ְ� round