#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    // nums : 포켓몬의 종류 번호
    
    int cnt = nums.size() / 2;
    map<int, int> pkMap;
    for(int i = 0; i < nums.size(); i++) pkMap[nums[i]]++;
    answer = pkMap.size() > cnt ? cnt : pkMap.size();
    
    return answer;
}