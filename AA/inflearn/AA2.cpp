#include <iostream>
using namespace std;

// �ڿ��� ��
int main()
{
	int a, b; // A, B
	int result = 0; // result
	
	cin >> a >> b;

	for (int i = a; i < b; i++) // A~B-1 ����
	{
		cout << i << "+ ";
		result += i;
	}

	result += b; // B

	cout << b << "=" << result << "\n";
	return 0;
}