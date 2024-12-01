#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int a, int b, int c, int d)
{
    map<int, int> m;
    m[a]++; m[b]++; m[c]++; m[d]++;
    // 1 1 1 1 => 1111 * 1 => m 1
    // 1 1 1 2 => (10 * 1 + 2)^2 => m 2
    // 1 1 2 2 => (p + q) * abs(p - q) => m 2
    // 1 1 2 3 => 2 * 3 => m 3
    // 1 2 3 4 => min => m 4
    map<int, int>::iterator it = m.begin();
    int p = it->first;
    it++;
    int q = it->first;
    int temp1 = 1, temp2 = 2147000000;
    switch(m.size())
    {
        case 1: return 1111 * a;
        case 2:
            if(m.begin()->second == 2) return (p + q) * abs(p - q);
            return it->second == 1 ? pow((10 * p + q), 2) : pow((10 * q + p), 2);
        case 3:
            for(auto it = m.begin(); it != m.end(); it++) if(it->second == 1) temp1 *= it->first;
            return temp1;
        case 4:
            for(auto it = m.begin(); it != m.end(); it++) temp2 = min(temp2, it->first);
            return temp2;
    }
}