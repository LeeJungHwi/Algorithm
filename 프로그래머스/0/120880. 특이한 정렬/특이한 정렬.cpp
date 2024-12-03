#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<int> numlist, int n)
{
    vector<int> answer;
    map<int, map<int, int> > m;
    for(int i = 0; i < numlist.size(); i++) m[abs(numlist[i] - n)][numlist[i]]++;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        for(auto it2 = it->second.rbegin(); it2 != it->second.rend(); it2++)
        {
            answer.push_back(it2->first);
        }
    }
    return answer;
}