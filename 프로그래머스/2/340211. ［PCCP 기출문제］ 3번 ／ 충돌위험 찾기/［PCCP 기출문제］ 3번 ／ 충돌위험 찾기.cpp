#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    // 각 위치에 도착하는 시간들을 저장한 해시 유지
    // 모든 루트를 돌면서 각 루트에 대해 각 위치에 도착하는 시간 기록
    // 이동할 때 열 먼저 이동한 후 행 이동
    // 겹치는 상황 개수 => 각 위치의 맵을 돌면서 값이 2 이상인 경우 카운팅
    
    vector<vector<map<int, int>>> dis(101, vector<map<int, int>>(101));
    for(int i = 0; i < routes.size(); i++)
    {
        // 시작 번호
        int sp = routes[i][0];
        int si = points[sp - 1][0];
        int sj = points[sp - 1][1];
        int sd = 1;
        dis[si][sj][sd]++;
        
        for(int j = 1; j < routes[i].size(); j++)
        {
            // 현재 도착 번호
            int ep = routes[i][j];
            int ei = points[ep - 1][0];
            int ej = points[ep - 1][1];
            
            // 열 이동
            // si - ei > 0 => 상
            // si - ei < 0 => 하
            // si - ei == 0 => 이동 X
            if(si - ei > 0)
            {
                int cnt = si - ei;
                for(int k = 0; k < cnt; k++)
                {
                    dis[--si][sj][++sd]++;
                }
            }
            else if(si - ei < 0)
            {
                int cnt = ei - si;
                for(int k = 0; k < cnt; k++)
                {
                    dis[++si][sj][++sd]++;
                }
            }
            
            // 행 이동
            // sj - ej > 0 => 좌
            // sj - ej < 0 => 우
            // sj - ej == 0 => 이동X
            if(sj - ej > 0)
            {
                int cnt = sj - ej;
                for(int k = 0; k < cnt; k++)
                {
                    dis[si][--sj][++sd]++;
                }
            }
            else if(sj - ej < 0)
            {
                int cnt = ej - sj;
                for(int k = 0; k < cnt; k++)
                {
                    dis[si][++sj][++sd]++;
                }
            }
        }
    }
    
    // 겹치는 시간 카운팅
    int answer = 0;
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            for(auto it = dis[i][j].begin(); it != dis[i][j].end(); it++)
            {
                // 겹치지 않으면 X
                if(it->second < 2) continue;
                
                answer++;
            }
        }
    }
    
    return answer;
}