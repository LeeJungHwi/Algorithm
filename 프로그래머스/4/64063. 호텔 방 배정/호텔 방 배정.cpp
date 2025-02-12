#include <string>
#include <vector>
#include <unordered_map>
#define ll long long

using namespace std;

unordered_map<ll, ll> unf;

ll Find(ll v)
{
    if(unf.find(v) == unf.end()) return unf[v] = v + 1;
    return unf[v] = Find(unf[v]);
}

vector<long long> solution(ll k, vector<ll> room_number)
{
    vector<ll> answer;
    
    for(int i = 0; i < room_number.size(); i++) answer.push_back(Find(room_number[i]) - 1);
    
    return answer;
}