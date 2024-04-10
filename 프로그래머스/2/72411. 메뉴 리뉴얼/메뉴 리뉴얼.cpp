#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m; // (메뉴, 주문한 손님수) 맵핑

// DFS
void DFS(int L, string order, string comb = "")
{
    if(L == order.size()) // 종료조건 : 각 손님의 메뉴길이를 넘긴경우
    {
        // (메뉴, 주문한 손님수) 맵핑
        sort(comb.begin(), comb.end());
        m[comb]++;
    }
    else
    {
        DFS(L + 1, order, comb + order[L]); // 메뉴 선택
        DFS(L + 1, order, comb); // 메뉴 미선택
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    
    // 코스요리는 2명 이상의 손님으로부터 주문된 단품메뉴 2가지 이상으로 구성되어야함
    
    // orders : 각 손님들이 주문한 단품메뉴
    // course : 코스요리를 구성하는 단품메뉴들의 개수
    // answer : 추가할 메뉴들
    
    // orders 돌면서
    for(int i = 0; i < orders.size(); i++)
    {
        // DFS 돌려서 (메뉴, 주문한 손님수) 맵핑
        DFS(0, orders[i]);
    }
    
    // 맵 돌면서 course에 해당하는 개수면서
    // 2 명 이상의 손님으로부터 주문되었으면
    // 맵에 아직 없거나 주문한 손님수 이상일때 추가하다가 더 많으면 지금까지 추가한 메뉴 없애고 추가
    // (메뉴길이, 메뉴) 맵핑
    
    map<int, vector<pair<string, int>>> m2; // (메뉴길이, {메뉴,주문수}들) 맵핑
    
    // 맵 돌면서
    for(auto it = m.begin(); it != m.end(); it++)
    {
        for(int i = 0; i < course.size(); i++)
        {
            // course에 해당하는 개수면서 2 명 이상의 손님으로부터 주문되었으면
            if(it->first.size() == course[i] && it->second >= 2)
            {
                 // 맵에 아직 없거나 주문한 손님수 이상일때 추가하다가
                if(m2[it->first.size()].size() == 0 || m2[it->first.size()][0].second <= it->second)
                {
                    // 더 많으면 지금까지 추가한 메뉴 없애고 추가
                    if(m2[it->first.size()].size() != 0 && m2[it->first.size()][0].second < it->second)
                    {
                        m2[it->first.size()].clear();
                    }
                    
                    // 같으면 그냥 추가
                    m2[it->first.size()].push_back({it->first, it->second});
                    
                    break;
                }
            }
        }
    }
    
    // 맵 돌면서 answer에 push
    for(auto it = m2.begin(); it != m2.end(); it++)
    {
        for(int i = 0; i < it->second.size(); i++)
        {
            answer.push_back(it->second[i].first);
        }
    }
    
    // answer 오름차순 정렬
    sort(answer.begin(), answer.end());
    
    return answer;
}