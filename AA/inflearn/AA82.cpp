#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// �������ϱ�
void GetSequence()
{

}

// �������ϱ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream cin;
	cin.open("input.txt");

	int n, r; // N, R

	int num; // ����

	vector<int> nums(n); // ���� ����

	int sequenceCnt = 0; // ���� ����

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		nums[i] = num;
	}



	return 0;
}