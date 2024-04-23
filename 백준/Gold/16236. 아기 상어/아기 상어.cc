#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
using namespace std;

// 아기상어가 움직이는 상태 저장
struct State
{
	// x, y, 거리
	int x, y, dis;

	// 생성자
	State() {}
	State(int curX, int curY, int curDis) : x(curX), y(curY), dis(curDis) {}

	// 정렬 기준 : 1.거리가 가까운 물고기 2. 위쪽에있는 물고기 3. 왼쪽에 있는 물고기
	bool operator<(const State &state) const
	{
		if (dis != state.dis) return dis > state.dis;
		if (x != state.x) return x > state.x;
		return y > state.y;
	}
};

// 아기상어
struct Shark
{
	// x, y, 크기, 먹은횟수
	int x, y, s, ate;

	// 아기상어 크기 증가
	void sizeUp()
	{
		ate = 0;
		s++;
	}
};

// 아기 상어
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N, 3
	cin >> n;

	Shark shark; // 아기상어
	vector<vector<int> > graph(n + 1, vector<int>(n + 1)); // 그래프
	vector<vector<bool> > vis(n + 1, vector<bool>(n + 1)); // 방문체크
	priority_queue<State> checkPos; // 체크 할 위치 => 우선순위가 높은 물고기부터 먹음
	vector<pair<int, int> > checkDir; // 상하좌우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	int helpMotherShark = 0; // 아기상어가 엄마상어에게 도움을 요청하는 시간

	//	0 0 0
	//	0 0 0
	//	0 9 0
	// 아기상어 위치 저장
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];

			// 아기상어 위치
			if (graph[i][j] == 9)
			{
				shark.x = i;
				shark.y = j;
				graph[i][j] = 0;
			}
		}
	}

	// 처음 아기상어 위치 우선순위 큐에 저장
	checkPos.push(State(shark.x, shark.y, 0));
	shark.s = 2;
	shark.ate = 0;

	// BFS
	while (!checkPos.empty()) // 큐가 빌때까지
	{
		// 우선순위에 맞게 이동할 위치 꺼냄
		State standardPos = checkPos.top();
		checkPos.pop();

		// 이동할 위치가 빈칸이 아니면서 아기상어의 크기가 더 클때
		if (graph[standardPos.x][standardPos.y] != 0 && graph[standardPos.x][standardPos.y] < shark.s)
		{
			// 이동 후 물고기를 먹음
			shark.x = standardPos.x;
			shark.y = standardPos.y;
			shark.ate++;

			// 아기상어의 크기 횟수만큼 물고기를 먹었을때 아기상어 사이즈 증가
			if (shark.ate >= shark.s) shark.sizeUp();

			// 먹혀진 물고기는 빈칸으로
			graph[standardPos.x][standardPos.y] = 0;

			// 방문체크 초기화 -> 잡아먹은 위치부터 다시 BFS 돌리기위해
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					vis[i][j] = false;
				}
			}

			// 우선순위 큐 초기화
			while (!checkPos.empty()) checkPos.pop();

			// 현재까지 아기상어가 움직인 거리 저장
			helpMotherShark = standardPos.dis;
		}

		// 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 좌표
			int checkX = standardPos.x + checkDir[i].first;
			int checkY = standardPos.y + checkDir[i].second;

			// 경계체크
			if (checkX < 1 || checkX > n || checkY < 1 || checkY > n) continue;

			// 사이즈 체크
			if (graph[checkX][checkY] > shark.s) continue;

			// 방문 체크
			if (vis[checkX][checkY]) continue;
			
			// 큐에 저장, 방문체크 
			checkPos.push(State(checkX, checkY, standardPos.dis + 1));
			vis[checkX][checkY] = true;
		}
	}

	cout << helpMotherShark << '\n';

	return 0;
}