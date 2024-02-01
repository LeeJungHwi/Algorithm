#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n; // 8
vector<int> sequences(1001); // ����
vector<int> length(1001); // ������ ���� ���� �������� ���� ����

// �ִ� �κ� ��������(LIS)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> sequences[i]; // 5 3 7 8 6 2 9 4
	}

	// ������� �ϴ� �κ� ������ ������ ���� 5�϶� -> 5 -> ���� 1
	// ������� �ϴ� �κ� ������ ������ ���� 3�϶� -> 3 -> ���� 1
	// ������� �ϴ� �κ� ������ ������ ���� 7�϶� -> 3 7, 5 7 -> ���� 2
	// ������� �ϴ� �κ� ������ ������ ���� 8�϶� -> 3 7 8, 5 7 8, 3 8, 5 8 -> ���� 3
	// ������� �ϴ� �κ� ������ ������ ���� 6�϶� -> 3 6, 5 6 -> ���� 2
	// ������� �ϴ� �κ� ������ ������ ���� 2�϶� -> 2 -> ���� 1
	// ������� �ϴ� �κ� ������ ������ ���� 9�϶� -> 2 9, 3 6 9, 5 6 9, 3 7 8 9, 5 7 8 9, 3 8 9, 5 8 9, 3 7 9, 5 7 9, 3 9, 5 9 -> ���� 4
	// ������� �ϴ� �κ� ������ ������ ���� 4�϶� -> 2 4, 3 4 -> ���� 2
	length[1] = 1;
	int lis = 0;

	// �����ε��� �����ε����� ���鼭 ������ ���ں��� ���� ���� ���� �� �ִ밪�� ���ؼ� +1�ؼ� ����
	for (int i = 2; i < n + 1; i++)
	{
		// ������ ���ں��� ���� ���� ���� �� �ִ밪
		int maxLength = 0;
		int lastNum = sequences[i];

		for (int j = i - 1; j > 0; j--)
		{
			if (lastNum > sequences[j] && maxLength < length[j])
			{
				maxLength = length[j];
			}
		}

		// ���� �ִ밪�� + 1
		length[i] = maxLength + 1;

		// lis ����
		if (lis < length[i])
		{
			lis = length[i];
		}
	}

	cout << lis << '\n';

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <fstream>
//using namespace std;
//
//int n; // 8
//vector<int> sequences(1000); // ����
//vector<bool> vis(1000); // �湮üũ
//int lis;
//
//void DFS(int L)
//{
//	if (L == n)
//	{
//		// �� �κ� �������� lis �����ϱ�
//		int maxNum = 0;
//		int length = 0;
//
//		for (int i = 0; i < n; i++)
//		{
//			if (vis[i])
//			{
//				if (maxNum < sequences[i])
//				{
//					maxNum = sequences[i];
//					length++;
//				}
//			}
//		}
//
//		if (lis < length)
//		{
//			lis = length;
//		}
//	}
//	else
//	{
//		// ��� �κ� ���� �����
//		if (!vis[L])
//		{
//			vis[L] = true;
//			DFS(L + 1);
//			vis[L] = false;
//			DFS(L + 1);
//		}
//	}
//}
//
//// �ִ� �κ� ��������(LIS)
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> sequences[i]; // 5 3 7 8 6 2 9 4
//	}
//
//	// ��� ���� �����
//	// �� �������� lis ã��
//	DFS(0);
//
//	cout << lis << '\n';
//
//	return 0;
//}