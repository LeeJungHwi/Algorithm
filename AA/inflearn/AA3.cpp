#include <iostream>
using namespace std;

// ����� ��
int main()
{
	int n; // N
	int result = 1; // result
	
	cin >> n;

	cout << 1; // 1

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) // + 2 + 4 ...
		{
			cout << " + " << i;
			result += i;
		}
	}

	cout << " = " << result << "\n"; // = result
	return 0;
}

// �ٽ�
// ����� -> �ڱ��ڽ��� ������ ���
// " + "�� �տ� ����