#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> heights(101); // Ű ����
int cntAngry; // �г������� ��
bool isAngry; // �г������� üũ

// �г������� �� ���ϱ�
void CountAngry(vector<int> &heights, int n)
{
	for (int i = 0; i < n - 1; i++) // ������ �л��� ������ �л�����ŭ ���鼭
	{
		isAngry = true;

		for (int j = i + 1; j < n; j++) // i��° �л� ���� ���ڸ��� ���� ������ �г�������
		{
			if (heights[i] <= heights[j]) // �Ѹ��̶� �� ������ �г������� �ƴ�, Ű�������� �� ������
			{
				isAngry = false;
				break;
			}
		}

		if (isAngry)
		{
			cntAngry++;
		}
	}
}

// �г�������
int main()
{
	ios_base::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	int height;// Ű
	cin >> n;

	// Ű ����
	for (int i = 0; i < n; i++)
	{
		cin >> height;
		heights[i] = height;
	}

	// �г������� ���ϱ�
	CountAngry(heights, n);

	cout << cntAngry << '\n';

	return 0;
}

// �ٽ�
// ���� ũ�� �Ҵ� �� �ε����� ����, �� �Ҵ� �� push_back