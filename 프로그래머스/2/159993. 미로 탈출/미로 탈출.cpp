#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<string> maps)
{
    int answer = 0;
    
    // 레버 먼저 당겨야 탈출이 가능함
    
    vector<vector<char> > graph(maps.size(), vector<char>(maps[0].size())); // 그래프
    vector<vector<char> > dis(maps.size(), vector<char>(maps[0].size())); // 거리
    queue<pair<int, int> > checkPos; // 체크 할 위치
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    // S O O O L 
    // X X X X O 
    // O O O O O 
    // O X X X X 
    // O O O O E 
    // 시작지점 큐에 넣고 거리1
    // 도착지점 및 레버지점 저장
    
    pair<int, int> endPos;
    pair<int, int> leverPos;
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].size(); j++)
        {
            graph[i][j] = maps[i][j];
            
            if(graph[i][j] == 'S')
            {
                checkPos.push({i, j});
                dis[i][j] = 1;
            }
            else if(graph[i][j] == 'E')
            {
                endPos = {i, j};
            }
            else if(graph[i][j] == 'L')
            {
                leverPos = {i, j};
            }
        }
    }
    
    // // 디버깅용
    // for(auto a : graph)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // 시작지점부터 BFS 돌려서 레버로가는 최단거리 구하고
    
    int minDis = 0; // 미로를 탈출하는 최단거리
    
    while(!checkPos.empty())
    {
        // 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();
        
        // 레버최단거리 찾았으면 큐 초기화하고 종료
        if(standardPos.first == leverPos.first && standardPos.second == leverPos.second)
        {
            while(!checkPos.empty())
            {
                checkPos.pop();
            }
            
            break;
        }
        
        // 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= maps.size() || checkJ >= maps[0].size())
			{
				continue;
			}

			// 벽체크
			if (graph[checkI][checkJ] == 'X')
			{
				continue;
			}

			// 방문체크(거리로)
			if (dis[checkI][checkJ] > 0)
			{
				continue;
			}

			// 큐에저장, 거리저장
			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
		}
    }
    
    // 레버 최단거리 없으면 레버 못 댕겨서 탈출 못 함
    // 최단거리가 저장되어있으면 minDis에 저장
    // 그리고 거리 초기화
    if(dis[leverPos.first][leverPos.second] == 0)
    {
        answer = -1;
        
        return answer;
    }
    
    minDis = dis[leverPos.first][leverPos.second];
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].size(); j++)
        {
            dis[i][j] = 0;
        }
    }
    
    // 레버지점부터 BFS 돌려서 도착로가는 최단거리 구하고
    
    checkPos.push(leverPos);
    dis[leverPos.first][leverPos.second] = 1;
    
    while(!checkPos.empty())
    {
        // 기준위치 꺼냄
		pair<int, int> standardPos = checkPos.front();
		checkPos.pop();
        
        // 도착최단거리 찾았으면 종료
        if(standardPos.first == endPos.first && standardPos.second == endPos.second)
        {
            break;
        }
        
        // 상하좌우
		for (int i = 0; i < 4; i++)
		{
			// 체크 할 위치
			int checkI = standardPos.first + checkDir[i].first;
			int checkJ = standardPos.second + checkDir[i].second;

			// 경계체크
			if (checkI < 0 || checkJ < 0 || checkI >= maps.size() || checkJ >= maps[0].size())
			{
				continue;
			}

			// 벽체크
			if (graph[checkI][checkJ] == 'X')
			{
				continue;
			}

			// 방문체크(거리로)
			if (dis[checkI][checkJ] > 0)
			{
				continue;
			}

			// 큐에저장, 거리저장
			checkPos.push({ checkI, checkJ });
			dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
		}
    }
    
    // 도착점 최단거리 없으면 도착점까지 못 가므로 탈출 못 함
    // 최단거리가 저장되어있으면 minDis에 저장
    if(dis[endPos.first][endPos.second] == 0)
    {
        answer = -1;
        
        return answer;
    }
    
    minDis += dis[endPos.first][endPos.second];
    
    // 두 BFS 모두 시작할때 거리를 1로 했으므로 2를 빼줌
    answer = minDis - 2;
    
    return answer;
}