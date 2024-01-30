#include <iostream>
#include <vector>
using namespace std;

int sequence[10]; // ���� �迭
bool vis[10]; // �湮 üũ

int send() // SEND
{
	return sequence[6] * 1000 + sequence[1] * 100 + sequence[3] * 10 + sequence[0];
}

int more() // MORE
{
	return sequence[2] * 1000 + sequence[4] * 100 + sequence[5] * 10 + sequence[1];
}

int money() // MONEY
{
	return sequence[2] * 10000 + sequence[4] * 1000 + sequence[3] * 100 + sequence[1] * 10 + sequence[7];
}

void SendMoreMoney(int num)
{
	if (num == 8) // nums ������ ��������
	{
		if (send() + more() == money()) // SEND + MORE == MONEY üũ 
		{
			if (sequence[2] == 0 || sequence[6] == 0) // MS�� 0�̸� SEND�� MORE�� 4�ڸ����� �ȵǹǷ� ��� X
			{
				return;
			}

			cout << "  " << sequence[6] << " " << sequence[1] << " " << sequence[3] << " " << sequence[0] << '\n'; // SEND
			cout << "+ " << sequence[2] << " " << sequence[4] << " " << sequence[5] << " " << sequence[1] << '\n'; // MORE
			cout << "---------" << '\n';
			cout << sequence[2] << " " << sequence[4] << " " << sequence[3] << " " << sequence[1] << " " << sequence[7] << '\n'; // MONEY
		}
	}
	else
	{
		for (int i = 0; i < 10; i++) // 0~9 �����߿��� �̾Ƽ� ���� ����
		{
			if (!vis[i])
			{
				sequence[num] = i; // ���� �迭 �� �Ҵ�
				vis[i] = true; // �湮üũ
				SendMoreMoney(num + 1);
				vis[i] = false; // �湮����
			}
		}
	}
}

int main()
{
	SendMoreMoney(0);

	return 0;
}
// �ٽ�
// �����
/*
SEND + MORE = MONEY
nums �迭 : 0(D) 1(E) 2(M) 3(N) 4(O) 5(R) 6(S) 7(Y)
SEND = nums[6] * 1000 + nums[1] * 100 + nums[3] * 10 + nums[0]
MORE = nums[2] * 1000 + nums[4] * 100 + nums[5] * 10 + nums[1]
MONEY = nums[2] * 10000 + nums[4] * 1000 + nums[3] * 100 + nums[1] * 10 + nums[7]
*/
