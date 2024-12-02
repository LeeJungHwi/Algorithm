#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int cnt = 0;
    while(true) if(pow(2, cnt++) >= arr.size()) break;
    cnt = pow(2, --cnt) - arr.size();
    for(int i = 0; i < cnt; i++) arr.push_back(0);
    return arr;
}