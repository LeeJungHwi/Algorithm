#include <iostream>
#include <vector>
using namespace std;

int sequence[10]; // 순열 배열
bool vis[10]; // 방문 체크

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
	if (num == 8) // nums 순열이 가득차면
	{
		if (send() + more() == money()) // SEND + MORE == MONEY 체크 
		{
			if (sequence[2] == 0 || sequence[6] == 0) // MS가 0이면 SEND와 MORE이 4자리수가 안되므로 출력 X
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
		for (int i = 0; i < 10; i++) // 0~9 숫자중에서 뽑아서 순열 생성
		{
			if (!vis[i])
			{
				sequence[num] = i; // 순열 배열 값 할당
				vis[i] = true; // 방문체크
				SendMoreMoney(num + 1);
				vis[i] = false; // 방문해제
			}
		}
	}
}

int main()
{
	SendMoreMoney(0);

	return 0;
}
// 핵심
// 복면산
/*
SEND + MORE = MONEY
nums 배열 : 0(D) 1(E) 2(M) 3(N) 4(O) 5(R) 6(S) 7(Y)
SEND = nums[6] * 1000 + nums[1] * 100 + nums[3] * 10 + nums[0]
MORE = nums[2] * 1000 + nums[4] * 100 + nums[5] * 10 + nums[1]
MONEY = nums[2] * 10000 + nums[4] * 1000 + nums[3] * 100 + nums[1] * 10 + nums[7]
*/
