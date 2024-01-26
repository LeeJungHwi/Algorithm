#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���츮
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<vector<int> > peekHeights(n, vector<int>(n)); // ���츮 ���� ����
	vector<pair<int, int> > checkDir; // �����¿�
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });
	vector<vector<bool> > vis(n, vector<bool>(n)); // ���츮 �湮 üũ
	int peekCnt = 0; // ���츮 ����

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> peekHeights[i][j];
		}
	}

	// 2���� ���͸� ���鼭 �����¿� ���츮 üũ
	// ���ڸ� ����� üũ X
	// �湮üũ�� �ȵ� ���츮�� üũ
	// �ڽ��� ���츮���� ������ �湮üũ
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// �湮�� ���츮 üũ
			if (vis[i][j])
			{
				continue;
			}

			int curPeek = peekHeights[i][j]; // üũ�� ���츮
			bool isPeek = true; // ���츮���� üũ

			for (int k = 0; k < 4; k++)
			{
				// �����¿� ������ üũ
				int checkI = i + checkDir[k].first;
				int checkJ = j + checkDir[k].second;

				// ���üũ
				if (checkI < 0 || checkJ < 0 || checkI >= n || checkJ >= n)
				{
					continue;
				}
				
				// �ڽ��� ���츮���� ������ �湮üũ
				if (peekHeights[checkI][checkJ] < curPeek)
				{
					vis[checkI][checkJ] = true;
				}
				else // �����¿� �� �ڽź��� ���� ���츮�� �����Ƿ� ���츮�� �ƴ�
				{
					isPeek = false;
				}
			}
			 
			if (isPeek) // ���츮�϶��� ���� ����
			{
				peekCnt++;
			}
		}
	}

	cout << peekCnt << '\n';

	return 0;
}
// �ٽ�
// 2���� ���� �ʱ�ȭ
// bfs ���üũ ����
// �����¿� ��ǥ
// bfs �湮üũ
// ���츮�� �Ǵ� ����