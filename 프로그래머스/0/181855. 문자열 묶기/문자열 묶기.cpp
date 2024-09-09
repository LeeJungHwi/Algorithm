#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> strArr)
{
    map<int, int> m;
    int answer = 0;
    for(int i = 0; i < strArr.size(); i++) answer = max(answer, ++m[strArr[i].size()]);
    return answer;
}