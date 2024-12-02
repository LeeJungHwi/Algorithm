#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    for(int i = 0; i < arr.size(); i++)
    {
        if(answer.empty() || answer.back() != arr[i]) answer.push_back(arr[i]);
        else answer.pop_back();
    }
    if(answer.empty()) answer.push_back(-1);
    return answer;
}