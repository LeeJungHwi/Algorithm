#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// �۾��� ã�� 2
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int s, e, k; // S, E, K 5, 14, 3
	cin >> s >> e >> k;

	queue<int> checkPos; // üũ �� ��ġ
	vector<bool> vis(10001); // ������ ��ġ üũ 7 11 15

	// ������ ��ġ üũ
	int kPos;
	for (int i = 0; i < k; i++)
	{
		cin >> kPos;
		vis[kPos] = true;
	}

	// ���� ��ġ���� BFS ������
	checkPos.push(s);

	int jumpCnt = 0; // ���� Ƚ��

	while (!checkPos.empty()) // ť�� ��������
	{
		int sizeBackUp = checkPos.size(); // ť ������ ��� ??

		for (int i = 0; i < sizeBackUp; i++) // ����� ť �����ŭ ���鼭 ??
		{
			// ������ġ ����
			int standardPos = checkPos.front();
			checkPos.pop();

			// -1 +1 +5
			vector<int> checkDir;
			checkDir.push_back(standardPos - 1);
			checkDir.push_back(standardPos + 1);
			checkDir.push_back(standardPos + 5);

			for (int i = 0; i < 3; i++)
			{
				// ������ġ���� -1 +1 +5 �� �ϳ��� �ٷΰ��������� ����Ƚ�� + 1 ��� �� ���α׷� ����
				if (checkDir[i] == e) 
				{
					cout << jumpCnt + 1;
					exit(0);
				}
				
				// ���üũ
				if (checkDir[i] < 1 || checkDir[i] > 10000)
				{
					continue;
				}

				// ������ üũ
				if (vis[checkDir[i]])
				{
					continue;
				}

				// ť�� ���� �� �湮üũ
				checkPos.push(checkDir[i]);
				vis[checkDir[i]] = 1;
			}
		}

		// ����Ƚ�� ����
		jumpCnt++;
	}

	return 0;
}