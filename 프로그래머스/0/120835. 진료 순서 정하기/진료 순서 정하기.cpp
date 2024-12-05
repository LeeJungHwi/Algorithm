#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> emergency)
{
    vector<int> answer(emergency.size());
    map<int, int> m;
    for(int i = 0; i < emergency.size(); i++) m[emergency[i]] = i + 1;
    // 76 2
    // 24 3
    // 3 1
    int cur = 1;
    for(auto it = m.rbegin(); it != m.rend(); it++) answer[it->second - 1] = cur++;
    return answer;
}