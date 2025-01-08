#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill)
{
    int answer = 0;
    int wmin = min(wallet[0], wallet[1]);
    int wmax = max(wallet[0], wallet[1]);
    int bmin = min(bill[0], bill[1]);
    int bmax = max(bill[0], bill[1]);
    
    while(bmin > wmin || bmax > wmax)
    {
        if(bill[0] > bill[1]) bill[0] /= 2;
        else bill[1] /= 2;
        answer++;
        
        wmin = min(wallet[0], wallet[1]);
        wmax = max(wallet[0], wallet[1]);
        bmin = min(bill[0], bill[1]);
        bmax = max(bill[0], bill[1]);
    }
    
    return answer;
}