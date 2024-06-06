#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int home;

int solution(vector<int> A, vector<int> B)
{
    // 1 2 4
    // 4 4 5
    deque<int> a, b;
    sort(A.begin(), A.end());
    for(auto num : A) a.push_back(num);
    sort(B.begin(), B.end());
    for(auto num : B) b.push_back(num);
    
    for(int i = 0; i < A.size(); i++)
    {
        if(a.back() <= b.back())
        {
            home += b.back() * a.front();
            b.pop_back();
            a.pop_front();
            
            continue;
        }
        
        home += b.front() * a.back();
        b.pop_front();
        a.pop_back();
    }
    
    return home;
}