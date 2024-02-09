#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

// ���簢�� �׸���
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m; // N, M 6, 8
	cin >> n >> m;

	vector<vector<int> > graph(n, vector<int>(m)); // �׷���
	vector<int> cnts(1001); // ���簢�� ���� ����
	queue<pair<int, int> > checkPos; // üũ�� ��ġ
	int recSize = 1; // ���� �簢�� ũ��
	
	// �Է��� string���� ����;;
	// ũ�Ⱑ 1�� ���簢�� ��ǥ �� ���� ����
	//	00001010
	//	00011110
	//	00011000
	//	00011110
	//	11111110
	//	11111110
	for (int i = 0; i < n; i++)
	{
		string inputString;
		cin >> inputString;

		for (int j = 0; j < m; j++)
		{
			graph[i][j] = inputString[j] - '0';

			if (inputString[j] - '0' == 1)
			{
				checkPos.push({ i, j });
				cnts[recSize]++;
			}
		}
	}
	
	// ť�� �������� : ť�� ����ٴ°��� ���̻� ���� ���簢���� ��������ٴ°�
	// ���� ũ�� �簢�� ������ŭ ���鼭 ť���� �����鼭 : ���� ũ�� �簢�� ���� ��ǥ������ ���� ���簢���� ������ִ��� üũ�ϸ� �ǹǷ�
	// ���� ��ǥ���� ���簢���� ����������� ��ǥ �� ���� ����
	// for�� ������ ���� ���簢�� ������ ���� : ���� ũ���� ���簢�� ������ ���ϱ�����
	while (!checkPos.empty())
	{
		for (int i = 0; i < cnts[recSize]; i++) // ���� ũ�� �簢���� ������ŭ ���鼭
		{
			// �����鼭
			pair<int, int> standardPos = checkPos.front();
			checkPos.pop();

			// ��踦 ����� ���簢���� ���������
			if (standardPos.first + recSize + 1 > n || standardPos.second + recSize + 1 > m)
			{
				continue;
			}

			// ���簢���� ������ִ��� üũ
			bool isSquare = true;

			for (int j = standardPos.first; j < standardPos.first + recSize + 1; j++)
			{
				for (int k = standardPos.second; k < standardPos.second + recSize + 1; k++)
				{
					if (graph[j][k] != 1) // �ϳ��� 1�� �ƴϸ� ���簢���� ���������
					{
						isSquare = false;
						break;
					}
				}

				if (!isSquare)
				{
					break;
				}
			}

			// ���簢���� ������ִٸ� ��ǥ �� ���� ���簢�� ���� ����
			if (isSquare) 
			{
				checkPos.push(standardPos);
				cnts[recSize + 1]++;
			}
		}

		// for���� ������ ���� ���簢���� ������ ���ϱ����� ������ ����
		recSize++;
	}

	// ���簢�� ũ��� ���� ���
	for (int i = 1; i < recSize; i++)
	{
		cout << i << ' ' << cnts[i] << '\n';
	}

	return 0;
}