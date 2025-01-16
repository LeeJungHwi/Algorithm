#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots)
{
    int w = dots[0][0], h = dots[0][1];
    
    for(int i = 1; i < dots.size(); i++)
    {
        if(dots[i][0] != w)
        {
            w = abs(w - dots[i][0]);
            break;
        }
    }

    for(int i = 1; i < dots.size(); i++)
    {
        if(dots[i][1] != h)
        {
            h = abs(h - dots[i][1]);
            break;
        }
    }
    
    return w * h;
}