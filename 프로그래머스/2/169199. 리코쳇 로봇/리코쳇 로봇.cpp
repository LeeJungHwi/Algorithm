#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> board)
{
    int answer = 0;
    
    // 시작위치에서 목표위치까지 최단횟수 말하는 게임 도달할수없으면 -1 출력
    // 말은 상하좌우로 장애물이나 경계를 만날때까지 이동을 한번이동으로 간주함
    // board : .(빈공간) R(로봇 처음위치) D(장애물 위치) G(목표 위치)
    
    // 그래프 돌면서 R은 큐에 저장 거리 저장, G는 위치백업
    // R부터 BFS 돌리면서 한방향으로 쭉 가면서 거리 갱신
    
    vector<vector<int> > dis(board.size(), vector<int>(board[0].size())); // 거리
    queue<pair<int, int> > checkPos; // 체크 할 위치
    vector<pair<int, int> > checkDir; // 상하좌우
    pair<int, int> endPos; // 도착위치
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    // 그래프 돌면서 R은 큐에 저장 거리 저장, G는 위치백업
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == 'R')
            {
                checkPos.push({i, j});
                dis[i][j] = 1;
            }
            else if(board[i][j] == 'G')
            {
                endPos = {i, j};
            }
        }
    }
    
    // R부터 BFS 돌리면서 한방향으로 쭉 가면서 거리 갱신
    while(!checkPos.empty()) // 큐가 빌때까지
    {
        // 기준위치 꺼냄 
        pair<int, int> standardPos = checkPos.front();
        checkPos.pop();
        
        // 도착위치에 도착하면 최단거리 출력하고 종료
        if(standardPos.first == endPos.first && standardPos.second == endPos.second)
        {
            answer = dis[standardPos.first][standardPos.second] - 1;
            
            return answer;
        }
        
        // 상하좌우
        for(int i = 0; i < 4; i++)
        {
            // 우선 체크 할 위치에 기준위치 넣어둠
            int checkI = standardPos.first;
            int checkJ = standardPos.second;
            
            // 장애물 또는 경계를 만날때까지 한방향으로 쭉감
            while(true)
            {
                // 한방향으로 쭉가면서 
                checkI += checkDir[i].first;
                checkJ += checkDir[i].second;
                
                // 장애물 또는 경계를 만나면
                // 최단거리 갱신하고 종료
                if(checkI < 0 || checkJ < 0 || checkI >= board.size() || checkJ >= board[0].size() || board[checkI][checkJ] == 'D')
                {
                    // 다시 빼주고
                    checkI -= checkDir[i].first;
                    checkJ -= checkDir[i].second;
                    
                    // 처음 방문이면 그냥 저장
                    if(dis[checkI][checkJ] == 0)
                    {
                        // 큐에 저장 거리 갱신
                        checkPos.push({checkI, checkJ});
                        dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
                    }
                    else // 이미 방문이면 최단거리만 저장
                    {
                        if(dis[checkI][checkJ] > dis[standardPos.first][standardPos.second] + 1)
                        {
                            checkPos.push({checkI, checkJ});
                            dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
                        }
                    }
                    
                    break;
                }
            }
        }
    }
    
    // BFS 끝나고도 도달하지못하면 -1 출력
    answer = -1;
    
    return answer;
}