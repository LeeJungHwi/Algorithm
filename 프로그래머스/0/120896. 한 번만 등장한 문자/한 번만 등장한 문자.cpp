#include <string>
#include <map>
#include <vector>
using namespace std;

string solution(string s)
{
    string answer = "";
    
    // 문자열 하나씩 읽으면서 맵 ++
    // 값이 1인것만 answer에 저장
    
    map<char, int> m;
    
    for(int i = 0; i < s.size(); i++)
    {
        m[s[i]]++;
    }
    
    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(it->second == 1)
        {
            answer += it->first;
        }
    }
    
    return answer;
}