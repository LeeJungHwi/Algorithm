#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park)
{
    int answer = 0;
    
    sort(mats.rbegin(), mats.rend());
    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[0].size(); j++)
        {
            if(park[i][j] != "-1") continue;
            
            for(int k = 0; k < mats.size(); k++)
            {
                if(answer >= mats[k]) continue;
                
                int s = mats[k];
                bool is = true;
                for(int l = i; l < i + s; l++)
                {
                    for(int p = j; p < j + s; p++)
                    {
                        if(l < 0 || l >= park.size() || p < 0 || p >= park[0].size() || park[l][p] != "-1")
                        {
                            is = false;
                            break;
                        }
                    }
                    
                    if(!is) break;
                }
                
                if(is) answer = s;
            }
        }
    }
    
    return answer = answer > 0 ? answer : -1;
}