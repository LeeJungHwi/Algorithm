#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ������� �ִ밪
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 10
	cin >> n;

	vector<vector<int> > sets(3, vector<int>(n)); // �� ���� ���� ����
	vector<vector<bool> > vis(3, vector<bool>(100001)); // �� ���� ��� üũ

	//	39 31 32 75 75 7 89 21 7 67
	//	4 19 52 75 35 100 4 26 24 69
	//	82 53 22 64 58 80 94 75 51 69

	int num; // ����

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;

			sets[i][j] = num; // �� ���տ� ���� ����
			vis[i][num] = true; // �� ���տ� ����ִ� ��� üũ
		}
	}

	// �� ���� �������� ����
	//	7 7 21 31 32 39 67 75 75 89
	//	4 4 19 24 26 35 52 69 75 100
	//	22 51 53 58 64 69 75 80 82 94
	for (int i = 0; i < 3; i++)
	{
		sort(sets[i].begin(), sets[i].end());
	}

	// ù��° ���տ��� ū������ ��, ����° ���տ� ������Ҹ� �������� üũ

	int maxCommonEle = 0; // ������� �ִ밪

	for (int i = n - 1; i > -1; i--)
	{
		int checkNum = sets[0][i]; // üũ�� ����

		if (vis[1][checkNum] && vis[2][checkNum]) // üũ �� ���ڰ� ��, ����° ���տ��� �ִٸ�
		{
			maxCommonEle = checkNum; // ������� �ִ밪 ���� �� ����
			
			break;
		}
	}

	if (maxCommonEle == 0) // ���� �ȵ����� ã��������
	{
		cout << -1 << '\n';

		return 0;
	}

	cout << maxCommonEle << '\n';

	return 0;
}