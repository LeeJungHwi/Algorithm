#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

int n; // N 2

// 언더바 출력하는 함수
void PrintUnderBar(int curN)
{
	for (int i = 0; i < curN * 4; i++)
	{
		cout << "_";
	}
}

// 재귀함수에 대한 답을 들을때까지 반복하는 함수
void AnswerRecursive(int curN)
{
	if (curN == n) // 현재크기가 n이면 재귀함수에 대한 답을 출력하고 종료
	{
		// ________재귀함수가 뭔가요?
		PrintUnderBar(curN);
		cout << "\"재귀함수가 뭔가요?\"" << '\n';

		// ________재귀함수는 자기 자신을 호출하는 함수라네
		PrintUnderBar(curN);
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << '\n';

		// ________라고 답변하였지.
		PrintUnderBar(curN);
		cout << "라고 답변하였지." << '\n';

		return;
	}
	else
	{
		// ____재귀함수가 뭔가요?
		PrintUnderBar(curN);
		cout << "\"재귀함수가 뭔가요?\"" << '\n';

		// ____잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.
		// ____마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.
		// ____그의 답은 대부분 옳았다고 하네.그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.
		PrintUnderBar(curN);
		cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << '\n';

		PrintUnderBar(curN);
		cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << '\n';

		PrintUnderBar(curN);
		cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << '\n';

		// 재귀
		AnswerRecursive(curN + 1);

		// ____라고 답변하였지.
		PrintUnderBar(curN);
		cout << "라고 답변하였지." << '\n';
	}
}

// 재귀함수가 뭔가요?
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> n;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';

	AnswerRecursive(0);

	return 0;
}