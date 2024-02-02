#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// ���� ����ü
struct Rock
{
	int area; // �س���
	int height; // ����
	int weight; // ����

	Rock() : area(0), height(0), weight(0) {} // ������

	Rock(int ar, int he, int we) // ������
	{
		area = ar;
		height = he;
		weight = we;
	}

	bool operator<(const Rock &rock)const // �س��� �������� ����
	{
		return area < rock.area;
	}
};

// ���� ���� ž �ױ�(LIS)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N 5
	cin >> n;

	vector<Rock> rocks(n + 1); // ���� ����
	vector<int> heights(n + 1); // �� ������ �������϶� ���� �ִ밪 ����

	int area; // �س���
	int height; // ����
	int weight; // ����

	for (int i = 1; i < n + 1; i++)
	{
		cin >> area >> height >> weight;

		rocks[i] = Rock(area, height, weight); // (25 3 4) (4 4 6) (9 2 3) (16 2 5) (1 5 2)
	}

	sort(rocks.begin(), rocks.end()); // (1 5 2) (4 4 6) (9 2 3) (16 2 5) (25 3 4)

	// (1 5 2)�� ���� �Ʒ� �����϶� : (1 5 2) -> ���� 5
	// (4 4 6)�� ���� �Ʒ� �����϶� : ���� ������ ���鼭 �ڽź��� ���԰� ������ �� �ִ���� + �ڽų��� ���� -> (4 4 6) (1 5 2) -> ���� 9
	// (9 2 3)�� ���� �Ʒ� �����϶� : ���� ������ ���鼭 �ڽź��� ���԰� ������ �� �ִ���� + �ڽų��� ���� -> (9 2 3) (1 5 2) -> ���� 7
	// (16 2 5)�� ���� �Ʒ� �����϶� : ���� ������ ���鼭 �ڽź��� ���԰� ������ �� �ִ���� + �ڽų��� ���� -> (16 2 5) (9 2 3) (1 5 2) -> ���� 9
	// (25 3 4)�� ���� �Ʒ� �����϶� : ���� ������ ���鼭 �ڽź��� ���԰� ������ �� �ִ���� + �ڽų��� ���� -> (25 3 4) (9 2 3) (1 5 2) -> ���� 10
	heights[1] = rocks[1].height;
	int result = 0; // �ִ� ���� ����

	for (int i = 2; i < n + 1; i++)
	{
		int maxHeight = 0;

		for (int j = i - 1; j > 0; j--) // ���� ������ ���鼭
		{
			// �ڽź��� ���԰� ������ �� �ִ����
			if (rocks[i].weight > rocks[j].weight)
			{
				if (maxHeight < heights[j])
				{
					maxHeight = heights[j];
				}
			}
		}

		// �ִ���� + �ڽų��� ����
		heights[i] = maxHeight + rocks[i].height;

		// �ִ� ���� ���� ����
		if (result < heights[i])
		{
			result = heights[i];
		}
	}

	cout << result << '\n';

	return 0;
}