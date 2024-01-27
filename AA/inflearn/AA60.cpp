#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ���� ���� �κ����� ���ϱ�
void SameSumSubSet(int eleIndex, vector<int> &elements, vector<bool> &isEle, bool &exist)
{
	if (eleIndex == elements.size()) // �������� : �ε��� �Ѿ�� ����
	{
		int existSum = 0; // �����ϴ� ����� ��
		int notExistSum = 0; // �������� �ʴ¿���� ��

		for (int i = 0; i < elements.size(); i++) // �κ����� �հ� ������ ������ �� ���ϱ�
		{
			if (isEle[i])
			{
				existSum += elements[i];
			}
			else
			{
				notExistSum += elements[i];
			}
		}

		// �κ����� �� üũ : ���� �������� üũ, ���� ���Ұ� �ߺ����� �ʾƾ���
		if (existSum == notExistSum)
		{
			exist = true;
			return;
		}
	}
	else
	{
		isEle[eleIndex] = true; // ��� ����
		SameSumSubSet(eleIndex + 1, elements, isEle, exist);
		isEle[eleIndex] = false; // ��� ������
		SameSumSubSet(eleIndex + 1, elements, isEle, exist);
	}
}

// ���� ���� �κ�����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> elements(n); // ���� ���� ����
	vector<bool> isEle(n); // ��Ұ� �κ����տ� �ִ��� üũ
	bool isExist = false; // ���� ���� ������ �����ϴ��� üũ

	for (int i = 0; i < n; i++)
	{
		cin >> elements[i];
	}

	SameSumSubSet(0, elements, isEle, isExist);

	if (isExist)
	{
		cout << "YES" << '\n';
		return 0;
	}

	cout << "NO" << '\n';

	return 0;
}
// �ٽ�
// �ߺ��Ǵ� ���Ұ� �������