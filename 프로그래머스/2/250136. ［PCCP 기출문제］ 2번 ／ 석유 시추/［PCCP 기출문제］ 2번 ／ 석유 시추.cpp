#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    unordered_map<int, int> oilMap; // (라벨, 영역 넓이)
    queue<pair<int, int> > checkPos;
    vector<pair<int, int> > checkDir;
    checkDir.push_back({-1, 0});
    checkDir.push_back({1, 0});
    checkDir.push_back({0, -1});
    checkDir.push_back({0, 1});
    int curLabel = 1; // 라벨 2 부터 시작
    
    // 0. BFS 돌면서 (라벨, 영역 넓이) 맵핑
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[0].size(); j++)
        {
            if(land[i][j] == 1)
            {
                int area = 1;
                checkPos.push({i, j});
                land[i][j] = ++curLabel;
                
                while(!checkPos.empty())
                {
                    pair<int, int> standardPos = checkPos.front();
                    checkPos.pop();
                    
                    for(int k = 0; k < 4; k++)
                    {
                        int checkI = standardPos.first + checkDir[k].first;
                        int checkJ = standardPos.second + checkDir[k].second;
                        
                        if(checkI < 0 || checkJ < 0 || checkI >= land.size() || checkJ >= land[0].size()) continue;
                        if(land[checkI][checkJ] != 1) continue;
                        
                        checkPos.push({checkI, checkJ});
                        land[checkI][checkJ] = curLabel;
                        area++;
                    }
                }
                
                oilMap[curLabel] = area;
            }
        }
    }
    
    //for(auto it = oilMap.begin(); it != oilMap.end(); it++) cout << it->second << ' ';
    
    // 1. 각 열을 시추 할 때 뽑을 수 있는 최대 석유량 갱신
    int maxOil = 0;
    for(int i = 0; i < land[0].size(); i++)
    {
        int oil = 0;
        set<int> oilSet;
        for(int j = 0; j < land.size(); j++)
        {
            if(land[j][i] == 0) continue;
            if(oilSet.find(land[j][i]) != oilSet.end()) continue;
            
            oilSet.insert(land[j][i]);
            oil += oilMap[land[j][i]];
        }
        maxOil = max(maxOil, oil);
    }
    
    return answer = maxOil;
}