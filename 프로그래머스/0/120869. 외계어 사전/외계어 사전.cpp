#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> spell, vector<string> dic)
{
    int answer = 0;
    map<char, int> sMap;
    for(int i = 0; i < spell.size(); i++) sMap[spell[i][0]]++;
    for(int i = 0; i < dic.size(); i++)
    {
        map<char, int> dMap;
        for(int j = 0; j < dic[i].size(); j++)
        {
            dMap[dic[i][j]]++;
        }
        
        if(sMap == dMap) return 1;
    }
    return 2;
}