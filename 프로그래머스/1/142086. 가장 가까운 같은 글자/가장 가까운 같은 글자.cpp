#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    
    map<char, int> charMap;
    
    for(int i = 0; i < s.size(); i++)
    {
        answer.push_back(!charMap[s[i]] ? -1 : i + 1 - charMap[s[i]]);
        charMap[s[i]] = i + 1;
    }
    
    return answer;
}