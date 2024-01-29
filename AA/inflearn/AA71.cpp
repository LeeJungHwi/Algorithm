#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// �۾��� ã��
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int s, e; // S, E
	cin >> s >> e;

	int jumpCnt = 0; // ���� ��
	int curPos = s; // ���� ��ġ

	// ó�� ��ġ ����

	// ������ġ < �۾�����ġ
	// (�۾�����ġ - ������ġ) % 5 < 3 �̸� (�۾�����ġ - ������ġ) / 5 ��ŭ ���� �� (�۾�����ġ - ��������ġ) ��ŭ ����
	// (�۾�����ġ - ������ġ) % 5 >= 3 �̸� (�۾�����ġ - ������ġ) / 5 + 1��ŭ ���� �� (��������ġ - �۾�����ġ) ��ŭ ����

	// ������ġ > �۾�����ġ
	// ������ġ - �۾�����ġ�� �� ���� ��
	if (s < e)
	{
		if ((e - s) % 5 < 3)
		{
			jumpCnt = (e - s) / 5;
			curPos += 5 * jumpCnt;
			jumpCnt += e - curPos;
		}
		else
		{
			jumpCnt = (e - s) / 5 + 1;
			curPos += 5 * jumpCnt;
			jumpCnt += curPos - e;
		}

		cout << jumpCnt << '\n';
	}
	else if (s > e)
	{
		cout << s - e << '\n';
	}

	return 0;
}
// �ٽ�
// BFS�� �ð��ʰ����� ���� ��Ģ ã�Ƽ� Ǯ����

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <fstream>
//using namespace std;
//
//// �۾��� ã��
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	//ifstream cin;
//	//cin.open("input.txt");
//
//	int s, e; // S, E
//	cin >> s >> e;
//
//	vector<int> pos(10000); // ���� ��ǥ�� �����ϴ� ���� �� ����
//	int jumpCnt = 0; // ���� ��
//	queue<int> checkPos; // üũ�� ��ġ
//	vector<int> move; // �̵� : ��1 ��1 ��5
//	move.push_back(1);
//	move.push_back(-1);
//	move.push_back(5);
//
//	// ó�� ��ġ ����
//	checkPos.push(s);
//	pos[checkPos.front()] = 0;
//
//	while (checkPos.back() != e) // �۾��� ��ġ�� ������ ����
//	{
//		// ���� ��ġ ������
//		int curPos = checkPos.front();
//		checkPos.pop();
//		jumpCnt = pos[curPos] + 1; // ���� ��ġ�� ���� �� + 1
//
//		// ��1 ��1 ��5 üũ
//		for (int i = 0; i < 3; i++)
//		{
//			int nextPos = curPos + move[i]; // ���� ��ġ ���ϱ�
//
//			// ���üũ
//			if (nextPos < 1 || nextPos > 10000)
//			{
//				continue;
//			}
//
//			// ���� �� ����
//			pos[nextPos] = jumpCnt;
//
//			// ť�� �߰�
//			checkPos.push(nextPos);
//		}
//	}
//
//	cout << pos[e] << '\n';
//
//	return 0;
//}
//// �ٽ�
//// BFS�� ������ �ִܰŸ��� �����