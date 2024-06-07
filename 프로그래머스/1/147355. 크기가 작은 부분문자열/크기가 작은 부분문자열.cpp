#include <string>
#include <vector>
using namespace std;

int home;
#define loop(s, e) for(int i = s; i < e; i++)
#define cond(c, t, f) ((c) ? (t) : (f))

int solution(string t, string p)
{
    loop(0, t.size() - p.size() + 1) home += cond(stoll(t.substr(i, p.size())) <= stoll(p), 1, 0);
    
    return home;
}