#include <iostream>
using namespace std;

#define ll long long
#define loop(s, e) for(int i = s; i < e; i++)
#define cond(c, t, f) ((c) ? t : f)

ll home;

long long solution(int price, int money, int count)
{
    loop(0, count) home -= price * (i + 1);

    return home = cond((home + money) > -1, 0, abs(home + money));
}