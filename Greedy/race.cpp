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
ll needed(ll curspeed, ll X)
{
    if (curspeed <= X)
        return 0;
    ll res = curspeed * (curspeed - 1) - X * (X - 1);
    res /= 2;
    return res;
}
void solve(ll tcase)
{
    ll k, n;
    cin >> k >> n;
    ll x[n];
    rep(i, 0, n) cin >> x[i];
    rep(i, 0, n)
    {
        ll X = x[i];
        ll curspeed = 0, t = 0, covered = 0;
        while (true)
        {
            covered += curspeed;
            if (covered >= k)
                break;
            if (k - covered - needed(curspeed + 1, X) >= curspeed + 1)
                curspeed++;
            else if (k - covered - needed(curspeed, X) >= curspeed)
                curspeed *= 1;
            else
                curspeed--;
            t++;
        }
        cout << t << "\n";
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
#endif
    speed;
    ll t = 1;
    rep(i, 1, t + 1)
        solve(i);
}