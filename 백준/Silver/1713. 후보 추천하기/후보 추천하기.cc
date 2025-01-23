#include <bits/stdc++.h>
using namespace std;

#define home 0

#ifdef ONLINE_JUDGE
#define init ios_base::sync_with_stdio(home); cin.tie(home)
#else
#define init ios_base::sync_with_stdio(home); cin.tie(home); ifstream cin("input.txt")
#endif

#define ll long long
#define ld long double

#define pii pair<int, int>
#define pll pair<ll, ll>

#define loop(v, s, e) for(int v = (s); v < (e); v++)
#define rloop(v, s, e) for(int v = (s); v > (e); v--)
#define mloop(v, a) for(auto v = (a).begin(); v != (a).end(); v++)
#define mrloop(v, a) for(auto v = (a).rbegin(); v != (a).rend(); v++)

#define p(a) cout << (a)
#define elp(a) cout << (a) << '\n'
#define scp(a) cout << (a) << ' '

#define tvec(t, v) vector<t> v
#define vec(t, v, r) vector<t> v((r))
#define gmat(t, v, r) vector<vector<t> > v((r))
#define mat(t, v, r, c) vector<vector<t> > v((r), vector<t>((c)))

#define dir vector<pii> cd = { {-1, home}, {1, home}, { home, -1 }, { home, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } }
#define lhs first
#define rhs second

#define cond(c, t, f) ((c) ? (t) : (f))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX = 2147000000;
const int MIN = -2147000000;

struct Student
{
	int num;
	int cnt;
	int order;

    Student() {}
	Student(int n, int c, int o) : num(n), cnt(c), order(o) {}

	bool operator<(const Student& s)const
	{
		if(cnt != s.cnt) return cnt > s.cnt;
		return order > s.order;
	}
};

// 후보 추천하기
int main()
{
	init;

	int n, m; cin >> n >> m;
    priority_queue<Student> pq;
    map<int, Student> sMap;
    int num;
    loop(i, home, m)
    {
        cin >> num;

        // 이미 있는 학생
        if (sMap.count(num))
        {
            // 맵 추천 수 증가
            Student s = sMap[num];
            s.cnt++;
            sMap[num] = s;

            // 우선순위 큐 추천 수 증가
            priority_queue<Student> temp;
            while (!pq.empty())
            {
                Student s = pq.top();
                pq.pop();
                if (s.num == num) s.cnt++;
                temp.push(s);
            }

            pq = temp;
        }
        else // 사진틀에 없는 학생
        {
            // 사진틀 공간이 있을때
            if (pq.size() < n)
            {
                // 우선순위 큐 학생 추가
                pq.push(Student(num, 1, i));

                // 맵 학생 추가
                sMap[num] = Student(num, 1, i);
            }
            else // 사진틀 공간이 없을때
            {
                // 최소추천 오래된순서 삭제
                Student s = pq.top();
                pq.pop();
                sMap.erase(s.num);

                // 새 학생 추가
                Student newStudent(num, 1, i);
                pq.push(Student(num, 1, i));
                sMap[num] = Student(num, 1, i);
            }
        }
    }

    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().num);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    loop(i, home, ans.size()) scp(ans[i]);

	return home;
}