#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> babbling)
{
    int answer = 0;
    
    // 옹알이 맵핑
    map<string, int> babMap;
    babMap["aya"]++;
    babMap["ye"]++;
    babMap["woo"]++;
    babMap["ma"]++;
    
    for(int i = 0; i < babbling.size(); i++)
    {
        string temp = "";
        string pre = "";
        for(int j = 0; j < babbling[i].size(); j++)
        {
            temp += babbling[i][j];
            
            // 옹알이면서 이전 옹알이 아닌지 체크
            if(babMap[temp] > 0 && temp != pre)
            {
                pre = temp;
                temp.clear();
            }
        }
        
        if(temp.empty()) answer++;
    }
    
    return answer;
}