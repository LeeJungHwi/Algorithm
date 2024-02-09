#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> players(9); // ���� �Ƿ� ���� 1 2 3 4 5 6 7 8 9
vector<int> firstTeam, secondTeam, thirdTeam; // �� �� �������� ����
int minGap = 2147000000; // �Ƿ��� �ּҰ�

// DFS
void DFS(int L, int firstCnt, int secondCnt, int thirdCnt)
{
	if (L == 9 || (firstCnt == 3 && secondCnt == 3 && thirdCnt == 3)) // ���� ���� : ���� ���� �Ѿ�ų� �� ���� 3�� ��� ���� ���
	{
		if (L == 9) // ���� ���� �Ѿ ���
		{
			if (!(firstCnt == 3 && secondCnt == 3 && thirdCnt == 3)) // �� ���� ��� 3�� ������ �ƴϸ� ����
			{
				return;
			}
		}

		// �� ���� ��� 3�� �̾Ҵٸ� �Ƿ��� �ּҰ� ����

		int firstScore = 0, secondScore = 0, thirdScore = 0; // �� �� ����

		for (int i = 0; i < 3; ++i)
		{
			firstScore += players[firstTeam[i]]; // ù��° �� ����
			secondScore += players[secondTeam[i]]; // �ι�° �� ����
			thirdScore += players[thirdTeam[i]]; // ����° �� ����
		}

		int maxScore = max({ firstScore, secondScore, thirdScore }); // ���� �Ƿ��� ���� �� ����
		int minScore = min({ firstScore, secondScore, thirdScore }); // ���� �Ƿ��� ���� �� ����

		minGap = min(minGap, maxScore - minScore); // �Ƿ��� �ּҰ� ����
	}
	else
	{
		firstTeam.push_back(L); // ���� ����
		DFS(L + 1, firstCnt += 1, secondCnt, thirdCnt); // ù��° �� ����Ƚ�� ����
		firstTeam.pop_back(); // ���� �� ����
		firstCnt -= 1; // ù��° �� ����Ƚ�� ����

		secondTeam.push_back(L); // ���� ����
		DFS(L + 1, firstCnt, secondCnt += 1, thirdCnt); // �ι�° �� ����Ƚ�� ����
		secondTeam.pop_back(); // ���� �� ����
		secondCnt -= 1; // �ι�° �� ����Ƚ�� ����

		thirdTeam.push_back(L); // ���� ����
		DFS(L + 1, firstCnt, secondCnt, thirdCnt += 1); // ����° �� ����Ƚ�� ����
		thirdTeam.pop_back(); // ���� �� ����
		thirdCnt -= 1; // ����° �� ����Ƚ�� ����
	}
}

// �� �����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	for (int i = 0; i < 9; ++i)
	{
		cin >> players[i];
	}

	// DFS
	DFS(0, 0, 0, 0);

	cout << minGap;

	return 0;
}

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//vector<int> players1(9); // ���� �Ƿ� ���� 1 2 3 4 5 6 7 8 9
//vector<int> vis1(9); // ó�� 3�� ���� �̾Ҵ��� üũ
//vector<int> vis2(9); // ���� 6�� �� 3�� ���� �̾Ҵ��� üũ
//
//int allTeam; // ��� �� ���� ��
//int firstTeam, secondTeam, thirdTeam; // �� �� ���� ��
//int minGap = 2147000000; // �Ƿ��� �ּҰ�
//
//// DFS
//void DFS(int L, int cnt, int flag)
//{
//	if (flag == 1) // ó�� 3�� �̱�
//	{
//		if (L == 9 || cnt == 3) // ���� ���� : ���� ���� �Ѿ�ų� ���� ������ �������
//		{
//			if (L == 9) // ���� ���� �Ѿ���
//			{
//				if (cnt != 3) // ������ ������ ������ �ƴϸ� ����
//				{
//					return;
//				}
//			}
//
//			firstTeam = 0;
//
//			// ù��° �� ���� ��
//			for (int i = 0; i < 9; i++)
//			{
//				if (vis1[i])
//				{
//					firstTeam += players1[i];
//				}
//			}
//
//			// ���� 6�� �� 3�� �̱�
//			DFS(0, 3, 2);
//		}
//		else
//		{
//			vis1[L] = true; // ���� ����
//			DFS(L + 1, cnt += 1, 1);
//			vis1[L] = false; // ���� �� ����
//			DFS(L + 1, cnt -= 1, 1);
//		}
//	}
//	else if (flag == 2) // ���� 6�� �� 3�� �̱�
//	{
//		if (L == 9 || cnt == 6) // ���� ���� : ���� ���� �Ѿ�ų� ���� ������ �� �������
//		{
//			if (L == 9) // ���� ���� �Ѿ���
//			{
//				if (cnt != 6) // ������ ������ �� ������ �ƴϸ� ����
//				{
//					return;
//				}
//			}
//
//			secondTeam = 0;
//
//			// �ι�° �� ���� ��
//			for (int i = 0; i < 9; i++)
//			{
//				if (vis2[i])
//				{
//					secondTeam += players1[i];
//				}
//			}
//
//			thirdTeam = 0;
//
//			// ����° �� ���� ��
//			thirdTeam = allTeam - firstTeam - secondTeam;
//
//			// ���� ���� ���� ���� ���� ���� �Ƿ���
//			int maxTeam = max(firstTeam, secondTeam);
//			maxTeam = max(maxTeam, thirdTeam);
//
//			int minTeam = min(firstTeam, secondTeam);
//			minTeam = min(minTeam, thirdTeam);
//
//			int gapTeam = maxTeam - minTeam;
//
//			// �Ƿ��� �ּҰ� ����
//			if (minGap > gapTeam)
//			{
//				minGap = gapTeam;
//			}
//		}
//		else
//		{
//			if (!vis1[L]) // �̹� ���� 3���� ����
//			{
//				vis2[L] = true; // ���� ����
//				DFS(L + 1, cnt += 1, 2);
//				vis2[L] = false; // ���� �� ����
//				DFS(L + 1, cnt -= 1, 2);
//			}
//		}
//	}
//}
//
//// �� �����
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	for (int i = 0; i < 9; i++)
//	{
//		cin >> players1[i];
//
//		allTeam += players1[i];
//	}
//
//	// DFS
//	DFS(0, 0, 1);
//
//	cout << minGap;
//
//	return 0;
//}