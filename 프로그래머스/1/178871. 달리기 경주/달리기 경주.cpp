#include <string>
#include <map>
#include <vector>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    
    // players : 선수들의 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열
    // callings : 해설진이 부른 이름을 담은 문자열 배열
    // answer : 경주가 끝났을 때 선수들의 이름을 1등부터 등수 순서대로 배열
    
    // 해설진이 부른 선수는 자기 바로 앞 등수 선수와 등수가 바뀜
    // player 돌면서 (이름,등수) 저장
    // callings 돌면서 부른선수의 등수-1 값을 가지는 선수를 찾아 등수교체
    // 이름키를 돌면서 등수키에 저장
    // 등수키를 돌면서 answer에 저장
    
    map<string, int> nameKey; // 이름키
    map<int, string> orderKey; // 등수키
    
    // player 돌면서 (이름,등수) (등수,이름) 저장
    for(int i = 0; i < players.size(); i++)
    {
        nameKey[players[i]] = i;
        orderKey[i] = players[i];
    }
    
    // callings 돌면서 부른선수의 등수-1 값을 가지는 선수를 찾아 등수교체
    for(int i = 0; i < callings.size(); i++)
    {
        int playerOrder = nameKey[callings[i]]; // 추월한 선수 등수
        string changedPlayer = orderKey[playerOrder - 1]; // 추월당한 선수 이름
        
        // 등수교체
        nameKey[changedPlayer] = playerOrder;
        nameKey[callings[i]] = playerOrder - 1;
        orderKey[playerOrder] = changedPlayer;
        orderKey[playerOrder - 1] = callings[i];
    }
    
    // 이름키를 돌면서 등수키에 저장
    for(auto it = nameKey.begin(); it != nameKey.end(); it++)
    {
        orderKey[it->second] = it->first;
    }
    
    // 등수키를 돌면서 answer에 저장
    for(auto it = orderKey.begin(); it != orderKey.end(); it++)
    {
        answer.push_back(it->second);
    }
    
    return answer;
}