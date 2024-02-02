#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
using namespace std;

// 심바가 움직이는 상태 저장
struct State
{
	int x, y, dis; // x좌표, y좌표, 거리

	State(int curX, int curY, int curDis) // 생성자
	{
		x = curX;
		y = curY;
		dis = curDis;
	}
	
	bool operator<(const State &state) const // 정렬 기준 : 1.거리가 가까운 토끼 2. 위쪽에있는 토끼 3. 왼쪽에 있는 토끼 
	{
		if (dis != state.dis)
		{
			return dis > state.dis;
		}

		if (x != state.x)
		{
			return x > state.x;
		}

		return y > state.y;
	}
};

// 심바
struct Simba
{
	int x, y, s, ate; // x좌표, y좌표, 크기, 먹은횟수

	// 심바 크기 증가
	void sizeUp()
	{
		ate = 0;
		s++;
	}
};

// 라이언 킹 심바
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//ifstream cin;
	//cin.open("input.txt");

	int n; // N, 3
	cin >> n;

	Simba simba; // 심바
	priority_queue<State> Q; // 우선순위가 높은 토끼부터 먹음

	vector<vector<int> > graph(25, vector<int>(25)); // 그래프
	vector<vector<int> > vis(25, vector<int>(25)); // 방문체크
	vector<pair<int, int> > checkDir; // 상 하 좌 우
	checkDir.push_back({ -1, 0 });
	checkDir.push_back({ 1, 0 });
	checkDir.push_back({ 0, -1 });
	checkDir.push_back({ 0, 1 });

	int goSka = 0; // 심바가 스카삼촌에게 복수하러가는데 걸리는 시간

	//	0 1 3
	//	1 9 1
	//	0 1 1
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> graph[i][j];

			// 심바 위치
			if (graph[i][j] == 9)
			{
				simba.x = i;
				simba.y = j;
				graph[i][j] = 0;
			}
		}
	}

	// 처음 심바 위치 우선순위 큐에 저장
	Q.push(State(simba.x, simba.y, 0));
	simba.s = 2;
	simba.ate = 0;

	// BFS
	while (!Q.empty()) // 큐가 빌때까지
	{
		// 우선순위에 맞게 이동할 위치 꺼냄
		State state = Q.top();
		Q.pop();

		int curX = state.x;
		int curY = state.y;
		int curDis = state.dis;

		if (graph[curX][curY] != 0 && graph[curX][curY] < simba.s) // 이동할 위치가 빈칸이 아니면서 심바의 크기가 더 클때
		{
			// 이동 후 토끼를 먹음
			simba.x = curX;
			simba.y = curY;
			simba.ate++;

			// 심바의 크기 횟수만큼 토끼를 먹었을때 심바 사이즈 증가
			if (simba.ate >= simba.s)
			{
				simba.sizeUp();
			}

			// 먹혀진 토끼는 빈칸으로
			graph[curX][curY] = 0;

			// 방문체크 초기화 -> 잡아먹은 위치부터 다시 BFS 돌리기위해
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					vis[i][j] = 0;
				}
			}

			// 우선순위 큐 초기화
			while (!Q.empty())
			{
				Q.pop();
			}

			// 현재까지 심바가 움직인 거리 저장
			goSka = state.dis;
		}

		// 상 하 좌 우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 좌표
			int checkX = curX + checkDir[i].first;
			int checkY = curY + checkDir[i].second;

			// 경계체크
			if (checkX < 1 || checkX > n || checkY < 1 || checkY > n)
			{
				continue;
			}

			// 사이즈 체크
			if (graph[checkX][checkY] > simba.s)
			{
				continue;
			}

			// 방문 체크
			if (vis[checkX][checkY] > 0)
			{
				continue;
			}

			Q.push(State(checkX, checkY, curDis + 1)); // 큐에 저장
			vis[checkX][checkY] = 1; // 방문체크
		}
	}

	cout << goSka << '\n';
	return 0;
}
