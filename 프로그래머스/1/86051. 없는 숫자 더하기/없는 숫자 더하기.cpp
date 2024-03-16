#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = -1;
    
    // numbers : 0~9 사이 정수가 들어가있는 배열
    // numbers에서 찾을수없는 0~9까지의 숫자를 모두 찾아 더한수를 answer에 저장
    
    // numbers 돌면서 (숫자, 나왔는지) 맵핑
    // 0~9까지 돌면서 나오지않은숫자를 더해서 answer에 저장
    
    // numbers 돌면서 (숫자, 나왔는지) 맵핑
    map<int, int> num;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        num[numbers[i]] = 1;
    }
    
    // 0~9까지 돌면서 나오지않은숫자를 더해서 answer에 저장
    int sum = 0;
    
    for(int i = 0; i < 10; i++)
    {
        if(num[i] == 0)
        {
            sum += i;
        }
    }
    
    if(sum != 0)
    {
        answer = sum;
    }
    
    return answer;
}