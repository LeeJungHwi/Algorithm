#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �������ϱ�
void GetSequence(int num, vector<int> &nums, vector<bool> &vis, vector<int> &savePickNums, int pickCnt, int r, int n, int &seqCnt)
{
	if (pickCnt == r) // ���� ���� : r���� ���ڸ� ������ ����
	{
		for (int i = 0; i < r; i++)
		{
			cout << savePickNums[i] << ' '; // ���� ���� ���
		}

		cout << '\n';

		seqCnt++; // ���� ���� ����
	}
	else
	{
		for (int i = 0; i < n; i++) // n��ŭ ���鼭
		{
			if (!vis[i]) // �湮���� ���� ���
			{
				savePickNums[pickCnt] = nums[i]; // ���� ���� ����
				vis[i] = true; // �湮 üũ
				GetSequence(nums[i], nums, vis, savePickNums, pickCnt + 1, r, n, seqCnt);
				vis[i] = false; // �湮 ����
			}
		}
	}
}

// �������ϱ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n, r; // N, R 4, 3
	cin >> n >> r;

	int num; // ����

	vector<int> nums(n);          // ���� ����
	vector<int> savePickNums(r);  // ���� ���� ����
	vector<bool> vis(n);          // �湮 üũ
	int pickCnt = 0;              // ���ڸ� ���� Ƚ��
	int sequenceCnt = 0;          // ���� ����

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		nums[i] = num; // 1 3 6 7
	}

	GetSequence(nums[0], nums, vis, savePickNums, pickCnt, r, n, sequenceCnt);

	cout << sequenceCnt << '\n';

	return 0;
}
// �ٽ�
// ���� ���� ����