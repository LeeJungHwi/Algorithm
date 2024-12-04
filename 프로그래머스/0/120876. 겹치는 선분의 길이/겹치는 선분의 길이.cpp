#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines)
{
    int answer = 0;
    for(int i = 0; i < lines.size(); i++)
    {
        if(lines[i][0] > lines[i][1]) swap(lines[i][0], lines[i][1]);
    }
    
    vector<int> lineCoverage(201, 0);
    
    for(int i = 0; i < lines.size(); i++)
    {
        for(int j = lines[i][0] + 100; j < lines[i][1] + 100; j++) lineCoverage[j]++;
    }
    
    for (int i = 0; i < 201; i++)
    {
        if(lineCoverage[i] > 1) answer++;
    }

    return answer;
}