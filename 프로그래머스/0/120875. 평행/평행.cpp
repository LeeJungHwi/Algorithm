#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots)
{
    // 두 선분의 기울기가 같으면 평행
    for(int i = 1; i < 4; i++)
    {
        double t1 = 0, t2 = 0;
        
        if(i == 1)
        {
            // 01 23
            t1 = (double)abs(dots[0][0] - dots[1][0]) / (double)abs(dots[0][1] - dots[1][1]);
            t2 = (double)abs(dots[2][0] - dots[3][0]) / (double)abs(dots[2][1] - dots[3][1]);
        }
        else if(i == 2)
        {
            // 02 13
            t1 = (double)abs(dots[0][0] - dots[2][0]) / (double)abs(dots[0][1] - dots[2][1]);
            t2 = (double)abs(dots[1][0] - dots[3][0]) / (double)abs(dots[1][1] - dots[3][1]);
        }
        else
        {
            // 03 12
            t1 = (double)abs(dots[0][0] - dots[3][0]) / (double)abs(dots[0][1] - dots[3][1]);
            t2 = (double)abs(dots[1][0] - dots[2][0]) / (double)abs(dots[1][1] - dots[2][1]);
        }
        
        if(t1 == t2) return 1;
    }
    
    return 0;
}