#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const pair<int, pair<double, double> > &p1, const pair<int, pair<double, double> > &p2)
{
    double p1Rate = (p1.second.first == 0) ? 0.0 : p1.second.second / p1.second.first;
    double p2Rate = (p2.second.first == 0) ? 0.0 : p2.second.second / p2.second.first;
    
    if(p1Rate != p2Rate) return p1Rate > p2Rate;
    return p1.first < p2.first;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    
    vector<pair<int, pair<double, double> > > clear(N + 1);
    for(int i = 1; i < N + 1; i++) clear[i].first = i;
    for(int i = 0; i < stages.size(); i++)
    {
        if(stages[i] < N + 1)
        {
            clear[stages[i]].second.first++;
            clear[stages[i]].second.second++;
        }
        
        for(int j = 1; j < stages[i]; j++)
        {
            clear[j].second.first++;
        }
    }
    
    sort(clear.begin(), clear.end(), comp);
    
    for(int i = 0; i < N + 1; i++)
    {
        cout << clear[i].second.second / clear[i].second.first << ' ';
        cout << clear[i].first << ' ' << clear[i].second.first << ' ' << clear[i].second.second << '\n';
        if(clear[i].first > 0) answer.push_back(clear[i].first);
    }
    
    
    return answer;
}