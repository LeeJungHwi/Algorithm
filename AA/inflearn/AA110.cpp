#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ���� ����ü
struct Schedule
{
	int start;
	int end;
	int efficient;

	Schedule() : start(0), end(0), efficient(0) {}; // ������

	Schedule(int st, int et, int ef) // ������
	{
		start = st;
		end = et;
		efficient = ef;
	}

	bool operator<(const Schedule &schedule)const // ���۽ð� ��������
	{
		return start < schedule.start;
	}
};

// ȿ������ ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, m, r; // N, M, R 13, 5, 2
	cin >> n >> m >> r;

	vector<Schedule> schedules(m); // ���� ����ü ����
	vector<int> maxEfficients(m + 1); //  ���° ������ �������� �����ߴ����� ���� �ִ�ȿ���� ����

	//	3 5 20
	//	4 7 16
	//	1 2 5
	//	11 13 7
	//	9 10 6
	int st, et, ef; // ���۽ð� �����½ð� ȿ����

	for (int i = 0; i < m; i++)
	{
		cin >> st >> et >> ef;

		schedules[i] = Schedule(st, et + r, ef); // et�� �޽Ľð����� ���ؼ� �ʱ�ȭ
	}

	sort(schedules.begin(), schedules.end()); // (1 4 5) (3 7 20) (4 9 16) (9 12 6) (11 15 7)

	int result = 0; // �ִ�ȿ����

	for (int i = 0; i < m; i++) // i��° ������ ���������� ������
	{
		maxEfficients[i] = schedules[i].efficient;

		for (int j = i - 1; j > -1; j--)  // i��° ������ ���� �۾��� ���鼭
		{
			// ���� �۾��� ������ �ð����� i��° ������ ���۽ð��� ũ�ų� ���ƾ� �����Ҽ�����
			// ���� �۾��� �ִ�ȿ������ i��° ������ ȿ������ ���Ѱ��� ���� i��° ������ �ִ�ȿ�������� Ŀ�� �����Ҽ�����
			if (schedules[j].end <= schedules[i].start && maxEfficients[j] + schedules[i].efficient > maxEfficients[i])
			{
				maxEfficients[i] = maxEfficients[j] + schedules[i].efficient; // i��° ������ ���������� ���������� �ִ�ȿ���� ����
			}
		}

		// �ִ�ȿ���� ����
		if (result < maxEfficients[i])
		{
			result = maxEfficients[i];
		}
	}

	cout << result << '\n';

	return 0;
}
// �ٽ�
// DFS -> �ð��ʰ� -> DP�� �ذ�

//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <fstream>
//using namespace std;
//
//int n, m, r; // N, M, R 13, 5, 2
//vector<bool> vis(1001); // �湮üũ
//int maxEfficient; // �ִ� ȿ����
//
//// ���� ����ü
//struct Schedule
//{
//	int start;
//	int end;
//	int efficient;
//
//	Schedule() : start(0), end(0), efficient(0) {}; // ������
//
//	Schedule(int st, int et, int ef) // ������
//	{
//		start = st;
//		end = et;
//		efficient = ef;
//	}
//
//	bool operator<(const Schedule &schedule)const // ���۽ð� ��������
//	{
//		return start < schedule.start;
//	}
//};
//
//// DFS
//void DFS(int L, int et, vector<Schedule> &schedules)
//{
//	if (L == m) // �������� : ������ ������ �Ǹ� ����
//	{
//		int ef = 0; // ȿ����
//
//		for (int i = 0; i < m; i++) // ȿ���� ����
//		{
//			if (vis[i])
//			{
//				ef += schedules[i].efficient;
//			}
//		}
//
//		if (maxEfficient < ef) // �ִ�ȿ���� ����
//		{
//			maxEfficient = ef;
//		}
//	}
//	else
//	{
//		int st = schedules[L].start; // ���� ���۽ð�
//
//		if (st >= et) // �Ҽ��ִ� �����̸�
//		{
//			vis[L] = true; // �Ұ�
//			DFS(L + 1, schedules[L].end, schedules); // ������ ������ �����½ð�
//			vis[L] = false; // �� �Ұ�
//			DFS(L + 1, et, schedules); // �� ������ �Ѿ�� �����½ð�
//		}
//		else // �Ҽ����� �����̸�
//		{
//			DFS(L + 1, et, schedules); // ���ϹǷ� �Ѿ�� �����½ð�
//		}
//	}
//}
//
//// ȿ������ ����
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	ifstream cin;
//	cin.open("input.txt");
//
//	cin >> n >> m >> r;
//
//	vector<Schedule> schedules(m); // ���� ����ü ����
//
//	//	3 5 20
//	//	4 7 16
//	//	1 2 5
//	//	11 13 7
//	//	9 10 6
//	int st, et, ef; // ���۽ð� �����½ð� ȿ����
//
//	for (int i = 0; i < m; i++)
//	{
//		cin >> st >> et >> ef;
//
//		schedules[i] = Schedule(st, et + r, ef); // et�� �޽Ľð����� ���ؼ� �ʱ�ȭ
//	}
//
//	sort(schedules.begin(), schedules.end()); // (1 4 5) (3 7 20) (4 9 16) (9 12 6) (11 15 7)
//
//	// DFS
//	DFS(0, 0, schedules);
//
//	cout << maxEfficient << '\n';
//
//	return 0;
//}