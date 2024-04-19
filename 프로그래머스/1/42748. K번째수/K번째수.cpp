#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    
    // array : 숫자
    // commands : i~j까지 잘라 정렬했을때 k 번째 수
    // answer : commands에 따른 k 번째 수 저장
    
    // 1.commands 돌면서 array를 각 i-1 ~ j-1 자르고 정렬함
    // 2.k-1번째 수를 answer에 저장
    
    for(int i = 0; i < commands.size(); i++)
    {
        vector<int> temp;
        
        for(int j = commands[i][0] - 1; j < commands[i][1]; j++)
        {
            temp.push_back(array[j]);
        }
        
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2] - 1]);
    }
    
    return answer;
}