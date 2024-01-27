#include <iostream>
#include <stack>
#include <fstream>
using namespace std;

// 1���� n���� ����ϴ� �Լ�
// printOneToN(n)
// printOneToN(n - 1)
// printOneToN(n - 2)
// ....
// printOneToN(1)
// 1
// 2
// ....
// n
void PrintOneToN(int n)
{
	if (n == 1)
	{
		cout << 1 << ' ';
	}
	else
	{
		PrintOneToN(n - 1);
		cout << n << ' ';
	}
}

// ����Լ� �м�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	PrintOneToN(n);

	return 0;
}
// �ٽ�
// �Լ� ȣ�⽺�� üũ