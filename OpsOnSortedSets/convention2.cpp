#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MODA 998244353
#define pb push_back
#define sortv(v) sort(v.begin(), v.end())
#define sorta(A, N) sort(A, A + N)
#define debug(x) cerr << #x << " is " << x;
#define rep(i, a, N) for (ll i = a; i < N; i++)
#define f first
#define s second
#define uniq(v)                                       \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
void solve(ll tcase)
{
    ll n, ans = 0;
    cin >> n;
    set<array<ll, 3> > a, ind;
    rep(i, 0, n)
    {
        ll ai, ti;
        cin >> ai >> ti;
        a.insert({ai, i, ti});
        ind.insert({i, ai, ti});
    }
    bool waiting = false;

    ll curt = 0, cnt = 0;
    while (!a.empty())
    {
        if (!waiting)
        {
            auto cow = *a.begin();
            a.erase(a.begin());
            ind.erase(ind.find({cow[1], cow[0], cow[2]}));
            ans = max(ans, curt - cow[0]);
            curt = max(cow[0], curt) + cow[2];
            cnt = 0;
            if (!a.empty())
            {
                for (auto i : a)
                {
                    if (i[0] <= curt)
                        cnt++;
                    else
                        break;
                    if (cnt == 2)
                    {
                        waiting = true;
                        break;
                    }
                }
            }
        }
        else
        {
            auto cow = *ind.begin();
            ind.erase(ind.begin());
            a.erase(a.find({cow[1], cow[0], cow[2]}));
            ans = max(ans, curt - cow[1]);
            curt = max(cow[1], curt) + cow[2];
            cnt = 0;
            waiting = false;
            if (!a.empty())
            {
                for (auto i : a)
                {
                    if (i[0] <= curt)
                        cnt++;
                    else
                        break;
                    if (cnt == 2)
                    {
                        waiting = true;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}