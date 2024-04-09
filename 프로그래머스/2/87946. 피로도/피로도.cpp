#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dungeonCnt; // 던전 개수
vector<vector<int>> orderDungeon; // 던전 탐험 순서
vector<bool> vis(8); // 방문체크
int maxDungeonCnt = 0; // 유저가 탐험할수있는 최대 던전 수

// DFS
void DFS(int L, vector<vector<int>> &dungeon, int initPirodo)
{
	if (L == dungeonCnt) // 종료조건 : 던전개수가 되면 종료
    {
        // 디버깅용
		// for (int i = 0; i < dungeonCnt; i++)
		// {
		// 	cout << orderDungeon[i][0] << ' ';
		// }
        // cout << '\n';
        
        // 선택한 순서대로 탐험했을때 최대던전수 갱신
        
        int curPirodo = initPirodo; // 80
        int dunCnt = 0; // 탐험한 던전수
        
        for(int i = 0; i < dungeonCnt; i++)
        {
            // 최소 필요 피로도를 체크해서 현재 피로도가 이상이 아니면 break
            if(curPirodo < orderDungeon[i][0])
            {
                break;
            }
            
            // 현재 피로도에서 소모 피로도를 감소
            curPirodo -= orderDungeon[i][1];
            
            // 탐험한 던전수 카운팅
            dunCnt++;
        }
    
        // 탐험한 최대 던전 수 갱신
        maxDungeonCnt = max(maxDungeonCnt, dunCnt);
	}
	else
	{
        // 던전 탐험 순서 선택
		for (int i = 0; i < dungeonCnt; i++)
		{
			if (!vis[i])
			{
				vis[i] = true; // 선택
				orderDungeon.push_back(dungeon[i]);
				DFS(L + 1, dungeon, initPirodo);
				orderDungeon.pop_back();
				vis[i] = false; // 미선택
			}
		}
	}
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;
    
    // k : 현재 피로도
    // dungeons : (최소필요피로도, 감소하는피로도)
    // answer : 유저가 탐험할수있는 최대 던전 수
    
    // DFS 돌면서
    // 던전 탐험 순서 선택
    // 선택한 순서대로 탐험했을때 최대던전수 갱신
    
    // DFS
    dungeonCnt = dungeons.size();
    DFS(0, dungeons, k);
    answer = maxDungeonCnt;
    
    return answer;
}