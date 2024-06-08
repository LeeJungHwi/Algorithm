#include <string>
#include <vector>
using namespace std;

#define ll long long
#define loop(s, e) for(ll i = s; i < e; i++)

vector<ll> home;

vector<ll> solution(int x, int n)
{
    loop(0, n) home.push_back(x * (i + 1));
    
    return home;
}