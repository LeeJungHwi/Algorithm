#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n, d, k; // N, D, K 8, 4, 3
vector<vector<int> > students(30001); // �л� �ҽ����� 
vector<int> vis1(16); // �湮üũ
int maxStuCnt; // ������ ���� �� �ִ� �ִ��л� ��

// DFS
void DFS(int L, int cnt)
{
	if (L == d + 1 || cnt == k) // �������� : ������ ������ ���ų� k���� ��Ḧ �̾�����
	{
		// ������ ��ῡ�� k���� ��Ḧ �������� ���� ����
		if (L == d + 1)
		{
			if (cnt != k)
			{
				return;
			}
		}

		// k���� ��Ḧ �̾����� ����� ������ ���� �� �ִ��� �� �л����� üũ

		int studentCnt = 0; // ������ ���� �� �ִ� �л� ��

		for (int i = 1; i < n + 1; i++)
		{
			bool isEat = true; // ������ �ִ��� üũ

			for (int j = 0; j < students[i].size(); j++)
			{
				if (!vis1[students[i][j]]) // ���Ŀ� �ϳ��� �л��� �����ϴ� ��ᰡ ������ ����������
				{
					isEat = false;
					break;
				}
			}

			if (isEat) // �ش� �л��� �������ִ� �����̸� ī����
			{
				studentCnt++;
			}
		}

		// �ִ��л� �� ����
		if (maxStuCnt < studentCnt)
		{
			maxStuCnt = studentCnt;
		}
	}
	else
	{
		vis1[L] = true; // �ҽ� ����
		DFS(L + 1, cnt += 1);
		vis1[L] = false; // �ҽ� �̼���
		DFS(L + 1, cnt -= 1);
	}
}

// �ִ� ��ȣ ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> d >> k;

	// �л� : N ��, ��� : D ��, ��ἱ�� : K �� ����
	// �ִ� ����� �л��� ������ ���� �� �ִ���?
	// D �� �� K ���� �̾Ƽ� ����� ���� �� �ִ��� üũ

	int sourceCnt; // �ҽ� ����
	int sourceNum; // �ҽ� ��ȣ

	// 1�� �л����� ���Ḯ��Ʈ ��� ��ȣ�ϴ� ��� ����
	/*
	input : 1 1
			2 2 3
			1 3
			2 1 2
			0
			2 2 1
			3 2 3 4
			2 3 4

	graph : 1 -> 1
			2 -> 2 -> 3
			3 -> 3
			4 -> 1 -> 2
			5 
			6 -> 2 -> 1
			7 -> 2 -> 3 -> 4
			8 -> 3 -> 4
	*/
	for (int i = 1; i < n + 1; i++)
	{
		cin >> sourceCnt;

		for (int j = 0; j < sourceCnt; j++) // �ҽ� ���� ��ŭ �ҽ��� �Է¹ް� ����
		{
			cin >> sourceNum;

			students[i].push_back(sourceNum);
		}
	}

	// DFS
	DFS(1, 0);

	cout << maxStuCnt << '\n';

	return 0;
}