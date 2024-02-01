#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<pair<int, int> > pizza; // ������
vector<pair<int, int> > house; // ��
vector<int> vis(20); // ���õ� ������
int n, m; // N, M 4, 4
int minDis = 2147000000; // ���� ���ڹ�ްŸ� �ּڰ�
int pizzaDis; // �� ������ ���ڹ�ްŸ�
int cityDis; // ���� ���ڹ�ްŸ�

void DFS(int level, int start)
{
	if (level == m) // �������� : m���� �������� ���������� �� ���� ���� ���õ� ������ �� �ִܰŸ��� ��� ���Ѱ��� ���� ���ڹ�ްŸ�
	{
		cityDis = 0; // ���� ���ڹ�ްŸ�

		for (int i = 0; i < house.size(); i++) // �� ������ŭ ���鼭
		{
			int x1 = house[i].first; // �� x��ǥ
			int y1 = house[i].second; // �� y��ǥ
			pizzaDis = 2147000000; // �� ���ڹ�ްŸ�

			for (int j = 0; j < m; j++) // ���õ� ��������ŭ ���鼭 
			{
				int x2 = pizza[vis[j]].first; // ������ x��ǥ
				int y2 = pizza[vis[j]].second; // ������ y��ǥ
				pizzaDis = min(pizzaDis, abs(x1 - x2) + abs(y1 - y2)); // �� ���ڹ�ްŸ� �ּڰ� ����
			}

			cityDis += pizzaDis; // ���� ���ڹ�ްŸ�
		}

		if (cityDis < minDis) // ���� ���ڹ�ްŸ� ����
		{
			minDis = cityDis;
		}
	}
	else
	{
		for (int i = start; i < pizza.size(); i++) // ������ ���� �� m�� ���� ->  0 1 2 3, 0 1 2 4, ....
		{
			vis[level] = i;
			DFS(level + 1, i + 1);
		}
	}
}

// ���� ��� �Ÿ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int num; // ����

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> num;

			if (num == 1)
			{
				house.push_back({ i, j }); // (1, 2) (2, 1) (2,4) (3, 3) (4, 3)
			}
			else if (num == 2)
			{
				pizza.push_back({ i, j }); // (1, 3) (2, 3) (3, 2) (3, 4) (4, 1) (4, 4)
			}
		}
	}

	// house -> ��(1)�� ������ �� ��ǥ ���� -> (1, 2) (2, 1) (2,4) (3, 3) (4, 3)
	// pizza -> ������(2)�� ������ ������ ��ǥ ���� -> (1, 3) (2, 3) (3, 2) (3, 4) (4, 1) (4, 4)
	// ch -> �������� m�� �̾� ���� -> 0 1 2 3, 0 1 2 4, ....
	// �� ���� ���� ���õ� ������ �� �ִܰŸ��� ��� ���Ѱ��� ���� ���ڹ�ްŸ�
	DFS(0, 0);
	cout << minDis;

	return 0;
}