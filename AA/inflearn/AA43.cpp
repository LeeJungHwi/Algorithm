#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// ��������
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");
	//freopen("input.txt", "rt", stdin);

	int n, m; // N, M
	//cin >> n >> m;
	scanf_s("%d %d", &n, &m);

	int minute; // ���� ����
	vector<int> minutes(n); // ���� ���� ����

	int first = 0; // ó��
	int last = 0; // ������

	for (int i = 0; i < n; i++)
	{
		//cin >> minute;
		scanf_s("%d", &minute);
		minutes[i] = minute; // 6 5 8 5 6 8 7 6 6 7

		last += minute; // 64
	}

	//sort(minutes.begin(), minutes.end()); // 5 5 6 6 6 6 7 7 8 8

	first = minutes[0]; // 5

	// DVD �뷮 ������ 5 ~ 64
	// DVD �ּ� �뷮 ���ϱ�
	// first		avg				last
	// 5			34	O			64
	// 5			19	X			33
	// 20			26	O			33
	// 20			22  X			25
	// 23			24	O			25
	// 23			23  O			23
	// 23			>				22 -> first�� last�� �����ǹǷ� ����
	// DVD �ּ� �뷮 : 23

	int least = (first + last) / 2; // DVD �ּҿ뷮

	while (first <= last) // first�� last�� �����Ǹ� ����
	{
		int avg = (first + last) / 2; // DVD �뷮
		int dvdCnt = 0; // dvd ����
		int sumMinute = 0; // dvd ���� ��

		for (int i = 0; i < n; i++)
		{
			sumMinute += minutes[i]; // dvd ���� ���ϱ�

			if (sumMinute > avg) // dvd �뷮�� �ʰ��ϸ� ó��
			{
				sumMinute = minutes[i]; // �ʰ��� �ε����� ���̷� �ʱ�ȭ
				dvdCnt++;
			}

			if (dvdCnt == m) // dvd ������ m�� �ȼ��� m + 1��° dvd�� minutes[i]�� �����Ƿ� ������ �ʰ��� ���·� ����
			{
				break;
			}
		}

		if (sumMinute != 0) // ������ dvd
		{
			dvdCnt++;
		}

		if (dvdCnt <= m) // ������ �뷮
		{
			last = avg - 1; // ������ ����

			if (least > avg) // �ּұ��� ����
			{
				least = avg;
			}
		}
		else // �Ұ����� �뷮
		{
			first = avg + 1; // ó�� ����
		}
	}

	//cout << least << '\n';
	printf("%d\n", least);

	return 0;
}

// �ٽ�
// ���� ������ �ٲ��� ���ƾ��ϹǷ� ���� X -> ����Ž���� ���ĵȻ��¿����� ���밡���� �������� ������