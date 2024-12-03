#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score)
{
    vector<int> answer(score.size());
    vector<pair<double, int>> avgs;
    
    for (int i = 0; i < score.size(); i++) avgs.push_back({(score[i][0] + score[i][1]) / 2.0, i});
    sort(avgs.rbegin(), avgs.rend());
    
    int cur = 1;
    for (int i = 0; i < avgs.size(); i++)
    {
        if (i > 0 && avgs[i].first == avgs[i - 1].first) answer[avgs[i].second] = cur;
        else
        {
            cur = i + 1;
            answer[avgs[i].second] = cur;
        }
    }

    return answer;
}