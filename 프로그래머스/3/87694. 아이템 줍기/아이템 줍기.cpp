#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    
    // rectangle : 직사각형의 (좌하, 우상) 정보
    // characterX, characterY : 캐릭터 위치
    // itemX, itemY : 아이템 위치
    // answer : 아이템을 줍기위한 최소거리
    
    vector<vector<int> > graph(102, vector<int>(102)); // 그래프
    vector<vector<int> > dis(102, vector<int>(102)); // 거리
    queue<pair<int, int> > checkPos; // 체크 할 위치
    vector<pair<int, int> > checkDir; // 상하좌우
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    
    pair<int, int> leftDown; // 직사각형 좌하
    pair<int, int> rightUp; // 직사각형 우상
    map<pair<int, int>, int> innerMap; // 직사각형 내부위치 맵핑
    
    // 직사각형 좌표와 캐릭터, 아이템 위치를 두 배로 늘립니다.
    for(int i = 0; i < rectangle.size(); i++)
    {
        // 직사각형 크기를 2배로 키운 위치 가져와서
        leftDown = {rectangle[i][1] * 2, rectangle[i][0] * 2};
        rightUp = {rectangle[i][3] * 2, rectangle[i][2] * 2};
        
        // 직사각형 내부영역 맵핑
        for(int j = leftDown.first + 1; j < rightUp.first; j++)
        {
            for(int k = leftDown.second + 1; k < rightUp.second; k++)
            {
                innerMap[{j, k}]++;
            }
        }
        
        // 직사각형 채우기
        for(int j = leftDown.second; j < rightUp.second + 1; j++)
        {
            graph[leftDown.first][j] = 1;
            graph[rightUp.first][j] = 1;
        }
        
        for(int j = leftDown.first + 1; j < rightUp.first; j++)
        {
            graph[j][leftDown.second] = 1;
            graph[j][rightUp.second] = 1;
        }
    }
    
    // 디버깅용
    // for(int i = 1; i < 102; i++)
    // {
    //     for(int j = 1; j < 102; j++)
    //     {
    //         cout << graph[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // 캐릭터 위치부터 처음 갈수있는방향은 두방향임
    // 한쪽 방향을 설정했으면 다른쪽 방향은 방문체크해서 못가게해야함
    // 한쪽방향으로 진행(직사각형 영역 내부가 아닌방향으로 진행)
    // 아이템위치거리 - 1과 거리최대값 - 아이템위치거리 + 2 중 최솟값을 answer에 push
    
    pair<int, int> startPos = {characterY * 2, characterX * 2}; // 캐릭터 위치 6 2
    pair<int, int> itemPos = {itemY * 2, itemX * 2}; // 아이템 위치 16 14
    bool isFirst = false; // 처음방향 체크
    int preDir = 0; // 이전방향
    
    // 상하좌우 체크해서 처음만나는곳 방문체크하고 break
    for(int i = 0; i < 4; i++)
    {
        // 체크 할 위치
        int checkI = startPos.first + checkDir[i].first;
        int checkJ = startPos.second + checkDir[i].second;
        
        // 처음방향은 안갈거니까 거리 1로
        if(!isFirst && graph[checkI][checkJ] == 1)
        {
            isFirst = true;
            dis[checkI][checkJ] = 1;
        }
        // 다음방향은 갈거니까 이전방향 저장
        else if(isFirst && graph[checkI][checkJ] == 1)
        {
            preDir = i;
            
            break;
        }
    }
    
    // startPos부터 BFS
    // 한쪽방향으로 진행(직사각형 영역 내부가 아닌방향으로 진행)
    checkPos.push(startPos);
    dis[startPos.first][startPos.second] = 1;
    int maxDis = 1;
    
    while(!checkPos.empty()) // 큐가 빌때까지
    {
        // 기준위치 꺼냄
        pair<int, int> standardPos = checkPos.front();
        checkPos.pop();
        
        vector<tuple<int, int, int> > goPos; // (i, j, 방향) 저장
        
        // 상하좌우
        for(int i = 0; i < 4; i++)
        {
            // 체크 할 위치
            int checkI = standardPos.first + checkDir[i].first;
            int checkJ = standardPos.second + checkDir[i].second;
            
            // 경계체크
            if(checkI < 2 || checkJ < 2 || checkI >= 102 || checkJ >= 102)
            {
                continue;
            }
            
            // 방문체크
            if(dis[checkI][checkJ] > 0)
            {
                continue;
            }
            
            // 0체크
            if(graph[checkI][checkJ] == 0)
            {
                continue;
            }
            
            // 1인곳중에 영역내부체크
            if(innerMap[{checkI, checkJ}] > 0)
            {
                continue;
            }
            
            // 갈수있는 위치 저장
            goPos.push_back({checkI, checkJ, i});
        }
        
        // 갈수있는 위치가 한개면 그냥 가고
        if(goPos.size() == 1)
        {
            checkPos.push({get<0>(goPos[0]), get<1>(goPos[0])});
            dis[get<0>(goPos[0])][get<1>(goPos[0])] = dis[standardPos.first][standardPos.second] + 1;
            preDir = get<2>(goPos[0]);
            maxDis = dis[get<0>(goPos[0])][get<1>(goPos[0])];
        }
        // 갈수있는 위치가 두개면 같은방향으로 못감
        else
        {
            for(int i = 0; i < goPos.size(); i++)
            {
                if(get<2>(goPos[i]) != preDir)
                {
                    checkPos.push({get<0>(goPos[i]), get<1>(goPos[i])});
                    dis[get<0>(goPos[i])][get<1>(goPos[i])] = dis[standardPos.first][standardPos.second] + 1;
                    preDir = get<2>(goPos[i]);
                    maxDis = dis[get<0>(goPos[0])][get<1>(goPos[0])];
                    
                    break;
                }
            }
        }
    }
    
    //디버깅용
    // for(int i = 1; i < 102; i++)
    // {
    //     for(int j = 1; j < 102; j++)
    //     {
    //         cout << dis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // cout << maxDis;
    
    // 아이템위치거리 - 1과 거리최대값 - 아이템위치거리 + 2 중 최솟값을 answer에 push
    
    answer = min(dis[itemPos.first][itemPos.second] - 1, maxDis - dis[itemPos.first][itemPos.second] + 2);
    
    // 2배로 시작했으니 2로 나눠줌
    return answer / 2;
}
