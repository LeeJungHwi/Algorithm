#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const char &c1, const char &c2)
{
    return c1 > c2;
}

long long solution(long long n)
{
    long long answer = 0;
    
    string temp = to_string(n);
    vector<char> order;
    for(int i = 0; i < temp.size(); i++) order.push_back(temp[i]);
    temp.clear();
    sort(order.begin(), order.end(), comp);
    for(int i = 0; i < order.size(); i++) temp += order[i];
    return answer = stoll(temp);
}