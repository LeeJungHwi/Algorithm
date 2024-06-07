#include <bits/stdc++.h>
using namespace std;

#define loop(s, e) for(int i = s; i < e; i++)
#define cond(c, t, f) ((c) ? (t) : (f))

string home;

string solution(string phone_number)
{
    loop(0, phone_number.size()) home += cond(i < phone_number.size() - 4, '*', phone_number[i]);
    
    return home;
}