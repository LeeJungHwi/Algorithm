#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n; // N 6
vector<pair<int, int> > players1(16); // ����(Ⱥ���ɷ�ġ, �������ɷ�ġ)
vector<bool> vis1(16); // �湮üũ : true�� �򵹼���
int minGap = 2147000000; // �ɷ�ġ �� �ּҰ�

// DFS
void DFS(int L, int cnt)
{
	if (L == n || cnt == n / 2) // �������� : ������ �������� ���ų� �򵹼����� �� ��ŭ �̾�����
	{
		if (L == n) // ������ �������� ����� ���
		{
			if (cnt != n / 2) // �򵹼����� �� ��ŭ ���� �������� ����
			{
				return;
			}
		}

		int white = 0;
		int black = 0;

		// abs(�� ������ �ɷ�ġ �� - ������ ������ �ɷ�ġ ��)�� min�� ����
		for (int i = 0; i < n; i++)
		{
			if (vis1[i])
			{
				// �� ���� �ɷ�ġ ��
				white += players1[i].first;
				continue;
			}

			// ������ ���� �ɷ�ġ ��
			black += players1[i].second;
		}

		int gap = abs(white - black); // �ɷ�ġ ��

		if (minGap > gap) // �ɷ�ġ �� �ּҰ� ����
		{
			minGap = gap;
		}
	}
	else
	{
		vis1[L] = true; // �򵹼����� ����
		DFS(L + 1, cnt += 1); // ���� Ƚ�� ���� DFS
		vis1[L] = false; // �򵹼����� �� ���� 
		DFS(L + 1, cnt -= 1); // ���� Ƚ�� ���� DFS
	}
}

// �ٵϴ�ȸ
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	int white, black; 

	for (int i = 0; i < n; i++)
	{
		cin >> white >> black;

		players1[i] = { white, black };
	}

	// DFS
	DFS(0, 0);

	cout << minGap << '\n';

	return 0;
}