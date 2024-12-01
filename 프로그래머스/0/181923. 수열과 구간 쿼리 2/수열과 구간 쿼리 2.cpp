#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    vector<int> answer;
    for(int i = 0; i < queries.size(); i++)
    {
        int min = 2147000000;
        for(int j = queries[i][0]; j < queries[i][1] + 1; j++) if(arr[j] > queries[i][2] && arr[j] < min) min = arr[j];
        answer.push_back(min == 2147000000 ? -1 : min);
    }
    return answer;
}