#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

// ����ü �����층
struct LectureSort
{
	int m, d;

	LectureSort(int money, int day) // ������
	{
		m = money;
		d = day;
	}

	bool operator<(LectureSort &lectureSort) // ���ı��� : ������ ���̳��� ������ ���� -> ������ �� �������� ù �� ���� ������ �����층 �ϱ�����
	{
		return d > lectureSort.d;
	}
};

// �ִ� ���� ������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	int m, d; // m, d
	int maxD = 0; // ������ �����ϴ� ������ ��

	vector<LectureSort> lectureSort; // ���� ����
	priority_queue<int> schedule; // �����층 ����
	int pushCnt = 0; // ������ ť�� ���� Ƚ��
	int income = 0; // ����

	//	50 2
	//	20 1
	//	40 2
	//	60 3
	//	30 3
	//	30 1
	// maxD = 3
	for (int i = 0; i < n; i++)
	{
		cin >> m >> d;

		lectureSort.push_back(LectureSort(m, d));

		if (maxD < d)
		{
			maxD = d;
		}
	}

	// 60 3
	// 30 3
	// 50 2
	// 40 2
	// 20 1
	// 30 1
	sort(lectureSort.begin(), lectureSort.end());

	
	for (int i = maxD; i > 0; i--) // ����° ���� �Ҽ��ִ� ���� -> �ι�° ���� �Ҽ��ִ� ���� -> ù ���� �Ҽ��ִ� ����
	{
		for (int j = pushCnt; j < n; j++) // ���� �߿�
		{
			if (lectureSort[j].d < i) // ���� ��¥���� �۴ٸ� �����Ҽ�����
			{
				break;
			}

			// ť�� �߰�
			schedule.push(lectureSort[j].m);
			pushCnt++;
		}

		// ����1 : maxHeap�� 60, 30�� ����ǰ� �ִ밪 ���� -> ������ 60 ����� ť�� 30 ����
		// ����2 : maxHeap�� 50, 40�� ����ǰ� �ִ밪 ���� -> ������ 50 ����� ť�� 40 30 ����
		// ����3 : maxHeap�� 20, 30�� ����ǰ� �ִ밪 ���� -> ������ 40 ����� ť�� 30 20 ����
		if (!schedule.empty()) // maxHeap�� ��Ұ� �ִٸ� �����ϱ�
		{
			income += schedule.top();
			schedule.pop();
		}
	}

	cout << income << '\n';

	return 0;
}
// �ٽ�
// ����ü�� �̿��� ����
// ������ ���� ���� ���� ������ ����
// ������ �� �������� ù �� ���� ������ �����층