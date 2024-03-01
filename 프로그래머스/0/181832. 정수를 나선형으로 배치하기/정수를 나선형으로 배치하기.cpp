#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer(n, vector<int>(n)); // 그래프
    vector<vector<bool>> vis(n, vector<bool>(n)); // 방문체크
    queue<pair<int, int> > checkPos; // 체크 할 위치
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1,0});
    checkDir.push_back({1,0});
    checkDir.push_back({0,-1});
    checkDir.push_back({0,1});
    
    // 그래프 돌면서 
    // 오른쪽으로 가다가 경계를 만나거나 방문체크된 요소를 만나면 아래로
    // 아래쪽으로 가다가 경계를 만나거나 방문체크된 요소를 만나면 왼쪽으로
    // 왼쪽으로 가다가 경계를 만나거나 방문체크된 요소를 만나면 위쪽으로
    // 위쪽으로 가다가 경계를 만나거나 방문체크된 요소를 만나면 오른쪽으로
    
    int curDir = 3; // 현재 방향 오른쪽
        
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 그래프 돌면서 방문한곳 continue
            if(vis[i][j])
            {
                continue;
            }
            
            // (0, 0) 부터 진행
            checkPos.push({i, j});
            vis[i][j] = true;
            answer[i][j] = 1;
            
            while(!checkPos.empty()) // 큐가 빌때까지
            {
                // 기준위치 꺼냄
                pair<int, int> standardPos = checkPos.front();
                checkPos.pop();
                
                // 오른쪽으로 가다가 경계를 만나거나 방문체크된 요소를 만나면 아래로
                // 아래쪽으로 가다가 경계를 만나거나 방문체크된 요소를 만나면 왼쪽으로
                // 왼쪽으로 가다가 경계를 만나거나 방문체크된 요소를 만나면 위쪽으로
                // 위쪽으로 가다가 경계를 만나거나 방문체크된 요소를 만나면 오른쪽으로
                
                // 오른쪽으로 가다가
                if(curDir == 3)
                {
                    // 체크 할 위치
                    int checkJ = standardPos.second + checkDir[curDir].second;
                    
                    // 경계를 만나거나 방문체크된 요소를 만나면 아래로
                    if(checkJ >= n || vis[standardPos.first][checkJ])
                    {
                        curDir = 1;
                        
                        // 아래로 내려갈수있을때만 큐에저장 방문체크 요소저장
                        if(standardPos.first + 1 < n && !vis[standardPos.first + 1][standardPos.second])
                        {
                            checkPos.push({standardPos.first + 1, standardPos.second});
                            vis[standardPos.first + 1][standardPos.second] = true;
                            answer[standardPos.first + 1][standardPos.second] = answer[standardPos.first][standardPos.second] + 1;
                        }
                            
                        continue;
                    }
                    
                    // 큐에저장 방문체크 요소저장
                    checkPos.push({standardPos.first, checkJ});
                    vis[standardPos.first][checkJ] = true;
                    answer[standardPos.first][checkJ] = answer[standardPos.first][standardPos.second] + 1;
                }
                else if(curDir == 1) // 아래쪽으로 가다가
                {
                    // 체크 할 위치
                    int checkI = standardPos.first + checkDir[curDir].first;
                    
                    // 경계를 만나거나 방문체크된 요소를 만나면 왼쪽으로
                    if(checkI >= n || vis[checkI][standardPos.second])
                    {
                        curDir = 2;
                        
                        // 왼쪽으로 갈수있을때만 큐에저장 방문체크 요소저장
                        if(standardPos.second - 1 >= 0 && !vis[standardPos.first][standardPos.second - 1])
                        {
                            checkPos.push({standardPos.first, standardPos.second - 1});
                            vis[standardPos.first][standardPos.second - 1] = true;
                            answer[standardPos.first][standardPos.second - 1] = answer[standardPos.first][standardPos.second] + 1;
                        }
                            
                        continue;
                    }
                    
                    // 큐에저장 방문체크 요소저장
                    checkPos.push({checkI, standardPos.second});
                    vis[checkI][standardPos.second] = true;
                    answer[checkI][standardPos.second] = answer[standardPos.first][standardPos.second] + 1;
                }
                else if(curDir == 2) // 왼쪽으로 가다가 
                {
                    // 체크 할 위치
                    int checkJ = standardPos.second + checkDir[curDir].second;
                    
                    // 경계를 만나거나 방문체크된 요소를 만나면 위로
                    if(checkJ < 0 || vis[standardPos.first][checkJ])
                    {
                        curDir = 0;
                        
                        // 위로 올라갈수있을때만 큐에저장 방문체크 요소저장
                        if(standardPos.first - 1 >= 0 && !vis[standardPos.first - 1][standardPos.second])
                        {
                            checkPos.push({standardPos.first - 1, standardPos.second});
                            vis[standardPos.first - 1][standardPos.second] = true;
                            answer[standardPos.first - 1][standardPos.second] = answer[standardPos.first][standardPos.second] + 1;
                        }
                            
                        continue;
                    }
                    
                    // 큐에저장 방문체크 요소저장
                    checkPos.push({standardPos.first, checkJ});
                    vis[standardPos.first][checkJ] = true;
                    answer[standardPos.first][checkJ] = answer[standardPos.first][standardPos.second] + 1;
                }
                else if(curDir == 0) // 위쪽으로 가다가
                {
                    // 체크 할 위치
                    int checkI = standardPos.first + checkDir[curDir].first;
                    
                    // 경계를 만나거나 방문체크된 요소를 만나면 오른쪽으로
                    if(checkI < 0 || vis[checkI][standardPos.second])
                    {
                        curDir = 3;
                        
                        // 오른쪽으로 갈수있을때만 큐에저장 방문체크 요소저장
                        if(standardPos.second + 1 < n && !vis[standardPos.first][standardPos.second + 1])
                        {
                            checkPos.push({standardPos.first, standardPos.second + 1});
                            vis[standardPos.first][standardPos.second + 1] = true;
                            answer[standardPos.first][standardPos.second + 1] = answer[standardPos.first][standardPos.second] + 1;
                        }
                            
                        continue;
                    }
                    
                    // 큐에저장 방문체크 요소저장
                    checkPos.push({checkI, standardPos.second});
                    vis[checkI][standardPos.second] = true;
                    answer[checkI][standardPos.second] = answer[standardPos.first][standardPos.second] + 1;
                }
            }
        }
    }
    
    // // 디버깅용
    // for(auto a : answer)
    // {
    //     for(auto b : a)
    //     {
    //         cout << b << ' ';
    //     }
    //     cout << '\n';
    // }
    
    return answer;
}