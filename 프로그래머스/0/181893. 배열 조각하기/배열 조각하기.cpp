#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query)
{
    vector<int> answer;
    deque<int> d;
    for(int i = 0; i < arr.size(); i++) d.push_back(arr[i]);
    bool isEven = true;
    for(int i = 0; i < query.size(); i++)
    {
        int dSize = d.size();
        if(isEven) for(int j = query[i] + 1; j < dSize; j++) d.pop_back();
        else for(int j = 0; j < query[i]; j++) d.pop_front();
        isEven = !isEven;
    }
    for(int i = 0; i < d.size(); i++) answer.push_back(d[i]);
    return answer;
}