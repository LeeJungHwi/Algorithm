#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    
    // 최고 => 0이 모두 당첨번호 => 알고있는 번호 중 당첨번호 개수 + 0 개수
    // 최저 => 0이 모두 당첨번호가 아닌경우 => 알고있는 번호 중 당첨번호 개수
    map<int, int> m;
    for(int i = 0; i < win_nums.size(); i++) m[win_nums[i]]++;
    int knownCnt = 0, zeroCnt = 0;
    for(int i = 0; i < lottos.size(); i++)
    {
        if(m[lottos[i]] > 0) knownCnt++;
        if(lottos[i] == 0) zeroCnt++;
    }
    
    // 당첨개수에 해당하는 순위
    map<int, int> m2 = {{6, 1}, {5, 2}, {4, 3}, {3, 4}, {2, 5}, {1, 6}, {0, 6}};
    
    answer.push_back(m2[knownCnt + zeroCnt]);
    answer.push_back(m2[knownCnt]);
    
    return answer;
}