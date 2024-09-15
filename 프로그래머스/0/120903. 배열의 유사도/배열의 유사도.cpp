#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> s1, vector<string> s2)
{
    int answer = 0;
    map<string, int> m;
    for(int i = 0; i < s1.size(); i++) m[s1[i]]++;
    for(int i = 0; i < s2.size(); i++) if(m[s2[i]] > 0) answer++;
    return answer;
}