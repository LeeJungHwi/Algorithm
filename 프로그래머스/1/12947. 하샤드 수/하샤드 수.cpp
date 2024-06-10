#include <string>
#include <vector>
using namespace std;

#define loop(s, e) for(int i = s; i < e; i++)
#define cond(c, t, f) ((c) ? (t) : (f))

bool home;
int posSum;

bool solution(int x)
{
    string temp = to_string(x);
    loop(0, temp.size()) posSum += temp[i] - '0';
    
    return home = cond(!(x % posSum), true, false);
}