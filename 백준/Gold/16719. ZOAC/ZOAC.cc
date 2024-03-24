#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

string originalString; // 원본문자열 STARTLINK
vector<bool> vis(100); // 방문체크
string displayString; // 보여 줄 문자열

// DFS
// 최근 선택한 문자를 기준으로 오른쪽에 있는 문자들 중 사전순으로 가장 앞서는 문자를 추가해야함
void DFS(int latestPos, int rightPos)
{
	if (latestPos > rightPos) // 종료조건 : 더 이상 최근선택한 문자를 기준으로 선택 할 오른쪽 문자가 없는경우
	{
		return;
	}
	else
	{
		int selectedPos = latestPos; // 선택 할 문자

		// 최근 선택한 문자를 기준으로 오른쪽에 있는 문자들 중
		// 아직 방문하지않은 사전순으로 가장 앞서는 문자를 찾아 방문체크함
		for (int i = latestPos; i < rightPos + 1; i++)
		{
			if (!vis[i] && originalString[selectedPos] > originalString[i])
			{
				selectedPos = i;
			}
		}

		vis[selectedPos] = true;

		// 선택한 문자를 출력
		for (int i = 0; i < originalString.length(); i++)
		{
			if (vis[i])
			{
				cout << originalString[i];
			}
		}

		cout << '\n';

		// 최근 선택한 문자를 기준으로 오른쪽 영역 재귀호출
		DFS(selectedPos + 1, rightPos);

		// 더이상 오른쪽에 선택할문자가 없으면 왼쪽 영역 재귀호출
		DFS(latestPos, selectedPos - 1);
	}
}

// ZOAC
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	cin >> originalString;

	// DFS
	DFS(0, originalString.length() - 1);

	return 0;
}
