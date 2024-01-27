#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

// 기차운행
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N
	cin >> n;

	vector<int> trainOrder(n); // 기차 순서
	int curArrive = 1; // 현재 도착해야하는 기차 번호
	stack<int> crossRoad; // 교차로
	queue<char> processOrder; // 작업 순서
	
	// 기차 번호 순서대로 도착하게하기
	// push하면 큐에 P 저장 pop하면 큐에 O 저장
	// 현재 도착해야하는 기차번호까지 push
	// 현재 도착해야하는 기차번호 pop
	// 스택 탑과 현재도착해야하는 기차번호를 체크하면서 pop 또는 종료
	// 스택에 기차가 남아있다면 불가능하므로 impossible 출력
	// 스택이 비어있다면 도착가능하므로 큐 출력
	for (int i = 0; i < n; i++)
	{
		cin >> trainOrder[i]; // 2 1 3
	}

	for (int i = 0; i < n; i++)
	{
		if (trainOrder[i] != curArrive) // 현재 도착해야하는 기차번호 전까지 push
		{
			crossRoad.push(trainOrder[i]);
			processOrder.push('P');
		}
		else // 현재 도착해야하는 기차번호라면
		{
			// 현재 도착해야하는 기차 push
			crossRoad.push(trainOrder[i]);
			processOrder.push('P');

			// 현재 도착해야하는 기차 pop
			crossRoad.pop();
			processOrder.push('O');
			curArrive++;

			// 스택의 탑이 현재 도착해야하는 기차번호가 아닐때까지 pop
			while(!crossRoad.empty())
			{
				if(crossRoad.top() == curArrive)
				{
					crossRoad.pop();
					processOrder.push('O');
					curArrive++;
				}
				else // 현재 도착해야하는 기차번호가 아니면 종료
				{
					break;
				}
			}
		}
	}

	if (!crossRoad.empty()) // 스택에 기차가 남아있다면 불가능
	{
		cout << "impossible";
	}
	else // 스택이 비어있다면 도착가능
	{
		while (!processOrder.empty())
		{
			cout << processOrder.front();
			processOrder.pop();
		}
	}

	return 0;
}
// 핵심
// 큐 push : 큐 뒤에 요소 저장
// 큐 pop : 큐 앞 요소 삭제