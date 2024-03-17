#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    
    // participant : 마라톤에 참여한 선수들의 이름 배열
    // completion : 완주 성공한 선수들의 이름 배열
    // answer : 완주하지못한 한명의 선수 이름
    
    // participant 돌면서 카운팅
    // completion 돌면서 카운팅
    // pm 돌면서 cm과 값이 다른선수를 answer에 저장
    
    map<string, int> pm;
    map<string, int> cm;
    
    for(int i = 0; i < participant.size(); i++)
    {
        pm[participant[i]]++;
    }
    
    for(int i = 0; i < completion.size(); i++)
    {
        cm[completion[i]]++;
    }
    
    for(auto it = pm.begin(); it != pm.end(); it++)
    {
        if(it->second != cm[it->first])
        {
            answer = it->first;
            
            break;
        }
    }
    
    return answer;
}