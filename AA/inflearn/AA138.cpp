#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

int n, m; // N, M 7, 3
vector<int> clubScores(300); // ���Ƹ� ȸ���� �������� ���� 50 20 30 70 20 60 30

// ��������� ���� ���� �����ϴ� �Լ�
int GetTeamCnt(int teamMaxSum)
{
	int teamScores = 0; // �� ���� ��
	int teamCnt = 1; // ������� ���� ��

	for (int i = 0; i < n; i++)
	{
		if (teamScores + clubScores[i] > teamMaxSum) // �� ���� ���� �ִ밪�� �Ѿ���
		{
			teamCnt++; // ���� �ϳ� �������
			teamScores = clubScores[i]; // i��° ���������� ������ �ʰ��ϹǷ� i��°���� ���ο� ������
		}
		else
		{
			teamScores += clubScores[i]; // ���� �ִ밪�� �ѱ��� �ʾ����� �������� ����
		}
	}

	return teamCnt; // ������� ���� �� ����
}

// �� ������
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n >> m;

	int first = 0; // ó��
	int last = 0; // ������

	// 50 20 30 70 20 60 30
	for (int i = 0; i < n; i++)
	{
		cin >> clubScores[i];

		first = max(first, clubScores[i]); // 70 : �� ���� �� �� �ִ밪�� ����ȸ�� ���� �� �ִ밪���� ŭ
		last += clubScores[i]; // 280 : �� ���� �� �� �ִ밪�� ���ȸ�� ������ �պ��� ����
	}

	int result; // ���� ���� �ִ밪�� �� �ּҰ�

	// ���� ���� �ִ밪�� �� �ּҰ� ã�Ƽ� ���
	while (first <= last) // first�� last�� �����Ǹ� ����
	{
		int avg = (first + last) / 2; // ���� ���� �ִ밪

		if (GetTeamCnt(avg) <= m) // avg�� m���� ���� ���� �� �ִٸ�
		{
			result = avg; // ���� ���� �ִ밪�� �� �ּҰ� ����
			last = avg - 1; // ������ ���� 
		}
		else // �Ұ����� ���� ���� �ִ밪
		{
			first = avg + 1; // ó�� ����
		}
	}

	cout << result;

	return 0;
}
// DFS -> �ð��ʰ� -> ����Ž������ �ذ�

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//int n, m; // N, M 7, 3
//vector<int> clubScores(300); // ���Ƹ� ȸ���� �������� ����
//vector<vector<int> > teamScores(300); // �� �� �������� ����
//int result = 2147000000; // �� ���� ���� �ִ밪�� �� �ּҰ�
//
//// DFS
//void DFS(int L, int cnt)
//{
//	if (L == n || cnt == n) // �������� : ���Ƹ� ȸ�� ���� �Ѿ�ų� ���Ƹ� ȸ�� ���� �����Ѱ��
//	{
//		if (L == n) // ���Ƹ� ȸ�� ���� �ѱ���
//		{
//			if (cnt != n) // ���Ƹ� ȸ�� ���� �������� �ʾ����� ����
//			{
//				return;
//			}
//		}
//
//		for (int i = 0; i < m; i++) // ��� �ϳ��� ���� ������ ������ ����
//		{
//			if (teamScores[i].empty())
//			{
//				return;
//			}
//		}
//
//		// �� ���� ���� �ִ밪 ���ϱ�
//
//		int maxSum = 0; // ���� ���� �ִ밪
//
//		for (int i = 0; i < m; i++) // ���� ������ŭ ���鼭 ���� �� ���ϱ�
//		{
//			int sum = 0; // ���� ��
//
//			for (int j = 0; j < teamScores[i].size(); j++)
//			{
//				sum += clubScores[teamScores[i][j]]; // ������ ���� �� ����
//			}
//
//			// ���� ���� �ִ밪 ����
//			maxSum = max(maxSum, sum);
//		}
//
//		// �� ���� ���� �ִ밪�� �� �ּҰ� ����
//		result = min(result, maxSum);
//	}
//	else
//	{
//		// ���� �̱�
//		for (int i = 0; i < m; i++)
//		{
//			teamScores[i].push_back(L); // ȸ�� ����
//			DFS(L + 1, cnt += 1); // ����Ƚ�� ����
//			teamScores[i].pop_back(); // ȸ�� �� ����
//			cnt -= 1; // ����Ƚ�� ����
//		}
//	}
//}
//
//// �� ������
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	cin >> n >> m;
//
//	// 50 20 30 70 20 60 30
//	for (int i = 0; i < n; i++)
//	{
//		cin >> clubScores[i];
//	}
//
//	// DFS
//	DFS(0, 0);
//
//	cout << result << '\n';
//
//	return 0;
//}