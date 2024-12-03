#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string before, string after)
{
    int answer = 0;
    map<char, int> m;
    for(int i = 0; i < before.size(); i++)
    {
        m[after[i]]++;
        m[before[i]]--;
    }
    for(auto it = m.begin(); it != m.end(); it++)
    {
        if(it->second != 0) return 0;
    }
    return 1;
}