#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot)
{
    int temp = 0;
    for(int i = 0; i < dot.size(); i++) if(dot[i] < 0) temp++;
    switch(temp)
    {
        case 0 : return 1;
        case 1 : return dot[0] < 0 ? 2 : 4;
        case 2 : return 3;
    }
}