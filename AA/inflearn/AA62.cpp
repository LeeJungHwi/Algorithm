#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// ����
void Merge(vector<int> &nums, int first, int standard, int last)
{
	int i = first; // ù��° �迭 ù �ε���
	int j = standard + 1; // �ι�° �迭 ù �ε���
	int k = 0; // �ӽú��� �ε���

	vector<int> tempNums(last - first + 1); // �ӽú���

	// �� �迭 ũ�� �� �� ����
	while (i <= standard && j <= last)
	{
		if (nums[i] <= nums[j])
		{
			tempNums[k++] = nums[i++];
		}
		else
		{
			tempNums[k++] = nums[j++];
		}
	}

	// ���� ��� ����
	while (i <= standard)
	{
		tempNums[k++] = nums[i++];
	}
	while (j <= last)
	{
		tempNums[k++] = nums[j++];
	}

	// �ӽú��Ͱ� �������� ����
	for (int l = first; l < last + 1; l++)
	{
		nums[l] = tempNums[l - first];
	}
}

// ��������
void MergeSort(vector<int> &nums, int first, int last)
{
	if (first < last) // first�� last�� �������� �ʾƾ���
	{
		// ����
		int standard = (first + last) / 2;

		// ����
		MergeSort(nums, first, standard);
		MergeSort(nums, standard + 1, last);

		// �պ�
		Merge(nums, first, standard, last);
	}
}

// ��������
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> nums(n); // �ڿ��� ����

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	// ��������
	MergeSort(nums, 0, n - 1);

	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << ' ';
	}

	return 0;
}