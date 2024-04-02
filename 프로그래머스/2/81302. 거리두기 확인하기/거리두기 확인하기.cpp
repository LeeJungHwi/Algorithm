#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    
    // 대기실은 5개이며 각 대기실의 크기는 5 by 5
    // 거리두기를 위해 응시자들끼리 맨헤튼거리가 2보다 크게 앉아야함(맨헤튼거리는 |i1 - i2| + |j1 - j2|)
    // 단 응시자가 앉아있는 자리 사이가 파티션으로 막혀있을 경우 맨헤튼거리가 2 이하일때도 앉아도됨
    
    // places : 자리에앉아있는 응시자들의 정보와 대기실구조를 대기실별로 담은 2차원 문자열 배열, P(앉은자리) O(빈자리) X(파티션)
    // answer : 각 대기실별 거리두기를 지키고있으면 1 아니면 0을 저장
    
    // P 기준 BFS 돌려서 거리저장
    // 상2칸 하2칸 좌2칸 우2칸 좌상1칸 우상1칸 좌하1칸 우하1칸을 체크해서
    // P이면서 거리가 0이 아니면서 2이하면 answer에 0 저장
    // 그래프가 끝날때까지 종료가안되면 answer에 1 저장
    
    vector<vector<int> > dis(5, vector<int>(5)); // 거리
    queue<pair<int, int> > checkPos; // 체크 할 위치
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    
    // 대기실 개수만큼 돌면서
    for(int i = 0; i < 5; i++)
    {
        bool isPlace = true; // 거리두기를 지키는 대기실인지 체크
        
        // 그래프 돌면서
        for(int j = 0; j < 5; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                // P를 만나면 
                if(places[i][j][k] == 'P')
                {
                    // P 기준 BFS 돌려서 거리저장
                    checkPos.push({j, k});
                    dis[j][k] = 1;
                    
                    while(!checkPos.empty()) // 큐가 빌때까지
                    {
                        // 기준위치
                        pair<int, int> standardPos = checkPos.front();
                        checkPos.pop();
                        
                        // 상하좌우
                        for(int l = 0; l < 4; l++)
                        {
                            // 체크 할 위치
                            int checkI = standardPos.first + checkDir[l].first;
                            int checkJ = standardPos.second + checkDir[l].second;
                            
                            // 경계체크
                            if(checkI < 0 || checkJ < 0 || checkI >= 5 || checkJ >= 5)
                            {
                                continue;
                            }
                            
                            // 방문체크
                            if(dis[checkI][checkJ] > 0)
                            {
                                continue;
                            }
                            
                            // 파티션체크
                            if(places[i][checkI][checkJ] == 'X')
                            {
                                continue;
                            }
                            
                            // 큐에저장 거리저장
                            checkPos.push({checkI, checkJ});
                            dis[checkI][checkJ] = dis[standardPos.first][standardPos.second] + 1;
                        }
                    }
                    
                    // 그래프 돌면서
                    for(int l = 0; l < 5; l++)
                    {
                        for(int m = 0; m < 5; m++)
                        {
                            // P를 만나면
                            if(places[i][l][m] == 'P')
                            {
                                // 1부터 시작했으니 거리가 3이하면서 시작위치가 아니면
                                // 거리두기 안 지키는 대기실
                                if(dis[l][m] <= 3 && dis[l][m] > 1)
                                {
                                    answer.push_back(0);
                                    isPlace = false;
                                    break;
                                }
                            }
                        }
                        
                        // 거리두기 안 지키는 대기실
                        if(!isPlace)
                        {
                            break;
                        }
                    }
                    
                    // 큐 초기화
                    while(!checkPos.empty())
                    {
                        checkPos.pop();
                    }
                    
                    // 거리 초기화
                    for(int l = 0; l < 5; l++)
                    {
                        for(int m = 0; m < 5; m++)
                        {
                            dis[l][m] = 0;
                        }
                    }
                    
                    // 거리두기 안 지키는 대기실
                    if(!isPlace)
                    {
                        break;
                    }
                }
            }
            
            // 거리두기 안 지키는 대기실
            if(!isPlace)
            {
                break;
            }
        }

        // 거리두기를 지킨 대기실이면 1 추가
        if(isPlace)
        {
            answer.push_back(1);
        }
    }
    
    return answer;
}